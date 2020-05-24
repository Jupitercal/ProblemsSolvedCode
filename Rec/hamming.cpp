/*
ID: Rec
PROG: hamming
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define N 30000
int n,b,d,ans[N];
int main(){
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	scanf("%d%d%d",&n,&b,&d);
	int r=1<<b;
	ans[++ans[0]]=0;
	for (int i=1;i<=r;i++){
		bool b=1;
		for (int j=1;j<=ans[0];j++){
			int p=i^ans[j];
			int num=0;
			while (p){
				if (p&1)++num;
				p/=2;
			}
			if (num<d)b=0;
			if (!b)break;
		}
		if (b)ans[++ans[0]]=i;
		if (ans[0]==n)break;
	}
	for (int i=1;i<=n;i++){
		if (i==n){
			printf("%d\n",ans[i]);
			break;
		}
		if (i%10)printf("%d ",ans[i]);
		else printf("%d\n",ans[i]);
	}
	return 0;
}
