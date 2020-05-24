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
int a[5],T,sum,ans,v[5];
int main(){
	scanf("%d",&T);
	v[1]=300;v[2]=100;v[3]=50;
	while (T--){
		scanf("%d%d%d",&a[1],&a[2],&a[3]);
		sum=0;ans=0;
		for (int i=1;i<=3;i++){
			for (int j=1;j<=a[i];j++){
				ans+=(sum*2+1)*v[i];
				++sum;
			}
		}
		printf("%d ",ans);
		sum=0;ans=0;
		for (int i=3;i;i--){
			for (int j=1;j<=a[i];j++){
				ans+=(sum*2+1)*v[i];
				++sum;
			} 
		}
		printf("%d\n",ans);
	}
	return 0;
}
