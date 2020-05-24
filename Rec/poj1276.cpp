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
#define N 200000
int F[N],count[N],c[N],w[N];
int tot,n,ans;
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (std::cin>>tot>>n){
		memset(F,0,sizeof(F));
		ans=0;
		for (int i=1;i<=n;i++)scanf("%d%d",&c[i],&w[i]);
		for (int i=1;i<=n;i++){
			for (int j=0;j<=tot;j++)count[j]=0;
			for (int j=w[i];j<=tot;j++)
			  if (F[j]<F[j-w[i]]+w[i]&&count[j-w[i]]<c[i]){
			  	F[j]=F[j-w[i]]+w[i];
			  	ans=std::max(F[j],ans);
			  	count[j]=count[j-w[i]]+1;
			  }
		}
		printf("%d\n",ans);
	}
	return 0;
}

