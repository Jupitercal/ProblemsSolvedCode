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
int T,n;
int a[N],sum,max,x;	
int main(){
	//freopen("hdu5835.in","r",stdin);
	//freopen("hdu5835.out","w",stdout);
	scanf("%d",&T);x=0;
	while (T--){
		scanf("%d",&n);
		printf("Case #%d:",++x);
		max=-100;sum=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];max=std::max(max,a[i]);
		}
		sum-=max;
		if (max>=sum*3+2) printf("%d\n",sum*2+1);
		else printf("%d\n",(max+sum)/2);
	}
	return 0;
}
