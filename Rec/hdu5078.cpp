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
LL x,y,t1,t,xx,yy;
double ans;
LL sqr(LL x){return x*x;}
int main(){
	freopen("hdu5078.in","r",stdin);
	freopen("hdu5078.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		scanf("%I64d%I64d%I64d",&t1,&xx,&yy);
		ans=0;
		for (int i=2;i<=n;i++){
			scanf("%I64d%I64d%I64d",&t,&x,&y);
			double m=sqrt(sqr(x-xx)+sqr(y-yy))/(double)(t-t1);
			if (m-ans>1e-12)ans=m;
			t1=t;xx=x;yy=y;
		}
		printf("%.10f\n",ans);
	}
	return 0;
}
