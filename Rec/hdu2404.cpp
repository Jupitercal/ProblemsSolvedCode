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
#define N 501
int n;
int a[N];
int main(){
	freopen("hdu2404.in","r",stdin);
	freopen("hdu2404.out","w",stdout);
	scanf("%d",&n);
	while (n!=0){
		memset(a,0,sizeof(a));
		for (int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			int sum=0;
			for (int j=1;j<=n;j++)
			  if (a[j]==0){
			  	if (sum==x){
			  		a[j]=i;
			  		break;
			  	}
				++sum;
			  }
		}
		for (int i=1;i<n;i++)printf("%d,",a[i]);
		printf("%d\n",a[n]);
		scanf("%d",&n);
	}
	return 0;
}
