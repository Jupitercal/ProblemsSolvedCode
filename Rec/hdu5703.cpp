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
int T,n;
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		printf("1");
		for (int i=1;i<=n-1;i++)printf("0");
		printf("\n");
	}
	return 0;
}
