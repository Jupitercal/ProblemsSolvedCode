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
#define N 220
int n;
double x[N],y[N],dist[N][N];
double sqr(double x){return x*x;}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	int cases=0;
	while (scanf("%d",&n)&&n){
		for (int i=1;i<=n;i++)scanf("%lf%lf",&x[i],&y[i]);
		for (int i=1;i<=n;i++)
		  for (int j=1;j<=n;j++)
		    dist[i][j]=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
		for (int k=1;k<=n;k++)
		  for (int i=1;i<=n;i++)
		  if (i!=k)
		    for (int j=1;j<=n;j++)
		    if (k!=j&&i!=j)
		      if (dist[i][k]<dist[i][j]&&dist[k][j]<dist[i][j]){
		        if (dist[i][k]<dist[k][j])dist[j][i]=dist[i][j]=dist[k][j];
		        else dist[j][i]=dist[i][j]=dist[i][k];
				}
		++cases;
		printf("Scenario #%d\n",cases);
		printf("Frog Distance = %.3f\n\n",dist[1][2]);
	}
	return 0;
}

