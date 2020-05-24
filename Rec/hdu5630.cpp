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
int T;
int main(){
	freopen("hdu5630.in","r",stdin);
	freopen("hdu5630.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",x/2+y/2);
	}
	return 0;
}
