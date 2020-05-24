#include<bits/stdc++.h>
#define M 1<<21
#define MOD 1000000007
#define N 41
typedef long long LL;
LL dp1[M],dp2[M],cnt[M];
LL count,a[N],ans1,ans2;
int n,m,sta[N],stu[N],n1;
bool dist[N][N];
LL kpow(LL x,LL m){
	LL a=1;
	while (m){
		if (m&1)a=(a*x)%MOD;
		x=(x*x)%MOD;
		m/=2;
	}
	return a;
}
void dfs1(int cur,int state,LL tot){
	if (cur==n/2){
		dp1[state]=tot%MOD;
		dp2[state]=tot*tot%MOD;
		cnt[state]=1;
		return ;
	}
	dfs1(cur+1,state,tot);
	if (state&sta[cur])return;
	dfs1(cur+1,state^(1<<cur),(tot*a[cur])%MOD);
}
void dfs2(int cur,int state,LL tot,int nstate){
	if (cur==n){
		count=(count+cnt[n1-state-1])%MOD;
		ans1=(ans1+tot*dp1[n1-state-1]%MOD)%MOD;
		ans2=(ans2+tot*tot%MOD*dp2[n1-1-state]%MOD)%MOD;
		return;
	}
	dfs2(cur+1,state,tot,nstate);
	if (nstate&stu[cur])return;
	dfs2(cur+1,state|sta[cur],tot*a[cur]%MOD,nstate^(1<<(cur-n/2)));
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d%d",&n,&m)!=EOF){
		ans1=ans2=0;
		count=0;
		memset(dist,0,sizeof(dist));
		memset(sta,0,sizeof(sta));
		memset(stu,0,sizeof(stu));
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		memset(cnt,0,sizeof(cnt));
		for (int i=0;i<n;i++)scanf("%lld",&a[i]),a[i]%=MOD;
			for (int i=1;i<=m;i++){
				int x,y;
				scanf("%d%d",&x,&y);
				x--,y--;
				dist[x][y]=dist[y][x]=1;
			}
		for (int i=0;i<n;i++)
			for (int j=0;j<n/2;j++)
				if (dist[i][j]){
					sta[i]|=1<<j;
				}
		for (int i=0;i<n;i++)
			for (int j=n/2;j<n;j++)
				if (dist[i][j]){
					stu[i]|=1<<(j-n/2);
				}
		dp1[0]=dp2[0]=cnt[0]=1;
		dfs1(0,0,1);
		n1=1<<(n/2);
		for (int i=1;i<n1;i<<=1)
			for (int j=0;j<n1;j++){
				if (!(i&j))continue;
				dp1[j]=(dp1[j^i]+dp1[j])%MOD;
				dp2[j]=(dp2[j^i]+dp2[j])%MOD;
				cnt[j]=(cnt[j^i]+cnt[j])%MOD;
			}
		dfs2(n/2,0,1,0);
		LL inv=kpow(count,MOD-2);
		LL mid=ans1*inv%MOD;
		LL ans=(ans2*inv%MOD-mid*mid%MOD+MOD)%MOD;
		//while (ans<0)ans+=MOD;
		printf("%lld\n",ans);
	}
	return 0;
}