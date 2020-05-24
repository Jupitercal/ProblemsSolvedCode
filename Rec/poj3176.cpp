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
#define N 605
int F[N][N],n;
int a[N][N],ans;
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&n);
	ans=0;
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=i;j++)scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++)
	  for  (int j=1;j<=i;j++){
	  	if (j-1>0)F[i][j]=std::max(F[i][j],F[i-1][j-1]+a[i][j]);
	  	F[i][j]=std::max(F[i][j],F[i-1][j]+a[i][j]);
	  }
	for (int i=1;i<=n;i++)ans=std::max(ans,F[n][i]);
	printf("%d",ans);
	return 0;
}

