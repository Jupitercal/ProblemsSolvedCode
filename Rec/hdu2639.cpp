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
int F[N][30],T,n,V,v[N],a[N],A[30],B[30],K;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("hdu2639.in","r",stdin);
	freopen("hdu2639.out","w",stdout);
	#endif
	scanf("%d",&T);
	while (T--){
		memset(F,0,sizeof(F));
		scanf("%d%d%d",&n,&V,&K);
		for (int i=1;i<=n;i++)scanf("%d",&v[i]);
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		for (int i=1;i<=n;i++)
		  for (int j=V;j>=a[i];j--){
		  	for (int k=1;k<=K;k++){
		  		A[k]=F[j-a[i]][k]+v[i];
		  		B[k]=F[j][k];
		  	}
		  	A[K+1]=B[K+1]=0;
		  	int ma=1;int mb=1;int c=1;
		  	while (c<=K&&(ma<=K||mb<=K)){
		  		if (A[ma]>B[mb])F[j][c]=A[ma],++ma;
		  			else F[j][c]=B[mb],++mb;
		  		if (F[j][c]!=F[j][c-1])++c;
		  	}
		  }
		printf("%d\n",F[V][K]);
	}
	return 0;
}
