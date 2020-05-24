#include<bits/stdc++.h>
#define N 10000005
typedef long long LL;
int g[N],mu[N],prim[N],cnt,T,n,m;
LL sum[N];
bool vis[N];
void get_mu(int n){
    mu[1]=1;
    for(int i=2;i<=n;i++){
        if(!vis[i]){prim[++cnt]=i;mu[i]=-1;}
        for(int j=1;j<=cnt&&prim[j]*i<=n;j++){
            vis[prim[j]*i]=1;
            if(i%prim[j]==0)break;
            else mu[i*prim[j]]=-mu[i];
        }
    }
    for (int i=1;i<=cnt;++i)
    	for(int j=1;j*prim[i]<=n;j++)g[j*prim[i]]+=mu[j];
    for (int i=1;i<=n;i++)sum[i]=sum[i-1]+(LL)g[i];
 }
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	get_mu(N-5);
	while (T--){
		scanf("%d%d",&n,&m);
		int R=std::min(n,m);
		LL ans=0;
		for (int l=1,r;l<=R;l=r+1){
			r=std::min(n/(n/l),m/(m/l));
			ans+=1LL*(sum[r]-sum[l-1])*(n/l)*(m/l);
		}
		printf("%lld\n",ans);
	}
	return 0;
}