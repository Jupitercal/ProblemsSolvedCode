#include<bits/stdc++.h>
#define N 50050
typedef long long LL;
using namespace std;
int n,k,root,wt[N],tsiz,siz[N],sta[N],tot;
bool vis[N];
LL ans,cnt[2000];
vector<int>vec[N];
void Dfs(int u,int status,int fa){
	cnt[status]++;
	for (int i=0;i<vec[u].size();i++){
		int v=vec[u][i];
		if (v==fa||vis[v])continue;
		Dfs(v,status|sta[v],u);
	}
}
void getroot(int u,int fa){
	siz[u]=1;wt[u]=0;
	for (int i=0;i<vec[u].size();i++){
		int v=vec[u][i];
		if (!vis[v]&&fa!=v){
			getroot(v,u);
			siz[u]+=siz[v];
			wt[u]=std::max(wt[u],siz[v]);
		}
	}
	wt[u]=std::max(wt[u],tsiz-siz[u]);
	if (wt[root]>wt[u])root=u;
}
LL calc(int u,int status){
	memset(cnt,0,sizeof(cnt));
	Dfs(u,sta[u],0);
	LL sum=0;
	for (int i=status;i;i = (i-1)&status){
		if (cnt[i]){
			for (int x = i;x;x=(x-1)&i){
				sum += cnt[i]*cnt[x^status];
			}
			sum +=cnt[i]*cnt[0^status];
		}
	}
	return sum;
}
void dfs(int u){
	//cnt=0;
	ans+=calc(u,tot);vis[u]=1;
	for (int i=0;i<vec[u].size();i++){
		int v=vec[u][i];
		if (!vis[v]){
			//cnt=0;
			ans-=calc(v,tot);
			ans-=calc(v,tot^sta[u]);
			tsiz=siz[v];
			root=0;
			getroot(v,0);
			dfs(root);
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	#endif
	while (scanf("%d%d",&n,&k)!=EOF){
		//if (n==0&&k==0)break;
		tot=1<<k;
		tot--;
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=n;i++){
			vec[i].clear();
			int x;
			scanf("%d",&x);
			sta[i]=1<<(x-1);
		}
		for (int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		if (k==1){
			printf("%lld\n",1LL*n*n);
			continue;
		}
		wt[0]=0x7f7f7f7f;
		tsiz=n;
		root=0;
		ans=0;
		getroot(1,0);
		dfs(root);
		printf("%lld\n",ans);
	}
	return 0;
}