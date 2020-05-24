#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#define N 100005
#define prc(i) {printf("%d\n",i);continue;}
std::vector<int>e[N];
int root[N],lt[N*18],rt[N*18],s[N*18],fa[N][20],m,n,sz;
int L[N],R[N],c[N],deep[N];
void dfs(int x){
	L[x]=++sz;
	deep[x]=deep[fa[x][0]]+1;
	for (int i=1;i<=16;i++)fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int i=0;i<e[x].size();i++){
		int v=e[x][i];
		dfs(v);
	}
	R[x]=sz+1;
}
int lca(int u,int v){
	if (deep[u]<deep[v])std::swap(u,v);
	for (int i=16;i>=0;i--)
	  if (deep[u]-deep[v]>=1<<i)u=fa[u][i];
	if (u==v)return u;
	for (int i=16;i>=0;i--)
	  if (fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
	  }
	return fa[u][0];
}
int query(int x,int l,int r,int p){
	if (p==0)return 0;
	if (p==r)return s[x];
	int mid=(l+r)>>1;
	if (p<=mid)return query(lt[x],l,mid,p);
	else return s[lt[x]]+query(rt[x],mid+1,r,p);
}
int modify(int x,int l,int r,int p,int v){
	int now=++sz;int mid=(l+r)/2;
	lt[now]=lt[x];rt[now]=rt[x];
	s[now]=s[x]+v;
	if (l==r)return now;
	if (p<=mid)lt[now]=modify(lt[x],l,mid,p,v);
	else rt[now]=modify(rt[x],mid+1,r,p,v);
	return now;
}
int clac(int a,int b,int x,int y){
	x=fa[x][0];
	return deep[y]-deep[x]+query(root[b],1,n,L[y])-query(root[a],1,n,L[y])
	-query(root[b],1,n,L[x])+query(root[a],1,n,L[x]);
}
int solve(int a,int b,int c,int x,int k){
	for (int i=16;i>=0;i--){
		int t=fa[x][i];
		if (deep[t]>deep[c]){
			int T=clac(a,b,t,x);
			if (T<k)k-=T,x=fa[t][0]; 
		}
	}
	if (clac(a,b,x,x)<k)x=fa[x][0];
	return x;
}
int main(){
	scanf("%d",&n);
	int rot=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&fa[i][0]);
		if (fa[i][0])e[fa[i][0]].push_back(i);else rot=i;
	}
	dfs(rot);
	sz=0;
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		int t;
		scanf("%d",&t);
		if (t==1){
			int x;
			scanf("%d",&x);
			c[x]=i;
			root[i]=modify(root[i-1],1,n,L[x],1);
			if (R[x]<=n)root[i]=modify(root[i],1,n,R[x],-1);
		}else{
			int a,b,k,y;
			root[i]=root[i-1];	
			scanf("%d%d%d%d",&a,&b,&k,&y);
			k+=(c[a]<=y);
			int C=lca(a,b);
			int sup=clac(i,y,C,a);
			int sdn=clac(i,y,C,b);
			int sum=sup+sdn-(c[C]<=y);
			if (sum-(c[b]<=y)<k)prc(-1);
			if (sup>=k)prc(solve(i,y,C,a,k));
			prc(solve(i,y,C,b,sum-k+1));
		}
	}
	return 0;
}
