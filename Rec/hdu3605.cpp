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
	int f,op,p,next;
}da[N*30];
int tou[N*2],dd,dist[N*2],cnt[N*2],T,S,sum[N];
int n,m;
void add(int x,int y,int f){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].op=dd+1;da[dd].f=f;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].op=dd-1;da[dd].f=0;
}
int sap(int x,int delta){
	if (x==T)return delta;
	int mindis=T;int num=0;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (dist[x]==dist[v]+1&&da[i].f){
			int save=sap(v,std::min(da[i].f,delta-num));
			da[i].f-=save;
			num+=save;
			da[da[i].op].f+=save;
			if (dist[S]>=T ||num==delta)return num;
		}
		if (da[i].f)mindis=std::min(mindis,dist[v]);
	}
	if (num==0){
		if (--cnt[dist[x]]==0)dist[S]=T;
		else ++cnt[dist[x]=mindis+1];
	}
	return num;
}
int main(){
	freopen("hdu3605.in","r",stdin);
	freopen("hdu3605.out","w",stdout);
	while (scanf("%d%d",&n,&m)!=EOF){
		memset(sum,0,sizeof(sum));
		memset(tou,0,sizeof(tou));
		memset(da,0,sizeof(da));
		memset(dist,0,sizeof(dist));
		memset(cnt,0,sizeof(cnt));
		dd=0;
		S=0;T=0;
		for (int i=1;i<=n;i++){
			int num=0;
			for (int j=1;j<=m;j++){
				int x;
				scanf("%d",&x);
				num=num*2+x;
			}
			++sum[num];
		}
		int rs=(1<<m)-1;
		for (int i=0;i<=rs;i++)
		  if (sum[i]){
		  	add(S,i+1,sum[i]);
		  	for (int j=1;j<=m;j++)
		  		if ((i>>(j-1))&1)add(i+1,rs+m-j+2,INF);
		  }
		T=rs+m+3;
		for (int i=1;i<=m;i++){
			int x;
			scanf("%d",&x);
			add(rs+i+1,T,x);
		}
		int ans=0;
		while (dist[S]<T) ans+=sap(S,INF);
		if (ans!=n)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
