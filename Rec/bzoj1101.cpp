#include<bits/stdc++.h>
#define N 50005
typedef long long LL;
int t,n,m,d,sum[N],mu[N],prim[N],cnt;
bool vis[N];
LL ans;
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
    for (int i=1;i<=n;i++)sum[i]=sum[i-1]+mu[i];
 }
void getans(int x,int y){
	if (x>y)std::swap(x,y);
	ans=0;
	for (int l=1,r;l<=x;l=r+1){
		r=std::min(x/(x/l),y/(y/l));
		ans+=1LL*(sum[r]-sum[l-1])*(x/l)*(y/l);
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	get_mu(N-5);
	scanf("%d",&t);
	while (t--){
		scanf("%d%d%d",&n,&m,&d);
		getans(n/d,m/d);
	}
	return 0;
}