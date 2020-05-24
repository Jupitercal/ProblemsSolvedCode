#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define N 200
#define INF 0x3f3f3f3f
struct aa{
	int p,next,f,fy,op;
}da[N*N];
int dist[N],from[N],path[N],S,T,sum,n,ans,tou[N],dd;
bool inq[N];
std::queue<int>q;
bool spfa(){
	memset(dist,INF,sizeof(dist));
	dist[S]=0;
	q.push(S);
	inq[S]=1;
	while (!q.empty()){
		int u=q.front();q.pop();inq[u]=0;
		for (int i=tou[u];i;i=da[i].next){
			int v=da[i].p;
			if (da[i].fy+dist[u]<dist[v]&&da[i].f){
				dist[v]=da[i].fy+dist[u];
				from[v]=u;
				path[v]=i;
				if (!inq[v]){
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
	return dist[T]<INF;
}
void add(int x,int y,int len,int va){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].op=dd+1;da[dd].fy=va;da[dd].f=len;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].op=dd-1;da[dd].fy=-va;da[dd].f=0;
}
void csum(){
	int mindis=INF;
	for (int i=T;i;i=from[i])mindis=std::min(mindis,da[path[i]].f);
	for (int i=T;i;i=from[i]){
		int x=path[i];
		da[x].f-=mindis;
		da[da[x].op].f+=mindis;
		ans+=mindis*da[x].fy;
	}
}
int main(){
	freopen("overload.in","r",stdin);
	freopen("overload.out","w",stdout);
	scanf("%d",&n);
	S=0;T=n+1;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		add(S,i,x,0);
		sum+=x;
	}
	sum=sum/n;
	for (int i=1;i<=n;i++)add(i,T,sum,0);
	add(1,n,INF,1);add(1,2,INF,1);
	add(n,1,INF,1);add(n,n-1,INF,1);
	for (int i=2;i<=n-1;i++)add(i,i+1,INF,1),add(i,i-1,INF,1);
	while (spfa())csum();
	printf("%d",ans);
	return 0;
}