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
char s[30];
int max,min,T,n;
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%s\n",s);
		scanf("%d",&n);
		max=-10;min=50000;
		for (int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			max=std::max(x,max);
			min=std::min(x,min);
		}
		if (s[0]=='F')printf("%d\n",min);
		else printf("%d\n",max);
	}
	return 0;
}

