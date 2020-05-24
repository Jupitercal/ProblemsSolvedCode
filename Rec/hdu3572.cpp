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
int dd,dist[N],cnt[N],S,T,tou[N],TT;
int n,m,ll,rr; 
struct aa{
	int p,next,op,f;
}da[N*200];
void add(int x,int y,int f){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].f=f;da[dd].op=dd+1;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].f=0;da[dd].op=dd-1;
}
int sap(int x,int delta){
	if (x==T)return delta;
	int mindis=T;int sum=0;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (da[i].f&&dist[x]==dist[v]+1){
			int save=sap(v,std::min(delta-sum,da[i].f));
			da[i].f-=save;
			sum+=save;
			da[da[i].op].f+=save;
			if (dist[S]>=T || sum==delta) return sum;
		}
		if (da[i].f)mindis=std::min(mindis,dist[v]);
	}
	if (sum==0){
		if (--cnt[dist[x]]==0)dist[S]=T;
		else ++cnt[dist[x]=mindis+1];
	}
	return sum;
}
int main(){
	freopen("hdu3572.in","r",stdin);
	freopen("hdu3572.out","w",stdout);
	scanf("%d",&TT);
	for (int ca=1;ca<=TT;ca++){
		dd=0;
		memset(tou,0,sizeof(tou));
		memset(dist,0,sizeof(dist));
		memset(cnt,0,sizeof(cnt));
		scanf("%d%d",&n,&m);
		S=0;ll=100000;rr=0;
		int ans=0;
		for (int i=1;i<=n;i++){
			int s,e,p;
			scanf("%d%d%d",&p,&s,&e);
			add(S,i,p);
			for (int j=s;j<=e;j++)add(i,n+j,1);
			ll=std::min(ll,s);
			rr=std::max(rr,e);
			ans+=p;
		}
		T=rr+n+1;
		for (int i=ll;i<=rr;i++)add(n+i,T,m);
		while (dist[S]<T)ans-=sap(S,INF);
		printf("Case %d: ",ca);
		if (!ans)printf("Yes\n\n");
		else printf("No\n\n");
	}
	return 0;
}
