/*
ID: Rec
PROG: test
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define INF 0x5f5f5f5f
#define N 1005
struct aa{
	int p,f,next,op;
}da[N*20],db[N*20];
std::queue<int>q;
int dist[N],cnt[N],tou[N],dd,dis[N],to[N];
int cases,S,T,n,m,tot;
bool in[N];
void add(int x,int y,int f,bool b){
	if (b==1){
		da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].f=f;
		da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].f=f;
	}else{
		db[++dd].p=y;db[dd].next=to[x];to[x]=dd;db[dd].f=f;db[dd].op=dd+1;
		db[++dd].p=x;db[dd].next=to[y];to[y]=dd;db[dd].f=0;db[dd].op=dd-1;
	}
}
int sap(int x,int delta){
	if (x==T)return delta;
	int sum=0;int mindis=tot+1;
	for (int i=to[x];i;i=db[i].next){
		int v=db[i].p;
		if (dis[x]==dis[v]+1&&db[i].f){
			int save=sap(v,std::min(delta-sum,db[i].f));
			db[i].f-=save;
			sum+=save;
			db[db[i].op].f+=save;
			if (dis[S]>tot || sum==delta)return sum;
		}
		if (db[i].f)mindis=std::min(mindis,dis[v]);
	}
	if (sum==0){
		if (--cnt[dis[x]]==0)dis[S]=tot+1;
		else ++cnt[dis[x]=mindis+1];
	}
	return sum;
}
void spfa(){
	q.push(S);in[S]=1;
	dist[S]=0;
	while (!q.empty()){
		int u=q.front();q.pop();
		in[u]=0;
		for (int i=tou[u];i;i=da[i].next){
			int v=da[i].p;
			if (dist[u]+da[i].f<dist[v]){
				dist[v]=dist[u]+da[i].f;
				if (!in[v]){
					in[v]=1;
					q.push(v);
				}
			}
		}
	}
	dd=0;
	q.push(T);in[T]=1;tot=1;
	while (!q.empty()){
		int u=q.front();q.pop();
		for (int i=tou[u];i;i=da[i].next){
			int v=da[i].p;
			if (dist[u]==dist[v]+da[i].f){
				add(v,u,1,0);
				if (!in[v]){
					in[v]=1;++tot;
					q.push(v);
				}
			}
		}
	}
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&cases);
	while(cases--){
		dd=0;
		memset(tou,0,sizeof(tou));
		memset(to,0,sizeof(to));
		memset(dis,0,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		memset(dist,INF,sizeof(dist));
		memset(in,0,sizeof(in));
		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c,1);
		}
		scanf("%d%d",&S,&T);
		spfa();
		int ans=0;
		while (dis[S]<=tot)ans+=sap(S,INF);
		printf("%d\n",ans);
	}
	return 0;
}

