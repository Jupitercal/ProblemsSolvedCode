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
#define N 600
#define INF 0x5f5f5f5f
struct aa{
	int p,f,op,next;
}da[N*N];
int n,m,dd;
int S,T,dis[N],tou[N],cnt[N];
void add(int x,int y,int flow){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].f=flow;da[dd].op=dd+1;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].f=0;da[dd].op=dd-1;
} 
int sap(int x,int delta){
	if (x==T)return delta;
	int mindis=n*2;int sum=0;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (dis[x]==dis[v]+1&&da[i].f){
			int f=sap(v,std::min(delta-sum,da[i].f));
			da[i].f-=f;
			sum+=f;
			da[da[i].op].f+=f;
			if (dis[S]>2*n || sum==delta)return sum;
		}
		if (da[i].f)mindis=std::min(mindis,dis[v]);
	}
	if (sum==0){
		if (--cnt[dis[x]]==0)dis[S]=2*n+1;
		else ++cnt[dis[x]=mindis+1];
	}
	return sum;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d%d",&n,&m)!=EOF){
		dd=0;
		memset(tou,0,sizeof(tou));
		memset(dis,0,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		scanf("%d%d",&S,&T);
		for (int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			add(i,i+n,x);
		}
		T=T+n;
		for (int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u+n,v,INF);
			add(v+n,u,INF);
		}
		int ans=0;
		while (dis[S]<=2*n)ans+=sap(S,INF);
		printf("%d\n",ans);
	}
	return 0;
}

