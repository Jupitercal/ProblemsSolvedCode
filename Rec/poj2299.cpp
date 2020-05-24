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
#define N 504000
typedef long long LL;
struct aa{
	int pos;
	LL x;
}node[N];
bool cmp(aa a,aa b){return a.x<b.x;}
int MAXN,cases,n,a[N];
LL num[N];
LL sum(int x){
	LL s=0;
	while (x){
		s+=num[x];
		x-=x&(-x);
	}
	return s;
}
void plus(int x,int v){
	while (x<=MAXN){
		num[x]+=v;
		x+=x&(-x);
	}
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	bool b=0;
	while (scanf("%d",&n)&&n){
		LL ans=0;
		if (b)printf("\n");
		MAXN=n;
		for (int i=1;i<=n;i++)scanf("%lld",&node[i].x),node[i].pos=i;
		std::sort(node+1,node+1+n,cmp);
		int j=1;
		a[node[1].pos]=j;
		for (int i=2;i<=n;i++){
			if (node[i].x!=node[i-1].x)j++;
			a[node[i].pos]=j;
		}
		for (int i=n;i>=1;i--){
			ans+=sum(a[i]-1);
			plus(a[i],1);
		}
		printf("%lld",ans);
		b=1;
		for (int i=1;i<=MAXN;i++)num[i]=0;
	}
	return 0;
}

