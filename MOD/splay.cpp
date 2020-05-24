#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int ch[N][2], par[N], val[N], cnt[N], size[N], ncnt, root;

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
            return cur;
        }
    }
}

int pre(int x) {
    find(x);
    if (val[root] < x) return root;
    int cur = ch[root][0];
    while (ch[cur][1]) cur = ch[cur][1];
    return cur;
}

int succ(int x) {
    find(x);
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

int n, op, x;

int main() {
    scanf("%d", &n);
    insert(0x3f3f3f3f);
    insert(0xcfcfcfcf);
    while (n--) {
        scanf("%d%d", &op, &x);
        switch (op) {
            case 1: insert(x); break;
            case 2: remove(x); break;
            case 3: find(x); printf("%d\n", size[ch[root][0]]); break;
            case 4: printf("%d\n", val[kth(x+1)]); break;
            case 5: printf("%d\n", val[pre(x)]); break;
            case 6: printf("%d\n", val[succ(x)]); break;
        }
    }
}

//--------------------------------------------------´ø·­×ªtag
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int ch[N][2], par[N], val[N], cnt[N], size[N], rev[N], root, ncnt;
int n, m, x, y;

bool chk(int x) {
    return ch[par[x]][1] == x;
}

void pushup(int x) {
    size[x] = size[ch[x][0]] + size[ch[x][1]] + cnt[x];
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
    while (ch[cur][x > val[cur]] && val[cur] != x) {
        cur = ch[cur][x > val[cur]];
    }
    splay(cur);
}

int kth(int k) {
    int cur = root;
    while (1) {
        pushdown(cur);
        if (ch[cur][0] && k <= size[ch[cur][0]]) {
            cur = ch[cur][0];
        } else if (k > size[ch[cur][0]] + cnt[cur]) {
            k -= size[ch[cur][0]] + cnt[cur];
            cur = ch[cur][1];
        } else {
            return cur;
        }
    }
}

void reverse(int l, int r) {
    int x = kth(l), y = kth(r+2);
    splay(x); splay(y, x);
    rev[ch[y][0]] ^= 1;
}

int pre(int x) {
    find(x);
    if (val[root] < x) return root;
    int cur = ch[root][0];
    while (ch[cur][1]) cur = ch[cur][1];
    return cur;
}

int succ(int x) {
    find(x);
    if (val[root] > x) return root;
    int cur = ch[root][1];
    while (ch[cur][0]) cur = ch[cur][0];
    return cur;
}

void output(int x) {
    pushdown(x);
    if (ch[x][0]) output(ch[x][0]);
    if (val[x] && val[x] <= n) printf("%d ", val[x]);
    if (ch[x][1]) output(ch[x][1]);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n+1; i++) insert(i);
    while (m--) {
        scanf("%d%d", &x, &y);
        reverse(x, y);
    }
    output(root);
}