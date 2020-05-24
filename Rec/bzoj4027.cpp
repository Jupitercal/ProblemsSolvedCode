#include<bits/stdc++.h>
using namespace std;
#define N 2000005
vector<int> e[N];
int n,m,c[N],ans;
bool cmp(int x,int y){return c[x]<c[y];}
void dfs(int x){
	for (int i=0;i<e[x].size();i++)dfs(e[x][i]);
	sort(e[x].begin(),e[x].end(),cmp);
	c[x]+=e[x].size();
	for (int i=0;i<e[x].size();i++){
		if (c[x]+c[e[x][i]]-1<=m){
			c[x]+=c[e[x][i]]-1;
			ans++;
		}else break;
	}
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)scanf("%d",&c[i]);
	for (int i=0;i<n;i++){
		int x,y;
		scanf("%d",&x);
		for (int j=1;j<=x;j++){
			scanf("%d",&y);
			e[i].push_back(y);
		}
	}
	dfs(0);
	printf("%d",ans);
	return 0;
}