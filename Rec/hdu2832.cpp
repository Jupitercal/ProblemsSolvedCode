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
int n,ans1[10];
double distance;
int main(){
	freopen("hdu2832.in","r",stdin);
	freopen("hdu2832.out","w",stdout);
	ans1[5]=272400600;ans1[6]=9717617;ans1[7]=898515;
	while (scanf("%d",&n)!=EOF){
		double v=n*1.0/100;
		int ans=0;
		distance=1.0;
		if (n>7){
			while (distance>1e-5){
				distance-=v;
				distance*=(ans+2)*1.0/(ans+1);			
				++ans;
			}
			printf("%d\n",ans);
	   }else printf("%d\n",ans1[n]);
	}
	return 0;
}
