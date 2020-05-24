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
int T,n,a,b,c,d,e,f,g;
bool pd(){
	d-=g;e-=g;f-=g;
	if (d<0||e<0||f<0)return 0;
	a-=d+f+g;
	b-=d+e+g;
	c-=e+f+g;
	if (a<0||b<0||c<0)return 0;
	return 1;
}
int main(){
	freopen("hdu6106.in","r",stdin);
	freopen("hdu6106.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		int max=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
			if (pd())max=std::max(max,a+b+c+d+e+f+g);
		}
		printf("%d\n",max);
	}
	return 0;
}
