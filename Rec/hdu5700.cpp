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
int n,k,m,a[N];
LL ssum[N],max;
struct aa{
	int l,r;
}poi[N];
bool cmp(aa a,aa b){return (a.l<b.l||(a.l==b.l&&a.r<b.r));}
int sum(int x){
	int num=0;
	while (x){
		num+=a[x];
		x-=x&(-x);
	}
	return num;
}
void plus(int x,int v){
	while (x<=n){
		a[x]+=v;
		x+=x&(-x);
	}
}
bool check(int x){
	if (sum(x)>=k)return 1;
	else return 0;
}
int main(){
	freopen("hdu5700.in","r",stdin);
	freopen("hdu5700.out","w",stdout);
	while (scanf("%d%d%d",&n,&k,&m)!=EOF){
		memset(a,0,sizeof(a));
		max=0;
	    for (int i=1;i<=n;i++){
		  LL x;
		  scanf("%lld",&x);
		  ssum[i]=ssum[i-1]+x;
	    }
	 	for (int i=1;i<=m;i++)scanf("%d%d",&poi[i].l,&poi[i].r);
		std::sort(poi+1,poi+m+1,cmp);
		for (int i=1;i<=m;i++){
			plus(poi[i].l,1);
			plus(poi[i].r+1,-1);
			int L=poi[i].l;int R=n;
			int ans=0;
			while (L<=R){
				int mid=(L+R)/2;
				if (check(mid)){
					ans=mid;
					L=mid+1;
				}else R=mid-1;
			}
			if (ans>=poi[i].l)max=std::max(max,ssum[ans]-ssum[poi[i].l-1]);
		}
		printf("%lld\n",max);
	}
	return 0;
}
