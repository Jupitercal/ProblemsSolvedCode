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
int n;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int e=a*d+c*b;
		int mi=gcd(e,b*d);
		printf("%d %d\n",e/mi,b*d/mi);
	}
	return 0;
}
