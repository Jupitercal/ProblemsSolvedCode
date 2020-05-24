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
int F[220][3005],T,n,k;
int w[3000],v[3000],W,ans;
int main(){
	freopen("hdu2660.in","r",stdin);
	freopen("hdu2660.out","w",stdout);
	while (scanf("%d",&T)!=EOF){
	   while (T--){
			memset(F,0,sizeof(F));
			scanf("%d%d",&n,&k);
			for (int i=1;i<=n;i++)scanf("%d%d",&v[i],&w[i]);
			scanf("%d",&W);
			ans=0;
			for (int i=1;i<=n;i++)
				   for (int j2=W;j2>=w[i];j2--)
				    	for (int j1=1;j1<=k;j1++){
			   		F[j1][j2]=std::max(F[j1][j2],F[j1-1][j2-w[i]]+v[i]);
			   		ans=std::max(ans,F[j1][j2]);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
