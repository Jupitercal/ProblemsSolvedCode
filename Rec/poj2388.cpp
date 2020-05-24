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
int a[N],n;
bool cmp(int x,int y){return x<y;}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	std::sort(a+1,a+1+n,cmp);
	if (n%2)++n;
	printf("%d",a[n/2]);
	return 0;
}

