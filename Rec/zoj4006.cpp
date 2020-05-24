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
#define N 1000050
#define MOD 1000000007
typedef long long LL;
LL inv[N],fac[N],p[N];
int nn,mm,T;
LL C(int n,int m){return n<m?0:fac[n]*inv[n-m]%MOD*inv[m]%MOD;}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	inv[0]=inv[1]=1;fac[0]=fac[1]=1;
	for (int i=2;i<=N-50;i++)fac[i]=fac[i-1]*i%MOD;
	for (int i=2;i<=N-50;i++)inv[i]=(MOD-inv[MOD%i])*(MOD/i)%MOD;
	for (int i=2;i<=N-50;i++)inv[i]=inv[i-1]*inv[i]%MOD;
	p[0]=1;p[1]=inv[2];
	for (int i=2;i<=N-50;i++)p[i]=p[i-1]*p[1]%MOD;
	while (T--){
		scanf("%d%d",&nn,&mm);
		LL ans=0;
		for (int i=0;i<=nn;i++){
			int x=i;
			int y=i-mm;
			int z=nn-x-y;
			if (y<0||y>nn||z<0||z>nn)continue;
			ans=(C(nn,x)*C(nn-x,y)%MOD*p[(x+y)*2+z]%MOD+ans)%MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

