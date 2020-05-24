#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 600
#define INF 0x3f3f3f3f
struct aa{
	int p,next,f,op;
}da[N*N];
int n,dist[N],cnt[N],tou[N],dd,ans,su,S,T,ct,cost[N],ss,m;
bool inq[N];
void add(int x,int y,int len){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].op=dd+1;da[dd].f=len;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].op=dd-1;da[dd].f=0;
}
int sap(int x,int delta){
	if (x==T) return delta;
	int mindis=T;int sum=0;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (dist[x]==dist[v]+1&&da[i].f){
			int save=sap(v,std::min(da[i].f,delta-sum));
			da[i].f-=save;
			sum+=save;
			da[da[i].op].f+=save;
			if (dist[S]>T ||sum==delta) return sum;
		}
		if (da[i].f)mindis=std::min(mindis,dist[v]);
	}
	if (sum==0){
		if (--cnt[dist[x]]==0)dist[S]=T;
		else ++cnt[dist[x]=mindis+1];
	}
	return sum;
}
void dfs(int x){
	inq[x]=1;++ct;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (da[i].f&&!inq[v])dfs(v);
	}
}
int main(){
	freopen("zoj2930.in","r",stdin);
	freopen("zoj2930.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		dd=0;ans=0;ct=0;su=0;
		memset(tou,0,sizeof(tou));
		memset(inq,0,sizeof(inq));
		memset(dist,0,sizeof(dist));
		memset(cnt,0,sizeof(cnt));
		S=0;T=n+1;ss=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&cost[i]);
			su+=cost[i];
		}
		for (int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			cost[i]=cost[i]-x;
		}
		for (int i=1;i<=n;i++){
			if (cost[i]>=0)add(S,i,cost[i]),ss=ss+cost[i];
			else add(i,T,-cost[i]);
		}
		scanf("%d",&m);
		for (int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y,INF);
		}
		while (dist[S]<=T)ans+=sap(S,INF);
		dfs(S);ct--;
		printf("%d %d\n",su-(ss-ans),n-ct);
	}
	return 0;
}