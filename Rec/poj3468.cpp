#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define N 400000
typedef long long LL;
int n,m;
LL tr[N],tag[N],a[N];
char s[300];
void pushdown(int x,int l,int r){
	if (tag[x]){
		int mid=(l+r)/2;
		tag[x*2]+=tag[x];
		tag[x*2+1]+=tag[x];
		tr[x*2]+=(mid-l+1)*tag[x];
		tr[x*2+1]+=(r-mid)*tag[x];
		tag[x]=0;
	}
}
void update(int x){tr[x]=tr[x*2]+tr[x*2+1];}
void build(int x,int l,int r){
	if (l==r){
		tr[x]=a[l];
		tag[x]=0;
		return ;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	tr[x]=tr[x*2]+tr[x*2+1];
}
LL sum(int x,int l,int r,int lx,int rx){
	if (l==r)return tr[x];
	pushdown(x,l,r);
	if (lx<=l&&r<=rx)return tr[x];
	int mid=(l+r)/2;
	LL tot=0;
	if (lx<=mid)tot+=sum(x*2,l,mid,lx,rx);
	if (mid<rx)tot+=sum(x*2+1,mid+1,r,lx,rx);
	update(x);
	return tot;
}
void clac(int x,int l,int r,int lx,int rx,int c){
	if (l==r){
		tr[x]+=c;
		tag[x]+=c;
		return; 
	}
	pushdown(x,l,r);
	if (lx<=l&&r<=rx){
		tag[x]+=c;
		tr[x]+=c*(r-l+1);
		return;
	}
	int mid=(l+r)/2;
	if (lx<=mid)clac(x*2,l,mid,lx,rx,c);
	if (mid<rx)clac(x*2+1,mid+1,r,lx,rx,c);
	update(x);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("xx.in","r",stdin);
	freopen("xx.out","w",stdout);
	#endif
	while (scanf("%d%d",&n,&m)!=EOF){
	  for (int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	  build (1,1,n);
	  for (int i=1;i<=m;i++){
		  scanf("%s",s);
	 	  if (s[0]=='Q'){
			  int l,r;
			  scanf("%d%d",&l,&r);
			  printf("%I64d\n",sum(1,1,n,l,r));
		  }else {
			  int l,r,c;
			  scanf("%d%d%d",&l,&r,&c);
			  clac(1,1,n,l,r,c);
		  }
	  }
    }
	return 0;
}
