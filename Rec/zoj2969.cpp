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
#define N 200
int n,c[N],T;
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		bool f=0;
		for (int i=1;i<=n+1;i++){
			scanf("%d",&c[i]);
			c[i]=c[i]*(n-i+1); 
			if (c[i]!=0)f=1;
		}
		if (f==0)printf("0");
		else {
			printf("%d",c[1]);
			for (int i=2;i<=n;i++)
			  printf(" %d",c[i]);
		}
		if (T)printf("\n");
	}
	return 0;
}

