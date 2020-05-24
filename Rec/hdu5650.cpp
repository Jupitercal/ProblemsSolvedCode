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
		if (n==1){
			int x;
			scanf("%d",&x);
			printf("%d\n",x);
		}else {
			int x;
			for (int i=1;i<=n;i++)scanf("%d",&x);
			printf("0\n");
		}
	}
	return 0;
}
