/*
ID: Rec
PROG: test
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define N 500
int n,m;
int T;
int F[N][N],num[N],a[N][N],ans;
int main(){
	freopen("hdu5074.in","r",stdin);
	freopen("hdu5074.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		memset(F,0,sizeof(F));
		ans=0;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;i++)
		  for (int j=1;j<=m;j++)scanf("%d",&a[i][j]);
		for (int i=1;i<=n;i++)scanf("%d",&num[i]);
		for (int i=2;i<=n;i++){
			if (num[i-1]>0){
				if (num[i]>0)F[i][num[i]]=F[i-1][num[i-1]]+a[num[i-1]][num[i]];
				else {
					for (int j=1;j<=m;j++)
					F[i][j]=std::max(F[i][j],F[i-1][num[i-1]]+a[num[i-1]][j]);
				}
			}else{
				if (num[i]>0){
				   for (int j=1;j<=m;j++)
				   F[i][num[i]]=std::max(F[i][num[i]],F[i-1][j]+a[j][num[i]]);	
				}
				else {
					for (int j=1;j<=m;j++)
					 for (int k=1;k<=m;k++)
					  F[i][j]=std::max(F[i][j],F[i-1][k]+a[k][j]);
				}
			}
		}
		for (int i=1;i<=m;i++) ans=std::max(ans,F[n][i]);
		printf("%d\n",ans);
	}
	return 0;
}
