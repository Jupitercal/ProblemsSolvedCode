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
typedef long long LL;
LL F[30];
int T;
LL C(int x,int y){
	if (x==y||y==0)return 1;
	LL sum=1;
	for (int i=x;i>=(x-y+1);i--)sum*=i;
	for (int i=y;i;i--)sum/=i;
	return sum;
}
int main(){
	memset(F,0,sizeof(F));
	for (int i=1;i<=20;i++)
		for (int j=1;j<=i;j++)
		 F[i]+=j*C(i-1,j-1);
	scanf("%d",&T);
	for (int i=1;i<=T;i++){
		int x;
		scanf("%d",&x);
		printf("%lld\n",F[x]);
	}
	return 0;
}
