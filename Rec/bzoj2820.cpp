#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#define N 10000000
typedef long long LL;
LL sum[N];
int mu[N],prime[N/10],T,g[N];
bool flag[N];
void Mobius(){
	memset(flag,1,sizeof(flag));
	mu[1]=1;
	for (int i=2;i<=N;i++){
		if (flag[i]){
			prime[++prime[0]]=i;
			mu[i]=-1;
			g[i]=1;
		}
		for (int j=1;j<=prime[0];j++){
			int t=prime[j]*i;
			if (t>N)break;
			flag[t]=0;
			if (i%prime[j]==0){
				mu[t]=0;
				g[t]=mu[i];
				break;
			}
			mu[t]=-mu[i];
			g[t]=mu[i]-g[i];
		}
	}
}
LL solve(int n,int m){
	if (n>m)std::swap(n,m);
	int j;
	LL cal=0;
	for (int i=1;i<=n;i=j+1){
		j=std::min(n/(n/i),m/(m/i));
		cal+=(sum[j]-sum[i-1])*(n/i)*(m/i);
	}
	return cal;
}
int main(){
	freopen("bzoj2820.in","r",stdin);
	freopen("bzoj2820.out","w",stdout);
	Mobius();
	for (int i=1;i<=N;i++)sum[i]=sum[i-1]+g[i]; 
	scanf("%d",&T);
	while (T--){
		int n,m;
		scanf("%d%d",&n,&m);
		printf("%lld\n",solve(n,m));
	}
	return 0; 
} 
