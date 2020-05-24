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
#define INF 0x3f3f3f3f
#define N 300
int dist[N][N];
int n;
void Floyd(){
	for (int k=1;k<=n;k++)
	  for (int i=1;i<=n;i++)
	    if (i!=k)
	      for (int j=1;j<=n;j++)
	        if (i!=j&&j!=k)
	          dist[i][j]=std::min(dist[i][j],dist[i][k]+dist[k][j]);
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d",&n)&&n){
		memset(dist,INF,sizeof(dist));
		for (int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			for (int j=1;j<=x;j++){
				int y;
				scanf("%d",&y);
				scanf("%d",&dist[i][y]);
			}
		}
		Floyd();
		int min=INF;int go=0;
		for (int i=1;i<=n;i++){
			int max=0;
			for (int j=1;j<=n;j++)
			  if (i!=j)max=std::max(max,dist[i][j]);
			if (max<min){
				min=max;
				go=i;
			}
		}
		if (min==INF)printf("disjoint\n");
		else printf("%d %d\n",go,min);
	}
	return 0;
}

