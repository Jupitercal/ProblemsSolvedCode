/*
ID: Rec
PROG: money
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
typedef long long LL;
#define N 10001
int v,n,co[N];
LL F[N];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d%d",&v,&n);
	for (int i=1;i<=v;i++)scanf("%d",&co[i]);
	F[0]=1;
	for (int i=1;i<=v;i++)
	 for (int j=co[i];j<=n;j++)
	   F[j]+=F[j-co[i]];
	printf("%lld\n",F[n]);
	return 0;
} 
