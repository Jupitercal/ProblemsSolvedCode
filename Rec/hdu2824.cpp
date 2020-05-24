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
int l,r;
long long ans;
int main(){
	freopen("hdu2824.in","r",stdin);
	freopen("hdu2824.out","w",stdout);
	while (scanf("%d%d",&l,&r)!=EOF){
		ans=(r+l)*(r-l+1)/2;
		printf("%I64d\n",ans);
	}
	return 0;
}
