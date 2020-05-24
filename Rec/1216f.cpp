#include<bits/stdc++.h>
#define N 200005
typedef long long LL;
LL tree[N*4],tag[N*4];
char s[N];
int n,k;
void pushdown(int rt,int l,int r){
	if (tag[rt]!=1e18){
		tag[rt*2]=std::min(tag[rt*2],tag[rt]);
		tag[rt*2+1]=std::min(tag[rt*2+1],tag[rt]);
		tree[rt*2]=std::min(tree[rt*2],tag[rt]);
		tree[rt*2+1]=std::min(tree[rt*2+1],tag[rt]);
		tag[rt]=1e18;
	}
}
void build(int rt,int l,int r){
	if (l>r)return ;
	if (l==r){
		tree[rt]=1e18;
		tag[rt]=1e18;
		return ;
	}
	int mid=(l+r)/2;
	if (l<=mid)build(rt*2,l,mid);
	if (mid<r)build(rt*2+1,mid+1,r);
	tree[rt]=std::min(tree[rt*2],tree[rt*2+1]);
	tag[rt]=1e18;
}
void update(int rt,int l,int r,int ls,int rs,LL v){
	if (l==r){
		tree[rt]=std::min(tree[rt],v);
		tag[rt]=std::min(tag[rt],v);
		return ;
	}
	pushdown(rt,l,r);
	if (ls<=l&&r<=rs){
		tree[rt]=std::min(tree[rt],v);
		tag[rt]=std::min(tag[rt],v);
		return;
	}
	int mid=(l+r)/2;
	if (ls<=mid)update(rt*2,l,mid,ls,rs,v);
	if (mid<rs)update(rt*2+1,mid+1,r,ls,rs,v);
	tree[rt]=std::min(tree[rt*2],tree[rt*2+1]);
}
LL query(int rt,int l,int r,int ls,int rs){
	if (l==r)return tree[rt];
	pushdown(rt,l,r);
	if (ls<=l&&r<=rs)return tree[rt];
	int mid=(l+r)/2;
	LL m=1e18;
	if (ls<=mid)m=std::min(m,query(rt*2,l,mid,ls,rs));
	if (mid<rs)m=std::min(m,query(rt*2+1,mid+1,r,ls,rs));
	tree[rt]=std::min(tree[rt*2],tree[rt*2+1]);
	return m;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	#endif
	//memset(F,0x3f3f3f3f,sizeof(F));
	//F[0]=0;
	//printf("%d\n",0x7f7f7f7f);
	scanf("%d%d",&n,&k);
	build(1,1,n+1);
	update(1,1,n+1,1,1,0);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++){
		if (s[i]=='0'){
			//F[i]=std::min(F[i],F[i-1]+i);
			LL m=query(1,1,n+1,i,i)+i;
			update(1,1,n+1,i+1,i+1,m);
		}else{
			int L=std::max(1,i-k);
			int R=std::min(n,i+k);
			LL m=query(1,1,n+1,L,R)+i;
			update(1,1,n+1,L+1,R+1,m);
		}
	}
	printf("%lld\n",query(1,1,n+1,n+1,n+1));
	return 0;
}