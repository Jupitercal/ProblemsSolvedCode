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
#define N 100005
typedef long long LL;
int T,n,num[N],has[N],prime[N],prim,cnt[N][20];
int ext[N];
LL ans;
bool isprime[N];
void init(){
	isprime[0]=1;isprime[1]=1;
	for (int i=2;i<N;i++)
	   if (!isprime[i]){
	      	prime[++prim]=i;
	      	for (int j=2*i;j<=N;j+=i)isprime[j]=1;
	   }
}
void getfactor(){
	for (int i=2;i<=N;i++){
		int m=i;
		for (int j=1;j<=prim;j++){
			if (!isprime[m]){
				cnt[i][++cnt[i][0]]=m;
				break;
			}
			if (m%prime[j]==0){
				cnt[i][++cnt[i][0]]=prime[j];
				while (m%prime[j]==0)m/=prime[j];
			}
		} 
	}
}
void extend(){
	memset(ext,0,sizeof(ext));
	for (int i=1;i<N;i++)
		for (int j=i;j<N;j+=i)
		  if (has[j])++ext[i];
}
LL solve(){
	LL sum=0;
	for (int i=1;i<=n;i++){
		int x=num[i];
		if (x==1)continue;
		LL col=0;
		for (int j=(1<<cnt[x][0])-1;j;j--){
			bool b=0;
			int mul=1;
			for (int k=1;k<=cnt[x][0];k++)
			  if (1<<(k-1)&j){
			  	b^=1;
			  	mul*=cnt[x][k];
			  }
			if (b)col+=(ext[mul]-1);
			else col-=(ext[mul]-1);
		}
		sum+=col*(n-col-1);
	}
	return sum;
}
int main(){
	freopen("hdu5072.in","r",stdin);
	freopen("hdu5072.out","w",stdout);
	scanf("%d",&T);
	init();
	getfactor();
	while (T--){
	  scanf("%d",&n);	
	  memset(has,0,sizeof(has));
	  for (int i=1;i<=n;i++){
	  	int x;
	  	scanf("%d",&x);
	  	has[x]=1;
	  	num[i]=x;
	  }
	  extend();
	  ans=(LL)n*(n-1)*(n-2)/6-solve()/2;
	  printf("%lld\n",ans);
	}
	return 0;
}
