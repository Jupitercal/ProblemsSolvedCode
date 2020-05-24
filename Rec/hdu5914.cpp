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
typedef long long LL;
int F[N];
int n,x,T;
int main(){
	freopen("hdu5914.in","r",stdin);
	freopen("hdu5914.out","w",stdout);
	F[0]=1;F[1]=1;F[2]=2;F[3]=3;F[4]=3;
	F[5]=4;F[6]=5;F[7]=6;F[8]=7;F[9]=7;
	F[10]=8;F[11]=9;F[12]=10;F[13]=11;F[14]=12;
	F[15]=13;F[16]=14;
	x=0;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		if (n>3)printf("Case #%d: %d\n",++x,F[n-4]);
		else printf("Case #%d: 0\n",++x);
	}
	return 0;
}
