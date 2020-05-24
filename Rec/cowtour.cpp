/* 
ID: rec 
PROG: cowtour
LANG: C++ 
*/  
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 300
struct aa{
	int x,y;
}poi[N];
int n,i,j;
double dist[N][N],MAX,dis[N],MA;
int sqr(int x){return x*x;}
double disc(int a,int b){return sqrt(sqr(poi[a].x-poi[b].x)+sqr(poi[a].y-poi[b].y));}
double min(double a,double b){if (a>b)return b;else return a;}
char s[N];
int main(){
	freopen("cowtour.in","r",stdin);
	freopen("cowtour.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++)scanf("%d%d",&poi[i].x,&poi[i].y);
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			dist[i][j]=10000000.0;
	for (i=1;i<=n;i++)dist[i][i]=0.0;
	for (i=1;i<=n;i++){
		scanf("%s",s);
		for (j=1;j<=n;j++)
			if (s[j-1]=='1') dist[i][j]=disc(i,j);
	}
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			if (i!=j)
			for (int k=1;k<=n;k++)
				if (k!=j&&i!=k)
				 dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			 if (dis[i]<dist[i][j]&&dist[i][j]!=10000000.0)
			 dis[i]=dist[i][j],MA=dis[i]>MA?dis[i]:MA;
	MAX=10000000.0;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			if (i!=j&&dist[i][j]==10000000.0)
				MAX=min(MAX,disc(i,j)+dis[i]+dis[j]);
    double ans=MA>MAX?MA:MAX;
	printf("%.6f\n",ans);
	return 0;
}
