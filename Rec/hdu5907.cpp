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
#define N 100005
typedef long long LL;
int T;
char s[N];
int main(){
	freopen("hdu5907.in","r",stdin);
	freopen("hdu5907.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%s",s);
		int len=strlen(s);
		int sum=0;LL ans=0;
		for (int i=0;i<len;i++){
			if (s[i]!='q'){
				ans+=(sum+1)*sum/2;
				sum=0;
			}else sum++;
		}
		if (sum) ans+=(sum+1)*sum/2;
		printf("%I64d\n",ans);
	}
	return 0;
} 
