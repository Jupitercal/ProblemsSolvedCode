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
int n,a,b,c;
int main(){
	freopen("hdu3188.in","r",stdin);
	freopen("hdu3188.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&a,&b,&c);
		if (a>b)std::swap(a,b);
		if (b>c)std::swap(b,c);
		if (a*a+b*b==c*c)printf("good\n");
		else if (a==b||a==c||b==c)printf("perfect\n");
		else printf("just a triangle\n");
	}
	return 0;
}
