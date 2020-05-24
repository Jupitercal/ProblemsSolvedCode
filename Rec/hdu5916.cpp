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
int T,x,n,k;
int main(){
	scanf("%d",&T);x=0;
	while (T--){
		scanf("%d%d",&n,&k);
		printf("Case #%d:",++x);
		printf(" %d %d",2*k,k);
		for (int i=k-1;i>=1;i--)printf(" %d",i);
		for (int i=k+1;i<=n;i++)
		  if (i!=2*k)printf(" %d",i);
		printf("\n");
	}
	return 0;
} 
