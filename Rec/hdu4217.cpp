#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300005;

int ch[N][2], par[N], val[N], cnt[N], size[N], ncnt, root;
int T;

bool chk(int x) {
    return ch[par[x]][1] == x;
}

void pushup(int x) {
    size[x] = size[ch[x][0]] + size[ch[x][1]] + cnt[x];
}

void rotate(int x) {
    int y = par[x], z = par[y], k = chk(x), w = ch[x][k^1];
    ch[y][k] = w; par[w] = y;
    ch[z][chk(y)] = x; par[x] = z;
    ch[x][k^1] = y; par[y] = x;
    pushup(y); pushup(x);
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

void insert(int x) {
    int cur = root, p = 0;
    while (cur && val[cur] != x) {
        p = cur;
        cur = ch[cur][x > val[cur]];
    }
    if (cur) {
        cnt[cur]++;
    } else {
        cur = ++ncnt;
        if (p) ch[p][x > val[p]] = cur;
        ch[cur][0] = ch[cur][1] = 0;
        par[cur] = p; val[cur] = x;
        cnt[cur] = size[cur] = 1;
    }
    splay(cur);
}

void find(int x) {
    int cur = root;
    while (ch[cur][x > val[cur]] && x != val[cur]) {
        cur = ch[cur][x > val[cur]];
    }
    splay(cur);
}

int kth(int k) {
    int cur = root;
    while (1) {
        if (ch[cur][0] && k <= size[ch[cur][0]]) {
            cur = ch[cur][0];
        } else if (k > size[ch[cur][0]] + cnt[cur]) {
            k -= size[ch[cur][0]] + cnt[cur];
            cur = ch[cur][1];
        } else {
            splay(cur);
            return cur;
        }
    }
}

int pre(int x) {
    //find(x);
    if (val[root] < x) return root;
    int cur = ch[root][0];
    while (ch[cur][1]) cur = ch[cur][1];
    return cur;
}

int succ(int x) {
   // find(x);
    if (val[root] > x) return root;
    int cur = ch[root][1];
    while (ch[cur][0]) cur = ch[cur][0];
    return cur;
}

void remove(int x) {
    int last = pre(x), next = succ(x);
    splay(last); splay(next, last);
    int del = ch[next][0];
    if (cnt[del] > 1) {
        cnt[del]--;
        splay(del);
    }
    else ch[next][0] = 0, pushup(next), pushup(root);
}

int n, op, x,k;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    scanf("%d",&T);
    int cases=0;
    while (T--){
        scanf("%d%d", &n,&k);
       for (int i=0;i<=ncnt;i++){
            par[i]=0;
            ch[i][0]=ch[i][1]=0;
            size[i]=0;
            val[i]=0;
            cnt[i]=0;
       }
        ncnt=0;
        root=0;
        insert(-0x3f3f3f3f);
        for (int i=1;i<=n;i++)insert(i);
        insert(0x3f3f3f3f);
        LL ans=0;
        for (int i=1;i<=k;i++){
            int x;
            scanf("%d",&x);
            int m=val[kth(x+1)];
            ans+=m;
            remove(m);
        }
        ++cases;
        printf("Case %d: %lld\n",cases,ans);
    }
    return 0;
}