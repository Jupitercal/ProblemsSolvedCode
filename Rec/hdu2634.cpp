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
int T,n;
double x,ans;
int main(){
	scanf("%d",&T);
	while (T--){
		ans=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)scanf("%lf",&x),ans+=x;
		printf("The average M = %.10f.\n",ans/n);
	}
	return 0;
}
