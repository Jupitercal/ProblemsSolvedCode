/*
ID: Rec
PROG: frac1
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define N 50000
struct aa{
	int x,y;
	double num;
}a[N];
int n,cum;
bool cmp(aa q, aa w){
	return (q.num<w.num);
}
int gcd(int x,int y){
	if (y==0)return x;
	return (gcd(y,x%y));
}
int main(){
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	scanf("%d",&n);
	printf("0/1\n");
	for (int i=2;i<=n;i++)
	  for (int j=1;j<=i-1;j++){
	  	if (gcd(j,i)!=1)continue;
	  	a[++cum].x=j;a[cum].y=i;
	  	a[cum].num=j*1.0/i;
	  }
	std::sort(a+1,a+cum+1,cmp);
	for (int i=1;i<=cum;i++)printf("%d/%d\n",a[i].x,a[i].y);
	printf("1/1\n");
	return 0;
}
