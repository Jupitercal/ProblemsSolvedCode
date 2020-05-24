#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#define N 2000
bool inq[N],vis[N][N];
int n,e,tou[N],dd,S,T,nx[N][N],dist[N];
double F[N][N]; 
std::queue<int> q;
struct aa{
	int p,next;
}da[N*6];
void spfa(int x){
	memset(dist,0x3f3f3f3f,sizeof(dist));
	inq[x]=1;
	dist[x]=0;
	nx[x][x]=x;
	q.push(x);
	while (!q.empty()){
		int u=q.front();q.pop();inq[u]=0;
		for (int i=tou[u];i;i=da[i].next){
			int v=da[i].p;
			if (dist[v]>dist[u]+1){
				dist[v]=dist[u]+1;
				nx[v][x]=u;
				if (!inq[v]){
					inq[v]=1;
					q.push(v);
				}
			}
			if (dist[v]==dist[u]+1&&u<nx[v][x])nx[v][x]=u;
		}
	}
	
} 
double dp(int s,int t){
	if (s==t)return 0;
	if (vis[s][t])return F[s][t];
	vis[s][t]=1;
	if (nx[s][t]==t||nx[nx[s][t]][t]==t)return F[s][t]=1;
	int rd=1;
	F[s][t]+=dp(nx[nx[s][t]][t],t);
	for (int i=tou[t];i;i=da[i].next){
		int v=da[i].p;
		F[s][t]+=dp(nx[nx[s][t]][t],v); 
		++rd;
	} 
	F[s][t]=F[s][t]/rd+1;
	return F[s][t];
}
void add(int x,int y){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;
}
int main(){
	freopen("vijos1675.in","r",stdin);
	freopen("vijos1675.out","w",stdout);
	while (scanf("%d%d",&n,&e)!=EOF){
		memset(tou,0,sizeof(tou));
		dd=0;
		memset(F,0,sizeof(F));
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&S,&T);
		for (int i=1;i<=e;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		for (int i=1;i<=n;i++)spfa(i);
		printf("%.3f",dp(S,T));
	}
	return 0;
}
