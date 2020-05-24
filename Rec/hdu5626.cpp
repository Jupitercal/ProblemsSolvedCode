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
typedef long long LL;
LL seed;
int n,T;
LL x[N],y[N],maxa,maxb,mia,mib;
inline LL rand(LL l, LL r) {
  static LL mo=1e9+7, g=78125;
  return l+((seed*=g)%=mo)%(r-l+1);
}

int main(){
	freopen("hdu5626.in","r",stdin);
	freopen("hdu5626.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%lld",&n,&seed);
		for (int i=1;i<=n;i++){
			x[i] = rand(-1000000000, 1000000000);
            y[i] = rand(-1000000000, 1000000000);    
		}
		maxa=mia=x[1]+y[1];
		maxb=mib=x[1]-y[1];
		for (int i=2;i<=n;i++){
			maxa=std::max(x[i]+y[i],maxa);
			maxb=std::max(x[i]-y[i],maxb);
			mia=std::min(x[i]+y[i],mia);
			mib=std::min(x[i]-y[i],mib);
		}
		printf("%lld\n",std::max(maxa-mia,maxb-mib));
	}
	return 0;
}
