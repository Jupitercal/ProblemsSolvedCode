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
int n,ans;
int main(){
	freopen("hdu5640.in","r",stdin);
	freopen("hdu5640.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ans=1;
		while (1){
			if (x==y)break;
			if (x>y)x-=y;
			else y-=x;
			ans+=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
