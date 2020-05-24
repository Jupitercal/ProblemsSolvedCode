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
#define N 50005
typedef long long LL; 
const LL MOD=1e9+7;
int m,prime[N];
LL n,g[1<<16],cg[1<<16],inv2;
bool b[N];
void Prime(){
	for (int i=2;i<=N-5;i++)
		if (!b[i]){
			prime[++prime[0]]=i;
			for (int j=2;i*j<N;j++)b[j*i]=1;
		}
}
LL ksm(LL x,int c){
	LL a=1;
	while (c){
		if (c&1)a=(a*x)%MOD;
		x=(x*x)%MOD;
		c/=2;
	}
	return a;
}
void FWT_xor(LL *a,int opt,int n){
    for(int i=1;i<n;i<<=1)
        for(int p=i<<1,j=0;j<n;j+=p)
            for(int k=0;k<i;++k){
                LL X=a[j+k],Y=a[i+j+k];
                a[j+k]=(X+Y)%MOD;a[i+j+k]=(X+MOD-Y)%MOD;
                if(opt==-1)a[j+k]=1ll*a[j+k]*inv2%MOD,a[i+j+k]=1ll*a[i+j+k]*inv2%MOD;
            }
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	Prime();
	inv2=ksm(2,MOD-2);
	while (scanf("%lld%d",&n,&m)!=EOF){
		memset(g,0,sizeof(g));
		memset(cg,0,sizeof(cg));
		for (int i=1;i<=prime[0];i++)
			if (prime[i]<=m){
				g[prime[i]]=1;
			}else break;
		int len=1;
		while (len<=m)len*=2;
		n--;
		for (int i=0;i<len;i++)cg[i]=g[i];
		FWT_xor(cg,1,len);
		FWT_xor(g,1,len);
		while (n){
			if (n&1)for (int i=0;i<len;i++)cg[i]=1LL*cg[i]*g[i]%MOD;
			n/=2;
			for (int i=0;i<len;i++)g[i]=1LL*g[i]*g[i]%MOD;
		}
		FWT_xor(cg,-1,len);
		printf("%lld\n",cg[0]);
	}
	return 0;
}

