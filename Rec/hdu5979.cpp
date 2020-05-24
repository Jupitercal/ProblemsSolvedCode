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
#define pi 3.1415926  
int n,d;
double ans;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("hdu5979.in","r",stdin);
	freopen("hdu5979.out","w",stdout);
	#endif
	while (scanf("%d%d",&n,&d)!=EOF){
		int angel;
		ans=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&angel);
			ans+=d*d*0.5*sin(1.0*angel/180*pi);
		}
		printf("%.3f\n",ans);
	}
	return 0;
} 
