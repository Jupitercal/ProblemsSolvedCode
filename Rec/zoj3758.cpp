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
int F[15][17]={{0,0,1,1,0,1,0,1,0,0,0,0,0,1,0,0,0},
{0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0},
{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0},
{0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
int n,m;
int main(){

	while (scanf("%d%d",&n,&m)!=EOF){
		if (F[n-2][m])printf("YES\n");else printf("NO\n");
	}
	return 0;
}
