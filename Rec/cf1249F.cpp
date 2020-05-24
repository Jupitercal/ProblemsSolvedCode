#include<bits/stdc++.h>
#define N 205
#define uint unsigned int
typedef long long LL;
LL F[N][N],a[N];
int n,k;
std::vector<int>g[N];
void dfs(int x,int fa){
	for (uint i=0;i<g[x].size();i++){
		int v=g[x][i];
		if (v==fa)continue;
		dfs(v,x);
	}
	for (int dep=0;dep<=n;dep++){
		if (dep==0){
			F[x][dep]=a[x];
			for (uint i=0;i<g[x].size();i++){
				int v=g[x][i];
				if (v==fa)continue;
				F[x][dep]+=F[v][std::max(0,k-1)];
			}
		}
		else {
			for (uint i=0;i<g[x].size();i++){
				int v=g[x][i];
				if (v==fa)continue;
				LL cur=F[v][dep-1];
				for (uint j=0;j<g[x].size();j++){
					int vi=g[x][j];
					if (vi==v||vi==fa)continue;
					cur+=F[vi][std::max(dep-1,k-dep-1)];
				}
				F[x][dep]=std::max(F[x][dep],cur);
			}
		}
	}
	for (int dep=n-1;dep>=0;dep--)F[x][dep]=std::max(F[x][dep],F[x][dep+1]);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	#endif
	scanf("%d%d",&n,&k);
	k++;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	printf("%lld\n",F[1][0]);
	return 0;
}