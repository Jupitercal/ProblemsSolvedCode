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
int n,m;
int main(){
	freopen("hdu2925.in","r",stdin);
	freopen("hdu2925.out","w",stdout);
	scanf("%d%d",&n,&m);
	while (n!=0||m!=0){
		int D=0;
		for (int i=2;i<=n;i++)
		  D=(D+m)%i;
		printf("%d %d %d\n",n,m,D+1);
		scanf("%d%d",&n,&m);
	}
	return 0;
}
