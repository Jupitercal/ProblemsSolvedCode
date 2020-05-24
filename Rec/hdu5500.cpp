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
#define N 30
int num[N];
int T,n,ans;
int main(){
	freopen("hdu5500.in","r",stdin);
	freopen("hdu5500.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		ans=0;
		for (int i=1;i<=n;i++)scanf("%d",&num[i]);
		for (int i=n;i>1;i--){
			int a,b;
			for (int j=1;j<=n;j++)
			  if (num[j]==i){
			  	a=j;
			  	break;
			  }
			for (int j=1;j<=n;j++)
			  if (num[j]==i-1){
			  	b=j;
			  	break;
			  }
			if (b>a){
				for (int j=b;j>=2;j--)num[j]=num[j-1];
				num[1]=i-1;
				++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
