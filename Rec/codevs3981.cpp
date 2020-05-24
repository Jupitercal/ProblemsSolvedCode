#include<bits/stdc++.h>
typedef long long LL;
#define N 200005
int n;
LL a[N];
struct node{
	LL Lmax,Rmax,max,sum;
}tree[N*4];
void clac(node &u,node ls,node rs){
	u.max=std::max(std::max(ls.max,rs.max),ls.Rmax+rs.Lmax);
	u.Lmax=std::max(ls.Lmax,ls.sum+rs.Lmax);
	u.Rmax=std::max(rs.Rmax,ls.Rmax+rs.sum);
	u.sum=ls.sum+rs.sum;
}
void build (int rt,int l,int r){
	if (l==r){
		tree[rt].Lmax=tree[rt].Rmax=tree[rt].max=tree[rt].sum=a[l];
		return;
	}
	int mid=(l+r)/2;
	if (l<=mid)build(rt*2,l,mid);
	if (mid<r)build(rt*2+1,mid+1,r);
	clac(tree[rt],tree[rt*2],tree[rt*2+1]);
}
node query(int rt,int l,int r,int ls,int rs){
	if (ls<=l&&r<=rs)return tree[rt];
	int mid=(l+r)/2;
	if (rs<=mid)return query(rt*2,l,mid,ls,rs);
	if (ls>mid)return query(rt*2+1,mid+1,r,ls,rs);
	node u;
	node L=query(rt*2,l,mid,ls,rs);
	node R=query(rt*2+1,mid+1,r,ls,rs);
	clac(u,L,R);
	return u;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	build (1,1,n);
	int q;
	scanf("%d",&q);
	while (q--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%lld\n",query(1,1,n,l,r).max);
	}
	return 0;
}