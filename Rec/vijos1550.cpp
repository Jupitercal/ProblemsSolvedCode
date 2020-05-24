#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#define INF 0x3f3f3f3f
#define N 20000 
struct aa{
	int p,next;
}da[N+5];
int F[N][3],m,n,c[N],tou[N],dd;
bool vis[N][3];
int dp(int x,int o,int fa){
	if (vis[x][o])return F[x][o];
	vis[x][o]=1;
	if (x<=n&&o!=c[x])return F[x][o]=1;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (v==fa)continue;
		F[x][o]+=std::min(dp(v,o,x),dp(v,!o,x)+1);
	}
	return F[x][o];
}
void add(int x,int y){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;
}
int main(){
	freopen("vijos1550.in","r",stdin);
	freopen("vijos1550.out","w",stdout);
	scanf("%d%d",&m,&n);
	for (int i=1;i<=n;i++)scanf("%d",&c[i]);
	for (int i=1;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	} 
	int ans=std::min(dp(n+1,0,0),dp(n+1,1,0))+1;
	printf("%d",std::min(dp(n+1,2,0),ans));
	return 0;
} 
