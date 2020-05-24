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
#define N 2000
#define INF 0x5f5f5f5f
struct aa{
	int p,next,f,op;
}da[N*N];
int dd,n,f,d,a[N],b[N],S,T,tou[N];
int dis[N],cnt[N];
char s[N];
void add(int x,int y,int f){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].f=f;da[dd].op=dd+1;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].f=0;da[dd].op=dd-1;
}
int sap(int x,int delta){
	if (x==T)return delta;
	int sum=0;int mindis=T+1;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (dis[x]==dis[v]+1&&da[i].f){
			int save=sap(v,std::min(delta-sum,da[i].f));
			da[i].f-=save;
			sum+=save;
			da[da[i].op].f+=save;
			if (dis[S]>T ||sum==delta)return sum;
		}
		if (da[i].f)mindis=std::min(mindis,dis[v]);
	} 
	if (sum==0){
		if (--cnt[dis[x]]==0)dis[S]=T+1;
		else ++cnt[dis[x]=mindis+1];
	}
	return sum;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d%d%d",&n,&f,&d)!=EOF){
		S=0;dd=0;T=f+d+2*n+1;
		memset(tou,0,sizeof(tou));
		memset(dis,0,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		for (int i=1;i<=f;i++){
			scanf("%d",&a[i]);
			add(S,i,a[i]);
		}
		for (int i=1;i<=d;i++){
			scanf("%d",&b[i]);
			add(i+f+n*2,T,b[i]);
		}
		for (int i=1;i<=n;i++)add(i+f,i+f+n,1);
		for (int i=1;i<=n;i++){
			scanf("%s",s);
			for (int j=0;j<f;j++)
			  if (s[j]=='Y')add(j+1,f+i,1);
		}
		for (int i=1;i<=n;i++){
			scanf("%s",s);
			for (int j=0;j<d;j++)
			  if (s[j]=='Y')add(i+n+f,f+2*n+j+1,1);
		}
		int flow=0;
		while (dis[S]<=T)flow+=sap(S,INF);
		printf("%d\n",flow);
	}
	return 0;
}

