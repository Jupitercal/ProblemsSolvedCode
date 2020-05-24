#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 2000
#define INF 0x3f3f3f3f
struct aa{
	int p,next,op,f;
}da[N*N];
int dist[N*N],cnt[N*N],T,S,ans,tot,n,nod,tou[N*N],dd;
void add(int x,int y,int len){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].op=dd+1;da[dd].f=len;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].op=dd-1;da[dd].f=0;
}
int sap(int x,int delta){
	if (x==T)return delta;
	int mindis=T+1;int sum=0;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (dist[x]==dist[v]+1&&da[i].f){
			int save=sap(v,std::min(da[i].f,delta-sum));
			sum+=save;
			da[i].f-=save;
			da[da[i].op].f+=save;
			if (dist[S]>T || sum==delta) return sum;
		}
		if (da[i].f) mindis=std::min(mindis,dist[v]);
	}
	if (sum==0){
		if (--cnt[dist[x]]==0)dist[S]=T+1;
			else ++cnt[dist[x]=mindis+1];
	}
	return sum;
}
int main(){
	freopen("bzoj3996.in","r",stdin);
	freopen("bzoj3996.out","w",stdout);
	scanf("%d",&n);
	S=0;T=n+n*n+1;
	nod=n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			int x;
			scanf("%d",&x);
			tot+=x;
			++nod;
			add(i,nod,INF);
			add(j,nod,INF);
			add(nod,T,x);
		}
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		add(S,i,x);
	}
	while (dist[S]<=T)ans+=sap(S,INF);
	printf("%d",tot-ans);
	return 0;
}