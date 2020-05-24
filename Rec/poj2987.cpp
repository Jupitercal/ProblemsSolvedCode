#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define N 6000
#define INF 0x3f3f3f3f
typedef long long LL;
struct aa{
	int p,next,op;
	LL f;
}da[N*100];
int dist[N],tou[N],dd,n,m,S,T;
LL ans,sum;
int cnt[N],ct;
bool inq[N];
void add(int x,int y,LL len){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].f=len;da[dd].op=dd+1;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].f=0;da[dd].op=dd-1;
}
LL sap(int x,LL delta){
	if (x==T)return delta;
	int mindis=T;LL sum=0;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (dist[x]==dist[v]+1&&da[i].f){
			LL save=sap(v,std::min(delta-sum,da[i].f));
			sum+=save;
			da[i].f-=save;
			da[da[i].op].f+=save;
			if (dist[S]>=T||sum==delta) return sum;
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
		if (!inq[v]&&da[i].f)dfs(v);
	}
}
int main(){
	freopen("poj2987.in","r",stdin);
	freopen("poj2987.out","w",stdout);
	scanf("%d%d",&n,&m);
	S=0;T=n+1;
	for (int i=1;i<=n;i++){
		LL x;
		scanf("%lld",&x);
		if (x>=0)add(S,i,x),sum+=x;
		else add(i,T,-x);
	}
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y,INF);
	}
	while (dist[S]<T)ans+=sap(S,INF);
	dfs(S);
	printf("%d %lld",ct-1,sum-ans);
	return 0;
}