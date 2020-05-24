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
int T;
int main(){
	freopen("hdu2662.in","r",stdin);
	freopen("hdu2662.out","w",stdout);
	scanf("%d",&T);
	for (int cases=1;cases<=T;cases++){
		LL l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",(LL)(l-1)*(r-1)-1);
	}
	return 0;
}
