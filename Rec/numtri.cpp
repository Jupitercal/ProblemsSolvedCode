/*
ID: Rec
PROG: numtri
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define N 1005
int F[N][N],a[N][N],n;
int mar;
int main(){
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=i;j++)scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=i;j++)
	   F[i][j]=a[i][j]+std::max(F[i-1][j-1],F[i-1][j]);
	for (int i=1;i<=n;i++)mar=std::max(mar,F[n][i]);
	printf("%d\n",mar);
	return 0;
}
