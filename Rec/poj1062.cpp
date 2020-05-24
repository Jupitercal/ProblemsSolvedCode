/*
ID: Rec
PROG: test
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define N 200
#define INF 0x5f5f5f5f
int dist[N],a[N][N],p[N],l[N];
int m,n;
bool vis[N],vv[N];
void shortest(){
	for (int i=1;i<=n;i++)
	  if (vv[i])dist[i]=p[i];
	  else dist[i]=INF;
	for (int m=1;m<=n;m++){
		int mm=0;int ma=INF;
		for (int i=1;i<=n;i++)
		  if (vv[i]&&!vis[i]){
		  	if (ma>dist[i]){
		  		ma=dist[i];
		  		mm=i;
		  	}
		  }
		vis[mm]=1;
		for (int i=1;i<=n;i++)
		  if (!vis[i]&&vv[i])dist[i]=std::min(dist[i],dist[mm]+a[mm][i]);
	}
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	memset(a,INF,sizeof(a));
	scanf("%d%d",&m,&n);
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d%d%d",&p[i],&l[i],&x);
		for (int j=1;j<=x;j++){
			int x;
			scanf("%d",&x);
			scanf("%d",&a[x][i]);
		}
	}
	int ans=INF;
	int left=l[1]-m?l[1]-m:0;int right=left+m;
	while (left<=l[1]){
		memset(vv,0,sizeof(vv));
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=n;i++)
		  if (l[i]>=left&&right>=l[i])vv[i]=1;
		shortest();
		ans=std::min(ans,dist[1]);
		left++;right++;
	}
	printf("%d",ans);
	return 0;
}

