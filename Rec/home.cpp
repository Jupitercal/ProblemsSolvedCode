#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 50000
#define INF 0x3f3f3f3f
struct aa{
	int f,op,p,next;
}da[N*20];
int dist[N*4],cnt[N*4],S,T,n,m,k,tou[N*4];
int pi[N/100][N/100],ans,dd,h[N];
int sap(int x,int delta){
	if (x==T)return delta;
	int mindis=T;int sum=0;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (da[i].f&&dist[x]==dist[v]+1){
			int save=sap(v,std::min(delta-sum,da[i].f));
			sum+=save;
			da[i].f-=save;
			da[da[i].op].f+=save;
			if (dist[S]>=T||sum==delta)return sum;
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
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].op=dd+1;da[dd].f=len;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].op=dd-1;da[dd].f=0;
}
bool check(int x){
	dd=0;
	++x;
	memset(tou,0,sizeof(tou));
	memset(dist,0,sizeof(dist));
	memset(cnt,0,sizeof(cnt));
	S=0;
	T=(n+3)*x+1;
	for (int i=0;i<=x;i++)add(S,i*(n+3)+2,INF);
	for (int i=0;i<=x;i++)
		for (int l=1;l<=n+2;l++)
			add(l+i*(n+3),l+(i+1)*(n+3),INF);
	for (int i=1;i<=m;i++){
		for (int j=1;j<=x-1;j++){
			int xx=j%pi[i][0];
			if (xx==0)xx=pi[i][0];
			int lx=pi[i][xx]+2+(j-1)*(n+3);
			int yy=(xx+1)%pi[i][0];
			if (yy==0)yy=pi[i][0];
			int ly=pi[i][yy]+j*(n+3)+2;
			add(lx,ly,h[i]);
		}
	}
	for (int i=0;i<=x;i++)add(i*(n+3)+1,T,INF);
	int ans=0;
	while (dist[S]<T)
		ans+=sap(S,INF);
	if (ans>=k)return 1;else return 0;
}
int main(){
	freopen("home.in","r",stdin);
	freopen("home.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++){
		scanf("%d",&h[i]);
		scanf("%d",&pi[i][0]);
		for (int j=1;j<=pi[i][0];j++)scanf("%d",&pi[i][j]);
	}
	ans=0;
	int l=1;int r=10000;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}