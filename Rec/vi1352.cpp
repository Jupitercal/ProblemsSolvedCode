#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 50005
#define INF 0x3f3f3f3f
struct aa{
	int p,next,f,op;
}da[N*6];
int n,m,dist[N*2],cnt[N*2],S,T,dd,tou[N*2],sum,ans;
int sap(int x,int delta){
	if (x==T)return delta;
	int mindis=T;int sum=0;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (da[i].f&&dist[x]==dist[v]+1){
			int save=sap(v,std::min(da[i].f,delta-sum));
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
void add(int x,int y,int len){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].f=len;da[dd].op=dd+1;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].f=0;da[dd].op=dd-1;
}
int main(){
	freopen("vi1352.in","r",stdin);
	freopen("vi1352.out","w",stdout);
	scanf("%d%d",&n,&m);
	S=0;T=n+m+1;
	for (int i=1;i<=n;i++){
		int c;
		scanf("%d",&c);
		add(i+m,T,c);
	}
	for (int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(S,i,c);
		add(i,a+m,INF);
		add(i,b+m,INF);
		sum+=c;
	}
	while (dist[S]<T)ans+=sap(S,INF);
	printf("%d",sum-ans);
	return 0;
}