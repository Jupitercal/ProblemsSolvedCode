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
LL n,k;
int x;
int main(){
	freopen("hdu6043.in","r",stdin);
	freopen("hdu6043.out","w",stdout);
	x=0;
	while (scanf("%lld%lld",&n,&k)!=EOF){
		printf("Case #%d: ",++x);
		if (n==2){
			if (k%2==0)printf("2\n");
			else printf("1\n");
			continue;
		}
		if (k<=n-1)printf("%lld\n",k);
		else{
			k-=(LL)(n-1);
			k%=(LL)((n-1)*2);
			if (k==1)printf("%lld\n",n);
			else if (k<=(n-1)&&k!=0)printf("%lld\n",--k);
			else{
				if (k==n)printf("%lld\n",n-1);
				else {
					k=(k+(n-1)*2-n)%((n-1)*2);
					printf("%lld\n",k);
				}
			}
		}
	}
	return 0;
}
