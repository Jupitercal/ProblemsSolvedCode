#include<bits/stdc++.h>
#define N 200005
typedef long long LL;
int n,T,lc[N*20],rc[N*20],rt[N*20],t;
LL sum1,sum2,ans,tree[N*20];
void insert(int &i, int l, int r, int x){
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
int merge(int x, int y) {
    if(!x) return y;
    if(!y) return x;
    tree[x] += tree[y] ;
    sum1+=1LL*tree[lc[x]]*tree[rc[y]];
    sum2+=1LL*tree[lc[y]]*tree[rc[x]];
    lc[x] = merge(lc[x], lc[y]) ;
    rc[x] = merge(rc[x], rc[y]) ;
    //tree[x] = tree[lc[x]] + tree[rc[x]] ;
    return x;
}
void dfs(int &p){
	int x,ls,rs;
	int xt=t;
	++t;
	scanf("%d",&x);
	if (!x){
		dfs(ls);dfs(rs);
		sum1=sum2=0;
		rt[xt]=merge(ls,rs);
		ans+=std::min(sum1,sum2);
	}else insert(rt[xt],1,n,x);
	p=rt[xt];
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	#endif
	t=0;
	scanf("%d",&n);
	dfs(rt[0]);
	printf("%lld\n",ans);
	//printf("%d",t);
	return 0;
}