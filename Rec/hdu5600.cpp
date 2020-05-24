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
#define N 1000001
int T,n;
int num[N],b;
int main(){
	freopen("hdu5600.in","r",stdin);
	freopen("hdu5600.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		b=n%2;
	   	for (int i=1;i<=n;i++){
		   int x;
		   scanf("%d",&x);
		   b=(b+x)%2;
	   	}
	   	if (!b)printf("YES\n");else printf("NO\n");
	}
	return 0;
}
