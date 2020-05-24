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
int main(){
	freopen("hdu5605.in","r",stdin);
	freopen("hdu5605.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",x*y*2);
	}
	return 0;
}
