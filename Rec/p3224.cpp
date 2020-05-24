#include<bits/stdc++.h>
#define N 100005
int fa[N],rt[N*20],lc[N*20],T,n,m,rc[N*20],tree[N*20],a[N],b[N];
char s[30];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void insert(int &i, int l, int r, int x) {
    if(r<l) return ;
    i = ++T;
    if(l == r) {
        tree[i]++ ;
        return ;
    }
    int mid = (l + r)/2 ;
    if(x<=mid) insert(lc[i], l, mid, x) ;
    if(x>mid) insert(rc[i], mid + 1, r, x) ;
    tree[i] = tree[lc[i]] + tree[rc[i]] ;
}
int query(int root, int l, int r, int k) {
    int u=root;
    if (tree[u]<k)return -1;
    //k=tree[u]+1-k;
    while (l<r){
    	int mid=(l+r)/2;
    	//printf("%d %d\n",l,r);
    	if (tree[lc[u]]>=k){
    		r=mid;
    		u=lc[u];
    	}else{
    		k-=tree[lc[u]];
    		u=rc[u];
    		l=mid+1;
    	}
    }
    return l;
}
int merge(int x, int y) {
    if(!x) return y;
    if(!y) return x;
    tree[x] += tree[y] ;
    lc[x] = merge(lc[x], lc[y]) ;
    rc[x] = merge(rc[x], rc[y]) ;
    //tree[x] = tree[lc[x]] + tree[rc[x]] ;
    return x;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)fa[i]=i;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),insert(rt[i],1,n,a[i]),b[a[i]]=i;
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int fx=find(fa[x]);
		int fy=find(fa[y]);
		if (fx!=fy){
			fa[fy]=fx;
			rt[fx]=merge(rt[fx],rt[fy]);
		}
	}
	int q;
	scanf("%d",&q);
	while (q--){
		scanf("%s",s);
		if (s[0]=='B'){
			int x,y;
			scanf("%d%d",&x,&y);
			int fx=find(x);
			int fy=find(y);
			if (fx!=fy){
				fa[fy]=fx;
				rt[fx]=merge(rt[fx],rt[fy]);
			}
		}else{
			int x,k;
			scanf("%d%d",&x,&k);
			int fx=find(x);
			int tx=query(rt[fx],1,n,k);
			if (tx!=-1)printf("%d\n",b[tx]);
			else printf("%d\n",tx);
		}
	}
	return 0;
}