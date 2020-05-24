#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <ctime>
#include <vector>
#define Ll long long
#define Ld long double
using namespace std;
const int N = 50000 * 8 + 10;
struct P{
    int num[3],is_q,tag;
    void make(int n_1,int n_2,int n_3,int n_4,int n_5){
        num[0] = n_1, num[1] = n_2, num[2] = n_3, is_q = n_4, tag = n_5;
    }
}tem[4][N], q[4][N], p[4][N], rem[N];
int CMP, ans[N];
bool cmp(const P &p1,const P &p2){
    return p1.num[CMP] < p2.num[CMP];
}
void solve(int l,int r,int x){
    if(x == 3){
        int cnt = 0;
        for(int i = l; i <= r; i++)
            if(tem[x][i].is_q)
                ans[tem[x][i].is_q] += cnt * tem[x][i].tag;
            else
                ++cnt;
        return ;
    }
    if(l >= r) return ;
    int mid = (l + r) / 2, p_num = 0, q_num = 0;
    solve(l, mid, x); 
    solve(mid + 1, r, x);
    for(int i = l; i <= mid; i++)
        if(!tem[x][i].is_q)
            p[x][++p_num] = tem[x][i];
    for(int i = mid + 1; i <= r; i++)
        if(tem[x][i].is_q)
            q[x][++q_num] = tem[x][i];
    int cnt = 0;
    if(p_num > 0 && q_num > 0){
        for(int i = 1, j = 1; i <= p_num || j <= q_num; ){
            if(i <= p_num && (j > q_num || p[x][i].num[x] <= q[x][j].num[x]))
                tem[x + 1][++cnt] = p[x][i], ++i;
            else
                tem[x + 1][++cnt] = q[x][j], ++j;
        }
        CMP=x+1;
        std::sort(tem[x+1]+1,tem[x+1]+cnt+1,cmp);
        solve(1,cnt,x + 1);
    }
    cnt = l - 1;
    for(int i = l, j = mid + 1; i <= mid || j <= r;){
        if(i <= mid && (j > r || tem[x][i].num[x] <= tem[x][j].num[x]))
            rem[++cnt] = tem[x][i], ++i;
        else
            rem[++cnt] = tem[x][j], ++j;
    }
    for(int i = l; i <= r; i++) tem[x][i] = rem[i];
}
int main(){ 
    int Case;  
    scanf("%d",&Case);   
    while(Case--){
        int cnt = 0, n, Q = 0;
        scanf("%d",&n);
        for(int i = 1; i <= n; i++){
            int flag;
            scanf("%d",&flag);
            if(flag == 1){
                ++cnt;
                for(int j = 0; j < 3; j ++)
                    scanf("%d",&tem[0][cnt].num[j]);
                tem[0][cnt].tag = tem[0][cnt].is_q = 0;
            }
            if(flag == 2){
                int minx, miny, minz, maxx, maxy, maxz;
                scanf("%d%d%d%d%d%d", &minx, &miny, &minz, &maxx, &maxy, &maxz);  
                ++Q;                
                tem[0][++cnt].make(maxx, maxy, maxz, Q, 1);                
                tem[0][++cnt].make(minx - 1, maxy, maxz, Q, -1);
                tem[0][++cnt].make(maxx, miny - 1, maxz, Q, -1);
                tem[0][++cnt].make(maxx, maxy, minz - 1, Q, -1);                
                tem[0][++cnt].make(maxx, miny - 1, minz - 1, Q, 1);
                tem[0][++cnt].make(minx - 1, maxy, minz - 1, Q, 1);
                tem[0][++cnt].make(minx - 1, miny - 1, maxz, Q, 1);               
                tem[0][++cnt].make(minx - 1, miny - 1, minz - 1, Q, -1);
            }
        }
        for(int i = 1; i <= Q; i++) ans[i] = 0;       
        solve(1,cnt,0);      
        for(int i = 1; i <= Q; i++) printf("%d\n", ans[i]);
    }
    return 0;
} 
