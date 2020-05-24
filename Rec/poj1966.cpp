#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200
#define INF 0x3f3f3f3f
struct aa{
	int p,next,op,f,cf;
}da[N*N];
int n,m,dist[N],cnt[N],S,T,dd,tou[N],nod,flow,ans;
void add(int x,int y,int len){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].cf=len;da[dd].op=dd+1;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].cf=0;da[dd].op=dd-1;
}
int sap(int x,int delta){
	if (x==T)return delta;
	int mindis=nod+1;int sum=0;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (dist[x]==dist[v]+1&&da[i].f){
			int save=sap(v,std::min(da[i].f,delta-sum));
			sum+=save;
			da[i].f-=save;
			da[da[i].op].f+=save;
			if (dist[S]>nod || sum==delta) return sum;
		}
		if (da[i].f) mindis=std::min(mindis,dist[v]);
	}
	if (sum==0){
		if (--cnt[dist[x]]==0)dist[S]=nod+1;
			else ++cnt[dist[x]=mindis+1];
	}
	return sum;
}
void init(){
	memset(dist,0,sizeof(dist));
	memset(cnt,0,sizeof(cnt));
	for (int ii=1;ii<=dd;ii++)da[ii].f=da[ii].cf;
}
int main(){
	freopen("poj1966.in","r",stdin);
	freopen("poj1966.out","w",stdout);
	while (scanf("%d %d",&n,&m)!=EOF){
		ans=INF;
		dd=0;memset(tou,0,sizeof(tou));
		for (int i=1;i<=n;i++)add(i,i+n,1);
		nod=n*n+1;
		for (int i=1;i<=m;i++){
			int x,y;
			scanf(" (%d,%d)",&x,&y);
			x++;y++;
			add(x+n,y,INF);
			add(y+n,x,INF);
		}
		for (int i=1;i<n;i++)
			for (int j=i+1;j<=n;j++){
				init();
				flow=0;
				S=i+n;T=j;
				while (dist[S]<=nod)flow+=sap(S,INF);
				ans=std::min(ans,flow);
			}
		if (ans>=n)ans=n;
		printf("%d\n",ans);
	}
	return 0;
}