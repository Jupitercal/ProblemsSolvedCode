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
#define N 3000
#define INF 0x5f5f5f5f
struct aa{
	int f,p,next,op;
}da[N*10];
int T,t,s,n,m;
int dist[N],cnt[N],tou[N],dd;
void add(int x,int y,int f){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].op=dd+1;da[dd].f=f;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].op=dd-1;da[dd].f=0;
}
int sap(int x,int delta){
	if (x==t)return delta;
	int mindis=t;int sum=0;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (da[i].f&&dist[x]==dist[v]+1){
			int save=sap(v,std::min(delta-sum,da[i].f));
			da[i].f-=save;
			sum+=save;
			da[da[i].op].f+=save;
			if (dist[s]>t || sum==delta) return sum;
		}
		if (da[i].f)mindis=std::min(mindis,dist[v]);
	}
	if (sum==0){
		if (--cnt[dist[x]]==0)dist[x]=t+1;
		else ++cnt[dist[x]=mindis+1];
	}
	return sum;
}
int main(){
	freopen("hdu3549.in","r",stdin);
	freopen("hdu3549.out","w",stdout);
	scanf("%d",&T);
	for (int cases=1;cases<=T;cases++){
		dd=0;
		memset(tou,0,sizeof(tou));
		memset(dist,0,sizeof(dist));
		memset(cnt,0,sizeof(cnt));
		scanf("%d%d",&n,&m);
		int ans=0;
		t=n;
		s=1;
		for (int i=1;i<=m;i++){
			int x,y,c;
			scanf("%d%d%d",&x,&y,&c);
			add(x,y,c);
		}
		while (dist[s]<=t)ans+=sap(s,INF);
		printf("Case %d: %d\n",cases,ans);
	} 
	return 0;
} 
