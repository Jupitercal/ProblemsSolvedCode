#include<bits/stdc++.h>
using namespace std;
#define N 30005
int fa[N],top[N],siz[N],size,son[N],pos[N],n,m,deep[N],tag[N*4];
int tou[N],dd,ans[N];
int tree[N*4];
map<int,int>mp;
struct aa{
    int p,next;
    bool ok;
}da[200005];
struct qa{
    int u,v,op;
}Q[N];
void dfs(int x){
    siz[x]=1;
    for (int i=tou[x];i;i=da[i].next){
        int v=da[i].p;
        if (!siz[v]&&!da[i].ok){
            fa[v]=x;
            deep[v]=deep[x]+1;
            dfs(v);
            siz[x]+=siz[v];
            if (siz[v]>siz[son[x]])son[x]=v;
        }
    }
}
void dfs1(int x,int tp){
    pos[x]=++size;top[x]=tp;
    if (son[x])dfs1(son[x],tp);
    for (int i=tou[x];i;i=da[i].next){
        int v=da[i].p;
        if (v!=fa[x]&&v!=son[x]&&!da[i].ok&&fa[v]==x)dfs1(v,v);
    }
}
void add(int x,int y){
    da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;
    mp[x*(n+1)+y]=dd;
}
void clac(int x){
    tree[x]=tree[x*2]+tree[x*2+1];
}
void pushdown(int x,int l,int r){
    if (tag[x]){
        tree[x*2]=tree[x*2+1]=0;
        tag[x*2]=tag[x*2+1]=1;
        tag[x]=0;
    }
}
void ins(int x,int l,int r,int ls,int rs){
    if (l==r){
        tree[x]=0;
        tag[x]=1;
        return;
    }
    pushdown(x,l,r);
    if (ls<=l&&r<=rs){
        tag[x]=1;
        tree[x]=0;
        return;
    }
    int mid=(l+r)/2;
    if (ls<=mid)ins(x*2,l,mid,ls,rs);
    if (mid<rs)ins(x*2+1,mid+1,r,ls,rs);
    clac(x);
}
int query(int x,int l,int r,int ls,int rs){
    if (l==r)return tree[x];
    pushdown(x,l,r);
    if (ls<=l&&r<=rs)return tree[x];
    int mid=(l+r)/2;
    int mm=0;
    if (ls<=mid)mm+=query(x*2,l,mid,ls,rs);
    if (mid<rs)mm+=query(x*2+1,mid+1,r,ls,rs);
    return mm;
}
void modify(int x,int y){
    for (;top[x]!=top[y];x=fa[top[x]]){
        if (deep[top[x]]<deep[top[y]])std::swap(x,y);
        ins(1,1,n,pos[top[x]],pos[x]);
    }
    if (pos[x]>pos[y])std::swap(x,y);
    if (pos[x]+1<=pos[y]){
        ins(1,1,n,pos[x]+1,pos[y]);
    }
}
int  work(int x,int y){
    int mm=0;
    for (;top[x]!=top[y];x=fa[top[x]]){
        if (deep[top[x]]<deep[top[y]])std::swap(x,y);
        mm+=query(1,1,n,pos[top[x]],pos[x]);
    }
    if (pos[x]>pos[y])std::swap(x,y);
    if (pos[x]+1<=pos[y]){
        mm+=query(1,1,n,pos[x]+1,pos[y]);
    }
    return mm;
}
void dfs2(int x){
    for (int i=tou[x];i;i=da[i].next){
        int v=da[i].p;
        if (da[i].ok)continue;
        if (fa[v]==x)dfs2(v);
        if (fa[v]!=x&&deep[v]<deep[x]&&v!=fa[x]){
            modify(x,v);
            //printf("%d %d\n",x,v);
        }
    }
}
void build(int x,int l,int r){
    if (l>r)return;
    if (l==r){
        tree[x]=1;
        tag[x]=0;
        return;
    }
    int mid=(l+r)/2;
    if (l<=mid)build(x*2,l,mid);
    if (mid<r)build(x*2+1,mid+1,r);
    clac(x);
}
int main(){
    //#ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    //#endif 
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
        int u,v;
    	scanf("%d%d",&u,&v);
    	add(u,v);
    	add(v,u);
    }
    int c,a,b;
    int asks=0;
    while (1){
        scanf("%d",&c);
        if (c==-1)break;
        scanf("%d%d",&a,&b);
        Q[++asks].u=a;Q[asks].v=b;Q[asks].op=c;
        if (c==0){
            da[mp[a*(n+1)+b]].ok=1;
            da[mp[b*(n+1)+a]].ok=1;
        }
    }
    dfs(1);
    dfs1(1,1);
    build(1,1,n);
    //printf("%d\n",tree[1]);
    dfs2(1);
    for (int i=asks;i>=1;i--){
        if (Q[i].op==0){
            modify(Q[i].u,Q[i].v);
        }else{
            ans[i]=work(Q[i].u,Q[i].v);
        }
    }
    for (int i=1;i<=asks;i++){
        if (Q[i].op)printf("%d\n",ans[i]);
    }
    return 0;
}