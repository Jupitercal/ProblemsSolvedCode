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
typedef long long LL;
int T,n;
LL F[50];
int main(){
	F[0]=1;
	for (int i=1;i<=35;i++){
		if (i>=2)F[i]+=2*F[i-2];
		F[i]+=F[i-1];
	}
	while (scanf("%d",&T)!=EOF)
	while (T--){
		scanf("%d",&n);
		printf("%lld\n",F[n]);
	}
	return 0;
}
