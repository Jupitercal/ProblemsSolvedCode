#include<bits/stdc++.h>
#define N 2005
#define MOD 1000000007
typedef long long LL;
int T;
LL pre[N],next[N],n,bin[N];
LL ans,power[N];
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	int cases=0;
	power[0]=1;
	for (int i=1;i<=N-4;i++)power[i]=(power[i-1]*2)%MOD;
	while (T--){
		scanf("%lld",&n);
		memset(pre,0,sizeof(pre));
		memset(next,0,sizeof(next));
		int len=0;
		LL tn=n;
		while (n){
			next[++len]=n%2;
			n/=2;
		}
		for (int i=len;i>=1;i--)pre[len-i+1]=next[i],bin[len-i+1]=next[i];
		for (int i=1;i<=len;i++)pre[i]=(pre[i-1]*2+pre[i])%MOD;
		for (int i=1;i<=len;i++)next[i]=(next[i-1]+next[i]*power[i-1]%MOD)%MOD;
		++cases;
		ans=0;
		for (int i=1;i<=len;i++){
			if (bin[i])ans=(ans+next[len-i]+1)%MOD;
			ans=(ans+pre[i-1]*power[len-i]%MOD)%MOD;
		}
		ans=1LL*(tn+1)%MOD*ans%MOD;
		for (int i=1;i<=len;i++){
			if (bin[i])ans=(ans-(next[len-i]+1)*(next[len-i]+1)%MOD+MOD)%MOD;
			ans=(ans-pre[i-1]*power[len-i]%MOD*power[len-i]%MOD+MOD)%MOD;
		}
		printf("Case #%d: %lld\n",cases,ans);
	}
	return 0;
}