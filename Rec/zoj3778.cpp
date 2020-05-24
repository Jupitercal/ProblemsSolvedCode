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
int n,m,T;
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		int max=0;
		int sum=0;
		for (int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			sum+=x;
			max=std::max(x,max);
		}
		printf("%d\n",std::max((sum/m+(sum%m?1:0)),max));
	}
	return 0;
}

