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
int T,n,m,F[1<<13][600],a[20][20];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		memset(F,0,sizeof(F));
		for (int i=1;i<=n;i++)
		  for (int j=1;j<=n;j++)scanf("%d",&a[i][j]);
		F[0][0]=1;
		for (int i=0;i<=(1<<n)-1;i++){
			int tmp=0;
			for (int j=0;j<n;j++)if ((i>>j)&1)++tmp;
			for (int j=0;j<n;j++)
			  if (((i>>j)&1)==0){
			  	for (int k=0;k<=m;k++){
			  		if (a[tmp+1][j+1]+k>m)F[i+(1<<j)][m]+=F[i][k];
			  		else F[i+(1<<j)][k+a[tmp+1][j+1]]+=F[i][k];
			  	}
			  }
		}
		if (F[(1<<n)-1][m]==0)printf("No solution\n");
		else {
			int x=F[(1<<n)-1][m];
			int y=1;
			for (int i=1;i<=n;i++)y*=i;
			printf("%d/%d\n",y/gcd(x,y),x/gcd(x,y));
		}
	}
	return 0;
}

