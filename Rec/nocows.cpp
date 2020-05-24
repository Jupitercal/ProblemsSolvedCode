/*
ID: Rec
PROG: nocows
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define N 300
#define MOD 9901
int F[N][N];
int n,k;
int main(){
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i++)F[i][1]=1;
	for (int i=1;i<=k;i++)
	  for (int j=3;j<=n;j+=2)
	    for (int l=1;l<=j-2;l+=2)
	      F[i][j]=(F[i][j]+F[i-1][l]*F[i-1][j-l-1])%MOD;
	printf("%d\n",(F[k][n]-F[k-1][n]+MOD)%MOD);
	return 0;
}
