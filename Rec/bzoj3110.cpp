#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 210000
int n,m;
struct nod{
	int sum,tag;
}tree[N*2];
struct aa{
	int x,y,c,pos;
	bool op;
}poi[N],tm1[N],tm2[N];
int bel[N],anx,ans[N],mx[N],qx;
bool cmp(int x,int y){return x>y;}
void pushdown(int x,int l,int r){
	if (tree[x].tag!=0){
		int mid=(l+r)/2;
		tree[x*2].sum+=tree[x].tag*(mid-l+1);tree[x*2+1].sum+=tree[x].tag*(r-mid);
		tree[x*2].tag+=tree[x].tag;tree[x*2+1].tag+=tree[x].tag;tree[x].tag=0;
	}
}
void clac(int x){tree[x].sum=tree[x*2].sum+tree[x*2+1].sum;}
int ask(int rt,int l,int r,int ls,int rs){
	if (l>r)return 0;
	if (l==r)return tree[rt].sum;
	pushdown(rt,l,r);
	if (ls<=l&&r<=rs)return tree[rt].sum;
	int mid=(l+r)/2;
	int m=0;
	if (ls<=mid)m+=ask(rt*2,l,mid,ls,rs);
	if (mid<rs)m+=ask(rt*2+1,mid+1,r,ls,rs);
	return m;
}
void insert(int rt,int l,int r,int ls,int rs,int v){
	if (l>r)return ;
	if (l==r){
		tree[rt].sum+=v;
		tree[rt].tag+=v;
		return ;
	}
	pushdown(rt,l,r);
	if (ls<=l&&r<=rs){		
		tree[rt].tag+=v;
		tree[rt].sum+=(r-l+1)*v;
		return ;
	}
	int mid=(l+r)/2;
	if (ls<=mid)insert(rt*2,l,mid,ls,rs,v);
	if (mid<rs)insert(rt*2+1,mid+1,r,ls,rs,v);
	clac(rt);
}
//----------------------------------------------------------------------------------------------------------Seg Tree
void solve(int l,int r,int ll,int rr){
	if (ll>rr)return;
	if (l==r){
		for (int i=ll;i<=rr;i++)if (!poi[i].op)ans[bel[poi[i].pos]]=mx[l];
		return ;
	}
	int m1=(l+r)/2;
	int l1=0;int l2=0;
	for (int i=ll;i<=rr;i++){
		if (poi[i].op){
			if (poi[i].c>=mx[m1])insert(1,1,n,poi[i].x,poi[i].y,1),tm1[++l1]=poi[i];
				else tm2[++l2]=poi[i];
		}else
		if (!poi[i].op){
			int num=ask(1,1,n,poi[i].x,poi[i].y);
			if (num>=poi[i].c)tm1[++l1]=poi[i];
			else poi[i].c-=num,tm2[++l2]=poi[i];
		}
	}
	for (int i=ll;i<=rr;i++)
		if (poi[i].op)
			if (poi[i].c>=mx[m1])insert(1,1,n,poi[i].x,poi[i].y,-1);
	for (int i=ll;i<=ll+l1-1;i++)poi[i]=tm1[i-ll+1];
	for (int i=ll+l1;i<=rr;i++)poi[i]=tm2[i-l1-ll+1];
	solve(l,m1,ll,l1+ll-1);
	solve(m1+1,r,l1+ll,rr);
}
//----------------------------------------------------------------------------------------------------------CDQ
int main(){
	freopen("bzoj3110.in","r",stdin);
	freopen("bzoj3110.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int o,x,y,a;
		scanf("%d%d%d%d",&o,&x,&y,&a);
		poi[i].pos=i;poi[i].x=x;poi[i].y=y;poi[i].c=a;
		if (o==1)poi[i].op=1,mx[++qx]=a;
		else poi[i].op=0,bel[i]=++anx;
	}
	std::sort(mx+1,mx+qx+1,cmp);
	solve(1,qx,1,m);
	for (int i=1;i<=anx;i++)printf("%d\n",ans[i]);
	return 0;
}