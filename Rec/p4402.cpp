#include <bits/stdc++.h>
using namespace std;

const int N = 220005;

int ch[N][2], par[N], size[N], rev[N], root, ncnt;
int n, ans[N];
stack<int>s;
struct aa{
    int x,id;
}poi[N];
bool chk(int x) {
    return ch[par[x]][1] == x;
}

void pushup(int x) {
    size[x] = size[ch[x][0]] + size[ch[x][1]] + 1;
}

void pushdown(int x) {
    if (rev[x])  {
        swap(ch[x][0], ch[x][1]);
        rev[ch[x][0]] ^= 1;
        rev[ch[x][1]] ^= 1;
        rev[x] = 0;
    }
}

void rotate(int x) {
    int y = par[x], z = par[y], k = chk(x), w = ch[x][k^1];
    pushdown(y);pushdown(x);
    ch[y][k] = w; par[w] = y;
    ch[z][chk(y)] = x; par[x] = z;
    ch[x][k^1] = y; par[y] = x;
    pushup(x); pushup(y); 
}

void splay(int x, int goal = 0) {
    while (par[x] != goal) {
        int y = par[x], z = par[y];
        if (z != goal) {
            if (chk(x) == chk(y)) rotate(y);
            else rotate(x);
        }
        rotate(x);
    }
    if (!goal) root = x;
}
int build(int l,int r,int root){
    int now=(l+r)/2;
    par[now]=root;
    if (l<now)ch[now][0]=build(l,now-1,now);
    if (now<r)ch[now][1]=build(now+1,r,now);
    pushup(now);
    //printf("g %d %d l:%d r:%d\n",now,size[now],ch[now][0],ch[now][1]);
    return now;
}
bool cmp(aa a,aa b){
    return (a.x<b.x)||(a.x==b.x&&a.id<b.id);
}
void solve(int x){
    //return ;
    int tx=x;
    while (!s.empty())s.pop();
    while (x){
        s.push(x);
        x=par[x];
        //printf("%d %d\n",x,par[x]);
    }
    while (!s.empty()){
        int u=s.top();
        pushdown(u);
        s.pop();
    }
    splay(tx);
}
int find(int x) {
    int cur = root;
    while (1){
        pushdown(cur);
        if (ch[cur][0] && size[ch[cur][0]]>=x){
            cur=ch[cur][0];
        }else{
            if (ch[cur][0])x-=size[ch[cur][0]];
            x--;
            if (x<=0)return cur;
            cur=ch[cur][1];
        }
    }
    //return cur;
    //splay(cur);
}
void reverse(int l, int r) {
    int x = find(l), y = find(r);
    //printf("pos %d %d : %d %d\n",l,r,x,y);
    splay(x); splay(y, x);
   // printf("size %d %d %d\n",size[ch[y][0]],ch[y][0],ch[y][1]);
    rev[ch[y][0]] ^= 1;
}
int main() {
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&poi[i].x);
        poi[i].id=i;
    }
    std::sort(poi+1,poi+1+n,cmp);
    build(1,n+2,0);
    for (int i=1;i<=n;i++){
        solve(poi[i].id+1);
        ans[i]=size[ch[poi[i].id+1][0]];
        reverse(i,ans[i]+2);
    }
    for (int i=1;i<=n;i++)printf("%d ",ans[i]);
    return 0;
}