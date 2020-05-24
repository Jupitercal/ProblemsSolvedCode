#include<bits/stdc++.h>
#define N 100005
int n,a[N],tree[N*20],lc[N*20],rc[N*20],s[N],tou[N],dd,ans[N],nn;
int rt[N*20],T;
struct aa{
	int p,next;
}da[N*3];
void add(int x,int y){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;
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
int query(int root, int l, int r, int x) {
	//if (x==0)return 0;
    if(!root) return 0;
    if(l>= x) return tree[root];
    int ans = 0;
    int mid = (l + r)/2;
    if(mid>=x) ans += query(lc[root], l, mid, x) ;
    ans += query(rc[root], mid + 1, r, x) ;
    return ans ;
}
int merge(int x, int y) {
    if(!x) return y;
    if(!y) return x;
    lc[x] = merge(lc[x], lc[y]) ;
    rc[x] = merge(rc[x], rc[y]) ;
    tree[x] = tree[lc[x]] + tree[rc[x]] ;
    return x;
}
void dfs(int x){
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		dfs(v);
		rt[x]=merge(rt[x],rt[v]);
	}
	ans[x]=query(rt[x],1,nn,s[x]+1);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	#endif
	scanf("%d",&n);
	T=0;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),s[i]=a[i];
	std::sort(a+1,a+n+1);
	nn=std::unique(a+1,a+n+1)-a-1;
	for (int i=2;i<=n;i++){
		int x;
		scanf("%d",&x);
		add(x,i);
	}
	for (int i=1;i<=n;i++){
		s[i]=std::lower_bound(a+1,a+n+1,s[i])-a;
	}
	for (int i=1;i<=n;i++)insert(rt[i],1,nn,s[i]);
	dfs(1);
	for (int i=1;i<=n;i++)printf("%d\n",ans[i]);
	return 0;
}