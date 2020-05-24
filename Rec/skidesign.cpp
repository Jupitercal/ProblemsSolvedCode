/*
ID: Rec
PROG: skidesign
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
bool cmp(int x,int y){return x<y;}
int n,a[N],ans,L[N],R[N];
int sqr(int x){return x*x;}
int main(){
	freopen("skidesign.in","r",stdin);
	freopen("skidesign.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);	
	for (int i=0;i<=83;i++)L[i+1]=i,R[i+1]=i+17;
	ans=0x5f5f5f5f;
	for (int i=1;i<=84;i++){
		int m=0;
		for (int j=1;j<=n;j++){
			if (L[i]<=a[j]&&a[j]<=R[i])continue;
			if (a[j]<L[i])m+=sqr(L[i]-a[j]);
			if (R[i]<a[j])m+=sqr(R[i]-a[j]);
		}
		ans=std::min(ans,m);
	}
	printf("%d\n",ans);
	return 0;
}
