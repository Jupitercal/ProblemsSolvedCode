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
#define MOD 29999
#define INF 0x5f5f5f5f
struct aa{
	int p,op,next,f;
}da[MOD*10];
int n,m,S,T,cum;
int tou[MOD*2],dd,dist[MOD*2],cnt[MOD*2],ans,time[MOD*10];
int s[MOD],e[MOD];
void add(int x,int y,int f){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].op=dd+1;da[dd].f=f;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].op=dd-1;da[dd].f=0;
}
bool cmp(int x,int y){return x<y;}
int sap(int x,int delta){
	if (x==T)return delta;
	int sum=0;int mindis=T;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (da[i].f&&dist[x]==dist[v]+1){
			int save=sap(v,std::min(delta-sum,da[i].f));
			da[i].f-=save;
			sum+=save;
			da[da[i].op].f+=save;
			if (dist[S]>T || sum==delta) return sum;
		}
		if (da[i].f)mindis=std::min(mindis,dist[v]);
	}
	if (sum==0){
		if (--cnt[dist[x]]==0)dist[S]=T+1;
		else ++cnt[dist[x]=mindis+1];
	}
	return sum;
}
int main(){
	freopen("hdu2883.in","r",stdin);
	freopen("hdu2883.out","w",stdout);
	while (scanf("%d%d",&n,&m)!=EOF){
		cum=0;
		memset(tou,0,sizeof(tou));
		memset(dist,0,sizeof(dist));
		memset(cnt,0,sizeof(cnt));
		dd=0;
		ans=0;S=0;int tot=0;
		for (int i=1;i<=n;i++){
			int ti,ni;
			scanf("%d%d%d%d",&s[i],&ni,&e[i],&ti);
			ans+=ni*ti;
			time[++tot]=s[i];time[++tot]=e[i];
			add(S,i,ni*ti);
		}
		std::sort(time+1,time+tot+1,cmp);
		int c=1;
		for (int i=1;i<=tot;i++)
			if (time[c]!=time[i])time[++c]=time[i];
		T=c+n+1;
		for (int i=1;i<=c;i++){
			add(n+i,T,m*(time[i]-time[i-1]));
			for (int j=1;j<=n;j++)
				if (s[j]<=time[i-1]&&time[i]<=e[j])add(j,i+n,INF);
		}
		while (dist[S]<=T)ans-=sap(S,INF);
		if (ans==0)printf("Yes\n");else printf("No\n");
	}
	return 0;
}
