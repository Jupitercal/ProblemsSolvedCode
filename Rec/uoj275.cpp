#include<bits/stdc++.h>
#define MOD 1000000007
#define N 90
typedef long long LL;
LL F[N][2][2],sn[N],sm[N];
LL n,m,ans;
int t,K;
void add(LL &x,LL y){
	x+=y;
	if (x>=MOD)x-=MOD;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d%d",&t,&K);
	while (t--){
		memset(F,0,sizeof(F));
		scanf("%lld%lld",&n,&m);m=std::min(n,m);
		int tn=0;
		ans=(((m+1)%MOD)*((m+2)%MOD)%MOD*500000004%MOD+((n-m)%MOD)*((m+1)%MOD)%MOD)%MOD;
		for (;n;n/=K,m/=K){
			++tn;
			sn[tn]=n%K;
			sm[tn]=m%K;
		}
		F[tn+1][1][1]=1;
		for (int i=tn;i>=1;i--)
			for (int j=0;j<2;j++)
				for (int k=0;k<2;k++)
					if (F[i+1][j][k])
						for (int x=0;x<=(j?sn[i]:K-1);x++)
							for (int y=0;y<=(k?sm[i]:K-1)&&y<=x;y++)
								add(F[i][j&(sn[i]==x)][k&(y==sm[i])],F[i+1][j][k]);
		for (int i=0;i<2;i++)
			for (int j=0;j<2;j++)
				add(ans,MOD-F[1][i][j]);
		printf("%lld\n",ans);
	}
	return 0;
}