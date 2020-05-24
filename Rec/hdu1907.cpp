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
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int ans=0;
		scanf("%d",&n);
		bool f=0;
		for (int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			ans^=x;
			if (x!=1)f=1;
		}
		if (f){
			 if (ans==0)printf("Brother\n");else printf("John\n");
		}else{
			if (n%2)printf("Brother\n");else printf("John\n");
		}
	}
	return 0;
}

