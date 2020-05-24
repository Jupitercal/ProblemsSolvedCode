#include<bits/stdc++.h>
#define MOD 1000000007
#define N 1200
typedef long long LL;
int T,n,m,tou[N],dd,len;
LL inv2,F[N][N],ans[N];
struct aa{
	int p,next;
}da[N*6];
LL ksm(LL x,int c){
	LL a=1;
	while (c){
		if (c&1)a=(a*x)%MOD;
		x=(x*x)%MOD;
		c/=2;
	}
	return a;
}
void add(int x,int y){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;
}
void FWT_xor(LL *a,int opt,int n){
	for (int i=1;i<n;i<<=1)
		for (int p=i<<1,j=0;j<n;j+=p)
			for (int k=0;k<i;k++){
				LL x=a[j+k]%MOD,y=a[j+i+k]%MOD;
				a[j+k]=(x+y)%MOD;a[j+i+k]=(x-y+MOD)%MOD;
				if (opt==-1) a[j+k]=1LL*a[j+k]*inv2%MOD,a[i+j+k]=1LL*a[i+j+k]*inv2%MOD;
			}
}
void dfs(int x,int fa){
	FWT_xor(F[x],1,len);
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (v==fa)continue;
		dfs(v,x);
		for (int j=0;j<len;j++)F[x][j]=1LL*F[x][j]*F[v][j]%MOD;
	}
	FWT_xor(F[x],-1,len);
	for (int j=0;j<m;j++)ans[j]=(ans[j]+F[x][j])%MOD;
	F[x][0]=(F[x][0]+1)%MOD;
	FWT_xor(F[x],1,len);
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	inv2=ksm(2,MOD-2);
	while (T--){
		memset(F,0,sizeof(F));
		memset(tou,0,sizeof(tou));
		memset(ans,0,sizeof(ans));
		dd=0;
		scanf("%d%d",&n,&m);
		len=1;
		while (len<m)len*=2;
		for (int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			F[i][x]++;
		}
		for (int i=1;i<=n-1;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		dfs(1,0);
		for (int i=0;i<m;i++){
			printf("%I64d",ans[i]);
			if (i==m-1)printf("\n");else printf(" ");
		}
	}
	return 0;
}