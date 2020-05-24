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
#define N 1005
int A[N],n;
void plus(int x){
	while (x<=n){
		A[x]+=1;
		x+=x&(-x);
	}
}
int sum(int x){
	int suc=0;
	while (x){
		suc+=A[x];
		x-=x&(-x);
	}
	return suc;
}
int main(){
	freopen("hdu2689.in","r",stdin);
	freopen("hdu2689.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		memset(A,0,sizeof(A));
		int ans=0;
		for (int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			x=n-x+1;
			ans+=sum(x);
			plus(x);
		}
		printf("%d\n",ans);
	}
	return 0;
} 
