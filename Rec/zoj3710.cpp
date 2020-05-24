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
#define N 160
int T,n,m,kk,dd,ans;
bool dist[N][N],B;
int main(){
	freopen("zoj3710.in","r",stdin);
	freopen("zoj3710.out","w",stdout);
	while (scanf("%d",&T)!=EOF){
		while (T--){
			scanf("%d%d%d",&n,&m,&kk);
			for (int i=1;i<=n;i++)
			  for (int j=1;j<=n;j++)dist[i][j]=0;
			for (int i=1;i<=m;i++){
				int u,v;
				scanf("%d%d",&u,&v);
				u++;v++;
				dist[u][v]=dist[v][u]=1;
			}
			bool b=1;
			ans=0;
			while (b){
				b=0;
				for (int i=1;i<=n;i++)
					for (int j=1;j<=n;j++)
						if (i!=j&&!dist[i][j]){
							int sum=0;
							for (int k=1;k<=n;k++)
					  			if (i!=k&&k!=j)sum+=dist[i][k]&dist[k][j];
					  		if (sum>=kk){
					  			++ans;
					  			b=1;
					  			dist[i][j]=dist[j][i]=1;
					  		}
						}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
