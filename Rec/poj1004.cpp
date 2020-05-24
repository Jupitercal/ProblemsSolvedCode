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
double sum;
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	sum=0;
	for (int i=1;i<=12;i++){
		double x;
		scanf("%lf",&x);
		sum+=x;
	}
	printf("$%.2f",sum/12);
	return 0;
}
