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
int a,b,c,d;
int gcd(int x,int y){return y?gcd(y,x%y):x;};
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d%d%d%d",&a,&b,&c,&d);
	while (a!=-1&&b!=-1&&c!=-1&&d!=-1){
		bool f=0;
		if (a==0||b==0||c==0)f=1;
		if (f)printf("%d\n",21252-d);
		else {
			int m=a*b/gcd(a,b);
			int ans=m*c/gcd(m,c);
			printf("%d\n",ans-d);
		}
		scanf("%d%d%d%d",&a,&b,&c,&d);
	}
	return 0;
}

