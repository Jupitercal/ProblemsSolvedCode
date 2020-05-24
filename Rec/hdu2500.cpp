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
char s[10]="HDU";
int T,n;
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n*3;i++){
			for (int j=1;j<=n;j++)printf("%s",s);
			printf("\n");
		}	
	}
	return 0;
}
