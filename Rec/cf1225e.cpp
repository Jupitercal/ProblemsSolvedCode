#include<bits/stdc++.h>
typedef long long LL;
#define MOD 1000000007
#define N 2005
int n,m,row[N][N],col[N][N],num[N][N];
LL F[N][N][2],sum[N][N][2];
char s[N][N];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++){
		for (int j=m;j>=1;j--){
			int x=0;
			if (s[i][j]=='R')x=1,num[i][j]=1;
			row[i][j]=row[i][j+1]+x;
		}
	}
	for (int j=1;j<=m;j++)
		for (int i=n;i>=1;i--){
			int x=0;
			if (s[i][j]=='R')x=1;
			col[i][j]=col[i+1][j]+x;
		}
	F[1][1][0]=F[1][1][1]=1;
	if (col[1][1]>=n-1)F[1][1][0]=0;
	if (row[1][1]>=m-1)F[1][1][1]=0;
	sum[1][1][1]=F[1][1][1];
	sum[1][1][0]=F[1][1][0];
	for (int i=2;i<=m;i++){
		if (row[1][1]<=m-i)F[1][i][0]=sum[1][i][0]=F[1][1][1];
	}
	for (int i=2;i<=n;i++){
		if (col[1][1]<=n-i)F[i][1][1]=sum[i][1][1]=F[1][1][0];
	}
	for (int i=2;i<=n;i++){
		for (int j=2;j<=m;j++){
			//if (i*j==1)continue;
			int l=1;int r=j;int now=j;
			while (l<=r){
				int mid=(l+r)/2;
				if (row[i][mid]-num[i][mid]<=(m-j)){
					r=mid-1;
					now=mid;
				}else{
					l=mid+1;
				}
			}
			//printf("1 %d %d %d g %d ",i,j,now,row[i][now]);
			F[i][j][0]=(sum[i][j-1][1]-sum[i][now-1][1]+MOD)%MOD;
			//printf("%lld heng\n",F[i][j][0]);
			sum[i][j][0]=(sum[i-1][j][0]+F[i][j][0])%MOD;
			l=1;r=i; now=i;
			while (l<=r){
				int mid=(l+r)/2;
				if (col[mid][j]-num[mid][j]<=(n-i)){
					r=mid-1;
					now=mid;
				}else{
					l=mid+1;
				}
			}
			//printf("2 %d %d %d g %d ",i,j,now,col[now][j]);
			F[i][j][1]=(sum[i-1][j][0]-sum[now-1][j][0]+MOD)%MOD;
			//printf("%lld shu\n",F[i][j][1]);
			sum[i][j][1]=(sum[i][j-1][1]+F[i][j][1])%MOD;
		}
	}
	if (n==m&&m==1)printf("1\n");
	else 
	printf("%lld\n",(F[n][m][1]+F[n][m][0])%MOD);
	return 0;
}