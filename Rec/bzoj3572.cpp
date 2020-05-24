#include<bits/stdc++.h>
#define N 330000
//std::vector<int>g1[N],g2[N];
int n,deep[N],fa[N][20],sz,dfn[N],size[N],remi[N];
int stack[N],top,a[N],b[N],bel[N],F[N],tou[N],dd,to[N],dz;
int c[N];
struct aa{
	int p,next;
}da[N*2],db[N*2];
bool cmp(int x,int y){
	return dfn[x]<dfn[y];
}
void add(int x,int y){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;
}
void add1(int x,int y){
	db[++dz].p=y;db[dz].next=to[x];to[x]=dz;
}
int LCA(int u,int v){
    if(deep[u]< deep[v]) std::swap(u,v);
    int delta = deep[u] - deep[v];
    for(int i = 18;i>= 0;--i){
        if((delta >> i) & 1) u = fa[u][i];
    }
    for(int i = 18;i>= 0;--i){
        if(fa[u][i] != fa[v][i]) u = fa[u][i],v = fa[v][i];
    }
    if(u == v) return u;
    return fa[u][0];
}
void insert(int x){	
	if (top<=1){ stack[++top]=x;return;}
	int lca=LCA(x,stack[top]);
	if (lca==stack[top]){stack[++top]=x;return;}
	while (top>1&&dfn[lca]<=dfn[stack[top-1]]){ 
		//g2[stack[top-1]].push_back(stack[top]);
		add1(stack[top-1],stack[top]);
		top--;
	}
	if (lca!=stack[top]){
		add1(lca,stack[top]);
		stack[top]=lca;
	}
	stack[++top]=x;
}
void dfs(int x,int FA){
	dfn[x]=++sz;deep[x]=deep[FA]+1;
	size[x]=1;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (v==FA)continue;
		fa[v][0]=x;
		//size[x]+=size[v];
		dfs(v,x);
		size[x]+=size[v];
	}
	//remi[x]=size[x];
}
int dist(int x,int y){
	return deep[x]+deep[y]-2*deep[LCA(x,y)];
}
void dfs1(int x){
	c[++sz]=x;remi[x]=size[x];
	for (int i=to[x];i;i=db[i].next){
		int v=db[i].p;
		dfs1(v);
		if (!bel[v])continue;
		int t1=dist(x,bel[x]);int t2=dist(x,bel[v]);
		if (t1>t2||(t1==t2&&bel[v]<bel[x])||!bel[x])bel[x]=bel[v];
	}
}
void dfs2(int x){
	for (int i=to[x];i;i=db[i].next){
		int v=db[i].p;
		int t1=dist(v,bel[x]);int t2=dist(v,bel[v]);
		if (t1<t2||(t1==t2&&bel[x]<bel[v])||!bel[v])bel[v]=bel[x];
		dfs2(v);
	}
}
void solve(int x,int y){
	int mx=y;int mid=y;
	for (int i=18;i>=0;i--)
		if (deep[fa[mx][i]]>deep[x])mx=fa[mx][i];
	//int nxt=y;
	remi[x]-=size[mx];
	if (bel[x]==bel[y]){F[bel[x]]+=size[mx]-size[y];return;}
	for (int i=18;i>=0;i--){
		int nxt=fa[mid][i];
		if (deep[nxt]<=deep[x])continue;
		int t1=dist(nxt,bel[x]);
		int t2=dist(nxt,bel[y]);
		if (t1>t2||(t1==t2&&bel[x]>bel[y]))mid=nxt;
	}
	F[bel[x]]+=size[mx]-size[mid];
	F[bel[y]]+=size[mid]-size[y];
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n-1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,1);
	for (int i=1;i<=18;i++)
		for (int j=1;j<=n;j++)fa[j][i]=fa[fa[j][i-1]][i-1];
	int q,m;
	//for (int i=1;i<=n;i++)printf("%d\n",size[i]);
	scanf("%d",&q);
	while (q--){
		sz=0;
		scanf("%d",&m);
		for (int i=1;i<=m;i++)scanf("%d",&a[i]),b[i]=a[i],bel[b[i]]=b[i];
		std::sort(b+1,b+m+1,cmp);
		top=0;
		if (bel[1]!=1)stack[++top]=1;
		//stack[top]=1;
		for (int i=1;i<=m;i++)insert(b[i]);
		while (top>0){
			//g2[stack[top-1]].push_back(stack[top]);
			add1(stack[top-1],stack[top]);
			top--;
		}
		dfs1(1);dfs2(1);
		//printf("%d\n",sz);
		for (int i=1;i<=sz;i++)
			for (int j=to[c[i]];j;j=db[j].next)solve(c[i],db[j].p);
		for (int i=1;i<=sz;i++)F[bel[c[i]]]+=remi[c[i]];
		for (int i=1;i<=m;i++)printf("%d ",F[a[i]]);
		printf("\n");
		for (int i=1;i<=sz;i++){
			F[c[i]]=remi[c[i]]=bel[c[i]]=0;
			to[c[i]]=0;
		}
		dz=0;
	}
	//printf("YES");
	return 0;
}