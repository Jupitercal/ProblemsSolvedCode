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
#define N 100005
#define INF 0x5f5f5f5f
struct aa{
	int p,next,f,op;
}da[N*3];
int S,T,cases,dd;
int n,m;
int cnt[N],dis[N],tou[N],b[N];
void add(int x,int y,int f){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].f=f;da[dd].op=dd+1;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].f=0;da[dd].op=dd-1;
}
int sap(int x,int delta){
	if (x==T)return delta;
	int sum=0;int mindis=n+1;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (dis[x]==dis[v]+1&&da[i].f){
			int save=sap(v,std::min(delta-sum,da[i].f));
			da[i].f-=save;
			sum+=save;
			da[da[i].op].f+=save;
			if (dis[S]>n ||sum==delta)return sum;
		}
		if (da[i].f)mindis=std::min(mindis,dis[v]);
	} 
	if (sum==0){
		if (--cnt[dis[x]]==0)dis[S]=n+1;
		else ++cnt[dis[x]=mindis+1];
	}
	return sum;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&cases);
	while (cases--){
		memset(tou,0,sizeof(tou));
		memset(dis,0,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		dd=0;
		scanf("%d%d",&n,&m);
		S=T=0;
		for (int i=1;i<=n;i++){
			int y;
			scanf("%d%d",&b[i],&y);
			if (S==0||(b[i]<=b[S]&&S))S=i;
			if (T==0||(b[i]>=b[T]&&T))T=i;
		}
		for (int i=1;i<=m;i++){
			int x,y,c;
			scanf("%d%d%d",&x,&y,&c);
			add(x,y,c);
			add(y,x,c);
		}
		int ans=0;
		while(dis[S]<=n)ans+=sap(S,INF);
		printf("%d\n",ans);
	}
	return 0;
}

