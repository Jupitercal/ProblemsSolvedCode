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
#define N 2000
int T,a[N],n;
bool cmp(int x,int y){return x<y;}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		int sum=0;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		std::sort(a+1,a+n+1,cmp);
		for (int i=n;i>0;i-=2){
			if (i==1)sum^=(a[i]-0-1);
			else sum^=(a[i]-a[i-1]-1);
		}
		if (sum==0)printf("Bob will win\n");else printf("Georgia will win\n");
	}
	return 0;
}

