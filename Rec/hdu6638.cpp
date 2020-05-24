#include<bits/stdc++.h>
#define N 3000
typedef long long LL;
std::map<int,int>mp;
struct aa{
	LL lsum,rsum,sum,ans;
}tree[N*10];
struct b{
	int x,y;
	LL w;
}poi[N];
int T,n,y[N];
void clac(int x,int l,int r){
	tree[x].lsum=std::max(tree[x*2].lsum,tree[x*2].sum+tree[x*2+1].lsum);
	tree[x].rsum=std::max(tree[x*2+1].rsum,tree[x*2+1].sum+tree[x*2].rsum);
	tree[x].sum=tree[x*2].sum+tree[x*2+1].sum;
	tree[x].ans=std::max(tree[x*2].ans,tree[x*2+1].ans);
	tree[x].ans=std::max(tree[x].ans,tree[x*2].rsum+tree[x*2+1].lsum);
	tree[x].ans=std::max(tree[x].ans,tree[x].lsum);
	tree[x].ans=std::max(tree[x].ans,tree[x].rsum);
}
void build(int x,int l,int r){
	if (l>r)return ;
	if (l==r){
		tree[x].lsum=tree[x].rsum=tree[x].sum=0;
		tree[x].ans=0;
		return ;
	}
	int mid=(l+r)/2;
	if (l<=mid)build(x*2,l,mid);
	if (mid<r)build(x*2+1,mid+1,r);
	clac(x,l,r);
}
void insert(int rt,int l,int r,int x,LL v){
	if (l>r)return;
	if (l==r){
		tree[rt].lsum+=v;
		tree[rt].rsum+=v;
		tree[rt].sum+=v;
		tree[rt].ans+=v;
		return ;
	}
	int mid=(l+r)/2;
	if (x<=mid)insert(rt*2,l,mid,x,v);
	if (mid<x)insert(rt*2+1,mid+1,r,x,v);
	clac(rt,l,r);
}
bool cmp(b a,b b){
	return (a.x<b.x)||(a.x==b.x&&a.y<b.y);
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		mp.clear();
		for (int i=1;i<=n;i++){
			scanf("%d%d%lld",&poi[i].x,&poi[i].y,&poi[i].w);
			y[i]=poi[i].y;

		}
		y[0]=-253131515;
		std::sort(y+1,y+n+1);
		int p=0;
		for (int i=1;i<=n;i++){
			if (y[i]!=y[i-1])p++;
			mp[y[i]]=p;
		}
		std::sort(poi+1,poi+n+1,cmp);
		//for (int i=1;i<=n;i++)printf("%d %d %lld %d\n",poi[i].x,poi[i].y,poi[i].w,mp[poi[i].y]);
		LL ans=0;
		for (int i=1;i<=n;i++){
			build(1,1,n*2);
			//printf("%lld\n",tree[1].ans);
			if (poi[i].x==poi[i-1].x)continue;
			for (int j=i;j<=n;j++){
				if (poi[j].x!=poi[j-1].x){
					ans=std::max(tree[1].ans,ans);
				//	printf("%d %d %lld\n",i,j,tree[1].ans);
				}
				insert(1,1,n,mp[poi[j].y],poi[j].w);
				//ans=std::max(tree[1].ans,ans);
			}
			ans=std::max(tree[1].ans,ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}