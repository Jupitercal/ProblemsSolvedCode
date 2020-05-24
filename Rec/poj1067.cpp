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
int a,b; 
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d%d",&a,&b)!=EOF){
		if (a>b)std::swap(a,b);
		int d=b-a;
		int k=floor(d*(sqrt(5.0)+1)/2);
		if (k==a)printf("0\n");else printf("1\n");
	}
	return 0;
}

