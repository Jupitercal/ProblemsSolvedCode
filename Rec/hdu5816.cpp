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
#define N 1<<20
typedef long long LL;
int T,n,m,p;
LL gcd(LL x,LL y){return y?gcd(y,x%y):x;}
int num[30];
int A,B,tot;
LL fac[22],cnt,ans,F[N];
int main(){
	freopen("hdu5816.in","r",stdin);
	freopen("hdu5816.out","w",stdout);
	scanf("%d",&T);
	fac[1]=1;
	fac[0]=1;
	for (int i=2;i<=20;i++)fac[i]=i*fac[i-1];
	while (T--){
		scanf("%d%d%d",&p,&n,&m);
		cnt=ans=0;
		memset(F,0,sizeof(F));
		for (int i=1;i<=m;i++)scanf("%d",&num[i]);
		int P=(1<<(n+m))-1;
		F[0]=1;
		for (int i=0;i<=P;i++){
			if (F[i]==0)continue;
			A=B=tot=0;
			for (int j=1;j<=n;j++)
				if ((i>>(j-1))&1)++A;
			for (int j=n+1;j<=n+m;j++)
			    if ((i>>(j-1))&1)++B,tot+=num[j-n];
			if (tot>=p||A-B+1<=0)continue;
			for (int j=1;j<=n+m;j++){
				if ((i>>(j-1))&1)continue;
				F[i^(1<<(j-1))]+=F[i];
		}
	}
		for (int i=0;i<=P;i++){
			if (F[i]==0)continue;
			A=B=tot=0;
			for (int j=1;j<=n;j++)
				if ((i>>(j-1))&1)++A;
			for (int j=n+1;j<=n+m;j++)
			    if ((i>>(j-1))&1)++B,tot+=num[j-n];
			if (tot>=p) ans+=F[i]*fac[n+m-A-B];
	   }
		cnt=fac[n+m];
		LL MOD=gcd(cnt,ans);
		printf("%I64d/%I64d\n",ans/MOD,cnt/MOD);
    }
	return 0;
}
