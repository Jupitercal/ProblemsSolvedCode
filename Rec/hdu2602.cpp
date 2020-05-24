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
#define N 2000
int F[N],T,n,V,v[N],a[N];
int main(){
	freopen("hdu2602.in","r",stdin);
	freopen("hdu2602.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		memset(F,0,sizeof(F));
		scanf("%d%d",&n,&V);
		for (int i=1;i<=n;i++)scanf("%d",&v[i]);
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		for (int i=1;i<=n;i++)
		  for (int j=V;j>=a[i];j--)
		    F[j]=std::max(F[j],F[j-a[i]]+v[i]);
		printf("%d\n",F[V]);
	}
	return 0;
}
