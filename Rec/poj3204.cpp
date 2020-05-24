#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 60000
#define INF 0x3f3f3f3f
struct aa{
	int p,next,f,op; 
}da[N*3];
struct poi{
	int x,y;
}poi[N];
int n,m,dist[N],cnt[N],S,T,tou[N],dd,ans;
bool inq[N],in[N];
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
			if (dist[S]>T ||sum==delta)return sum;
		}
		if (da[i].f)mindis=std::min(dist[v],mindis);
	}
	if (sum==0){
		if (--cnt[dist[x]]==0)dist[S]=T+1;
		else ++cnt[dist[x]=mindis+1];
	}
	return sum;
}
void dfs(int x){
	inq[x]=1;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (!inq[v]&&da[i].f)dfs(v);
	}
}
void dfs1(int x){
	in[x]=1;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (!in[v]&&da[da[i].op].f)dfs1(v);
	}
}
int main(){
	freopen("poj3204.in","r",stdin);
	freopen("poj3204.out","w",stdout);
	while (scanf("%d%d",&n,&m)!=EOF){
		dd=0;ans=0;
		memset(tou,0,sizeof(tou));
		memset(dist,0,sizeof(dist));
		memset(cnt,0,sizeof(cnt));
		memset(inq,0,sizeof(inq));
		memset(in,0,sizeof(in));
	    S=0;T=n+1;
	    add(S,1,INF);add(n,T,INF);
	    for (int i=1;i<=m;i++){
		   int x,y,c;
		   scanf("%d%d%d",&x,&y,&c);
		   ++x;++y;
		   add(x,y,c);
	  	   poi[i].x=x;poi[i].y=y;
	    }
	    while (dist[S]<=T)sap(S,INF);
	    dfs(S);dfs1(T);
	    for (int i=1;i<=m;i++)if (inq[poi[i].x]&&in[poi[i].y])++ans;
	    printf("%d\n",ans);
	}
	return 0;
}
