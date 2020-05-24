#include<bits/stdc++.h>
#define N 60005
typedef long long LL;
int t,a,b,c,d,k,sum[N],mu[N],prim[N],cnt;
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
LL getans(int x,int y){
	if (x>y)std::swap(x,y);
	ans=0;
	for (int l=1,r;l<=x;l=r+1){
		r=std::min(x/(x/l),y/(y/l));
		ans+=1LL*(sum[r]-sum[l-1])*(x/l)*(y/l);
	}
	return ans;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	get_mu(N-5);
	scanf("%d",&t);
	while (t--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		a--,c--;
		printf("%lld\n",getans(b/k,d/k)+getans(a/k,c/k)-getans(a/k,d/k)-getans(b/k,c/k));
	}
	return 0;
}