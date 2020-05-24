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
#define N 30000
typedef long long LL;
int tot;
LL tr[N];
int n,a[N]; 
LL pop(){
	if (tot<0)return 0;
	int num=tr[1];
	tr[1]=tr[tot];
	int x=1;tot--;
	if (tot<=0)return num;
	while(x*2<=tot){
		int j=x*2;
		if (tr[j+1]<tr[j]&&j<tot)j++;
		if (tr[x]>tr[j])std::swap(tr[x],tr[j]);
		x=j;
	}
	return num;
}
void insert(LL x){
	if (tot<0)return;
	tr[++tot]=x;
	int y=tot;
	while (y/2){
		if (tr[y]<tr[y/2])std::swap(tr[y],tr[y/2]);
		y/=2;
	}
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		tot=0;
		for (int i=1;i<=n;i++){
			LL x;
			scanf("%lld",&x);
			insert(x);
		}
		LL ans=0;
		for (int i=1;i<=n-1;i++){
			LL x1=pop();
			LL y1=pop();
			ans+=x1+y1;
			insert(x1+y1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

