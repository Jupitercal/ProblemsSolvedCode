#include<bits/stdc++.h>
#define N 20005
typedef long long LL;
int n,tou[N],dd,node[N*2],cnt,fa[N];
bool vis[N],b[N];
LL pre[N*2],sum,ans,F[N*2],last[N*2],g[N],f[N],siz[N*2];
struct aa{
	int p,next;
}da[N*3];
void add(int x,int y){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;
}
void dfs(int x){
	vis[x]=1;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (v==fa[x])continue;
		if (!vis[v]){
			fa[v]=x;
			dfs(v);
		}
		else{
			//printf("%d\n",x);
			for (int m=x;m!=v;m=fa[m])b[node[++cnt]=m]=1;
			b[node[++cnt]=v]=1;
		}
		if (cnt)break;
	}
}
void dfs1(int x,int father){
	siz[x]=1;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (b[v]||v==father)continue;
		dfs1(v,x);
		f[x]+=g[v];
		siz[x]+=siz[v];
	}
	g[x]=f[x]+siz[x];
}
void dfs2(int x,int fa,LL num){
	ans=std::max(ans,num+n+f[x]);
	//printf("node %d: %lld\n",x,num+n+f[x]);
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (v==fa||b[v])continue;
		dfs2(v,x,num+n-siz[v]-g[v]+f[x]);
	}
}
void solve(){
	for (int i=1;i<=cnt*2;i++)last[i]=siz[node[i]],pre[i]=pre[i-1]+last[i],sum+=f[node[i]];
	for (int i=2;i<cnt;i++){
		for (int l=1;l<=cnt*2-i+1;l++){
			int r=l+i-1;
			LL tmp=pre[r]-pre[l-1];
			F[l]=std::max(last[l],last[l+1])+tmp;
		}
		for (int l=1;l<=cnt*2-i+1;l++)last[l]=F[l];
	}
	ans=0;
	//printf("!\n");
	for (int i=1;i<=cnt;i++){
		ans=std::max(ans,F[i+1]+n+sum/2);
		//printf("node %d: %lld\n",node[i],F[i+1]+n+sum/2);
		for (int j=tou[node[i]];j;j=da[j].next){
			int v=da[j].p;
			if (!b[v]){
				dfs2(v,node[i],n-siz[v]-g[v]+F[i+1]+sum/2);
			}
		}
	}	
	printf("%lld\n",ans);
}
int main(){
	//#ifndef ONLINE_JUDGE
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	//#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		x++,y++;
		add(x,y);
		add(y,x);
	}
	dfs(1);
	//for (int i=1;i<=cnt;i++)printf("%d\n",node[i]);
	for (int i=1;i<=cnt;i++)dfs1(node[i],0);
	for (int i=1;i<=cnt;i++)node[cnt+i]=node[i];
	solve();
	return 0;
}