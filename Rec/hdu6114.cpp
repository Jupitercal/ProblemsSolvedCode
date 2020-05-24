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
const LL MOD=1e9+7;
LL pow_mod(LL a,LL b){
	LL sum=1;
	while (b){
		if (b&1)sum=sum*a%MOD;
		b/=2;
		a=(a*a)%MOD;
	}
	return sum%MOD;
}
LL C(LL x,LL y){
	if (x<y)return 0;
	if (y>x-y)y=x-y;
	LL sum=1;
	for (LL i=1;i<=y;i++){
		sum=(LL)sum*(x-i+1)%MOD;
		LL a=pow_mod(i,MOD-2);
		sum=(LL)sum*a%MOD;
	}
	return sum;
}
LL lucas(LL x,LL y){
	if (y==0) return 1;
	LL sum=1;
	while (x&&y&&sum){
		sum=(LL)sum*C(x%MOD,y%MOD)%MOD;
		x/=MOD;
		y/=MOD;
	}
	return sum;
}
int main(){
	freopen("hdu6114.in","r",stdin);
	freopen("hdu6114.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--){
		LL n,m;
		scanf("%I64d%I64d",&n,&m);
		if (n<m)std::swap(n,m);
		printf("%I64d\n",lucas(n,m));
	}
	return 0;
}
