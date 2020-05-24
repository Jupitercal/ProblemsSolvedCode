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
int F[5000];
int main(){
	F[1]=1;F[2]=7;
	for (int i=3;i<=4019;i++){
		F[i]=F[i-2]+3*i*i-3*i+1;
		F[i]%=2009;
	}
	scanf("%d",&n);
	while (n){
		printf("%d\n",F[n%4018]);
		scanf("%d",&n);
	}
	return 0;
}
