#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#define N 10000003
#define MOD 100000009
typedef long long LL;
LL sum[N],g[N];
int mu[N],prime[N/3],T;
bool flag[N];
void Mobius(){
	memset(flag,1,sizeof(flag));
	mu[1]=1;g[1]=1;
	for (int i=2;i<N;i++){
		if (flag[i]){
			prime[++prime[0]]=i;
			mu[i]=-1;
			g[i]=1-i;
		}
		for (int j=1;j<=prime[0];j++){
			int t=prime[j]*i;
			if (t>=N)break;
			flag[t]=0;
			if (i%prime[j]==0){
				mu[t]=0;
				g[t]=g[i]%MOD;
				break;
			}
			mu[t]=-mu[i];
			g[t]=(g[prime[j]]*g[i])%MOD;
		}
	}
}
LL get(int x,int y){
	LL a=((LL)x*(x+1)/2)%MOD;
	LL b=((LL)y*(y+1)/2)%MOD;
	return (a*b)%MOD; 
}
LL solve(int n,int m){
	if (n>m)std::swap(n,m);
	int j;
	LL cal=0;
	for (int i=1;i<=n;i=j+1){
		j=std::min(n/(n/i),m/(m/i));
		cal=(cal+(sum[j]-sum[i-1])*get(n/i,m/i)%MOD)%MOD;
	}
	return cal;
}
int main(){
	freopen("bzoj2693.in","r",stdin);
	freopen("bzoj2693.out","w",stdout);
	Mobius();
	for (int i=1;i<N;i++)sum[i]=(sum[i-1]+(i*g[i])%MOD)%MOD; 
	scanf("%d",&T);
	while (T--){
		int n,m;
		scanf("%d%d",&n,&m);
		LL ans=solve(n,m);
		printf("%lld\n",(ans+MOD)%MOD);
	}
	return 0; 
} 
