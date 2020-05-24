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
#define N 8005
#define range 8000
int n;
int vis[N*5],tree[N*20],ans[N*5];
void build(int x,int l,int r){
	if (l>r)return ;
	tree[x]=-1;
	if (l==r)return ;
	int mid=(l+r)/2;
	build(x*2,l,mid);build(x*2+1,mid+1,r);
}
void query(int x,int l,int r){
	if (tree[x]!=-1){
		for (int i=l;i<=r;i++)vis[i]=tree[x];
		return;
	}
	if (l>=r)return;
	int mid=(l+r)/2;
	query(x*2,l,mid);query(x*2+1,mid+1,r);
}
void pushdown(int x){
	if (tree[x]!=-1){
		tree[x*2]=tree[x*2+1]=tree[x];
		tree[x]=-1;
	}
}
void update(int x,int l,int r,int ls,int rs,int b){
	if (l>r)return;
	if (tree[x]==b)return;
	pushdown(x);
	if ((ls<=l&&r<=rs)||(l==r)){
		tree[x]=b;
		return ;
	}
	int mid=(l+r)/2;
	if (ls<=mid)update(x*2,l,mid,ls,rs,b);
	if (mid<rs)update(x*2+1,mid+1,r,ls,rs,b);
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		memset(vis,-1,sizeof(vis));
		memset(ans,0,sizeof(ans));
		build(1,1,range);
		for (int i=1;i<=n;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if (a>=b)continue;
			update(1,1,range,a+1,b,c);
		}
		query(1,1,range);
		int i=1;
		while (i<=range){
			int col=vis[i];
			int j=i+1;
			if (col==-1){i++;continue;}
			while (vis[j]==col&&j<=range)j++;
			++ans[col];
			i=j;
		}
		for (int i=0;i<=range;i++)
		  if (ans[i])printf("%d %d\n",i,ans[i]);
		printf("\n");
	}
	return 0;
}

