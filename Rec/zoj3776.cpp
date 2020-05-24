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
int T,n,m;
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		int s1,s2;
		s1=s2=0;
		for (int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			s1+=x;
		}
		for (int i=1;i<=m;i++){
			int x;
			scanf("%d",&x);
			s2+=x;
		}
		if (s1>s2)printf("Calem\n");
		else if (s1==s2)printf("Draw\n");
		else printf("Serena\n");
	}
	return 0;
}	

