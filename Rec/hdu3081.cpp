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
#define N 200
#define INF 0x5f5f5f5f
int cases; 
int n,m,f,dis[N*2],fri[N][N],mai[N][N];
int cnt[N*2],tou[N*2],dd,S,T;
struct aa{
	int p,next,op,f;
}da[N*N];
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
			if (dis[S]>T || sum==delta)return sum;
		}
		if (da[i].f)mindis=std::min(mindis,dis[v]);
	}
	if (sum==0){
		if (--cnt[dis[x]]==0)dis[S]=T+1;
		else ++cnt[dis[x]=mindis+1];
	}
	return sum;
}
bool solve(int x){
	dd=0;
	memset(dis,0,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(tou,0,sizeof(tou));
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=n;j++)
	    if (mai[i][j])add(i,j+n,1);
	for (int i=1;i<=n;i++)add(S,i,x),add(i+n,T,x);
	int ans=0;
	while (dis[S]<=T)ans+=sap(S,INF);
	return ans==x*n;
}
void Floyd(){
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=n;j++)
	    if (fri[i][j])
	      for (int k=1;k<=n;k++)
	        if (fri[j][k])fri[i][k]=1;
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=n;j++)
	    if (fri[i][j])
	      for (int k=1;k<=n;k++)
	        if (mai[j][k])mai[i][k]=1;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&cases);
	while (cases--){
		memset(mai,0,sizeof(mai));
		memset(fri,0,sizeof(fri));
		scanf("%d%d%d",&n,&m,&f);
		S=0;T=n*2+1;
		for (int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			mai[x][y]=1;
		}
		for (int i=1;i<=f;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			fri[x][y]=1;
			fri[y][x]=1;
		}
		Floyd();
		int ans=0;
		int l=0;int r=n;
		while (l<=r){
			int mid=(l+r)/2;
			if (solve(mid)){
				ans=mid;
				l=mid+1;
			}else r=mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}

