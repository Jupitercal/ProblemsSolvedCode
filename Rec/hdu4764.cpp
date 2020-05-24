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
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d%d",&n,&m)&&n&&m){
		n--;
		if (n%(m+1)==0)printf("Jiang\n");else printf("Tang\n");
	}
	return 0;
}

