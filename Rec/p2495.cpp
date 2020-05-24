#include<bits/stdc++.h>
typedef long long LL;
#define N 300000
struct aa{
	int p,next;
	LL len;
}da[N*2],db[N*2];
int n,stack[N],top,dfn[N],sz,to[N],dz,tou[N],dd,deep[N];
LL mu[N];
int fa[N][21],kpoi[N];
bool b[N];
bool cmp(int x,int y){
	return dfn[x]<dfn[y];
}
void add(int x,int y,int len){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].len=len;
}
void add1(int x,int y){
	db[++dz].p=y;db[dz].next=to[x];to[x]=dz;
}
void dfs(int x,int FA){
	dfn[x]=++sz;deep[x]=deep[FA]+1;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (v==FA)continue;
		fa[v][0]=x;
		mu[v]=std::min(mu[x],da[i].len);
		dfs(v,x);
	}
}
int LCA(int u,int v){
    if(deep[u]< deep[v]) std::swap(u,v);
    int delta = deep[u] - deep[v];
    for(int i = 19;i>= 0;--i){
        if((delta >> i) & 1) u = fa[u][i];
    }
    for(int i = 19;i>= 0;--i){
        if(fa[u][i] != fa[v][i]) u = fa[u][i],v = fa[v][i];
    }
    if(u == v) return u;
    return fa[u][0];
}
void insert(int x){
	if (top==1){ stack[++top]=x;return;}
	int lca=LCA(x,stack[top]);
	if (lca==stack[top]){stack[++top]=x;return;}
	while (top>1&&dfn[lca]<=dfn[stack[top-1]]){ 
		add1(stack[top-1],stack[top]);
		top--;
	}
	if (lca!=stack[top]){
		add1(lca,stack[top]);
		stack[top]=lca;
	}
	stack[++top]=x;
}
LL dfs1(int x){
	LL cost=0;
	for (int i=to[x];i;i=db[i].next){
		int v=db[i].p;
		cost+=std::min(mu[v],dfs1(v));
	}
	to[x]=0;
	if (b[x])return mu[x];
	else return cost;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		add(u,v,l);
		add(v,u,l);
	}
	memset(mu,0x3f3f3f3f,sizeof(mu));
	dfs(1,0);
	for (int t=1;t<=19;t++)
		for (int i=1;i<=n;i++)
			fa[i][t]=fa[fa[i][t-1]][t-1];
	int q;
	scanf("%d",&q);
	for (int i=1;i<=q;i++){
		int m;
		scanf("%d",&m);
		for (int j=1;j<=m;j++)scanf("%d",&kpoi[j]),b[kpoi[j]]=1;
		std::sort(kpoi+1,kpoi+1+m,cmp);
		top=1;
		//use[++use[0]]=1;
		//used[1]=1;
		stack[top]=1;
		for (int j=1;j<=m;j++)insert(kpoi[j]);
		while(top > 0) {
            add1(stack[top-1],stack[top]);
            top--;
        }
		printf("%lld\n",dfs1(1));
		for (int j=1;j<=m;j++)b[kpoi[j]]=0;
		dz=0;
	}
	return 0;
}