#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 300
#define INF 0x3f3f3f3f
#define ex 0.0000001
struct aa{
	int p,next,op;
	double f;
}da[N*N*4];
int n,m,k,S,T,t,tou[N*4],dist[N*4],dd,cnt[N*4];
double ans;
void add(int x,int y,double len){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].op=dd+1;da[dd].f=len;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].op=dd-1;da[dd].f=0.0;
}
double mi(double a,double b){
	if (a-b>ex)return a;else return b;
}
double sap(int x,double delta){
	if (x==T)return delta;
	int mindis=T;double sum=0.0;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (dist[x]==dist[v]+1&&da[i].f>ex){
			double save=sap(v,mi(da[i].f,delta-sum));
			sum+=save;
			da[i].f-=save;
			da[da[i].op].f+=save;
			if (dist[S]>=T || fabs(delta-sum)<ex)return sum;
		}
		if (da[i].f>ex) mindis=std::min(mindis,dist[v]);
	}
	if (sum<ex){
		if (--cnt[dist[x]]==0)dist[S]=T;
		else ++cnt[dist[x]=mindis+1];
	}
	return sum;
}
int main(){
	freopen("poj3308.in","r",stdin);
	freopen("poj3308.out","w",stdout);
	scanf("%d",&t);
	while (t--){
		dd=0;ans=0.0;
		memset(dist,0,sizeof(dist));
		memset(cnt,0,sizeof(cnt));
		memset(tou,0,sizeof(tou));
		scanf("%d%d%d",&m,&n,&k);
		S=0;T=n+m+1;
		for (int i=1;i<=m;i++){
			double x;
			scanf("%lf",&x);
			add(S,i,log(x));
		}
		for (int i=1;i<=n;i++){
			double x;
			scanf("%lf",&x);
			add(i+m,T,log(x));
		}
		for (int i=1;i<=k;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y+m,INF);
		}
		while (dist[S]<T)ans+=sap(S,INF);
		printf("%.4lf\n",exp(ans));
	}
	return 0;
}