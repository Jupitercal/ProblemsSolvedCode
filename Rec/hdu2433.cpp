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
#include<queue>
#define N 3000
std::queue <int>q;
int n,m;
struct jj{
	int p,op,id;
}da[N*3];
int dist[201][201],dd,tou[201],pre[201][2*N],dis[201];
bool v[201],edge[2*N];
void add(int x,int y){
	da[++dd].p=y;da[dd].op=tou[x];tou[x]=dd;da[dd].id=dd/2+1;
	da[++dd].p=x;da[dd].op=tou[y];tou[y]=dd;da[dd].id=da[dd-1].id;
}
void SPFA(int x,bool b){
	q.push(x);
	for (int i=1;i<=n;i++)v[i]=0;
	v[x]=1;
	dist[x][x]=0;dis[x]=0;
	while (!q.empty()){
		int u=q.front();q.pop();
		for (int i=tou[u];i;i=da[i].op){
			int vi=da[i].p;
			if (b==1){
				if (!edge[da[i].id]&&!v[vi]){
					dist[x][vi]=dist[x][u]+1;
					pre[x][da[i].id]=1;
					v[vi]=1;
					q.push(vi);
				}
			}
			else {
				if (!edge[da[i].id]&&!v[vi]){
					dis[vi]=dis[u]+1;
					v[vi]=1;
					q.push(vi);
				}
			}
		}
	}	
}
void solve(){
	int ans=0;
	memset(pre,0,sizeof(pre));
	for (int i=1;i<=n;i++)SPFA(i,1);
	for (int j=1;j<=n;j++)
	    for (int k=1;k<=n;k++)
	        if (j!=k)ans+=dist[j][k];
	for (int i=1;i<=m;i++){
		edge[i]=1;
		int ans1=ans;
		for (int j=1;j<=n;j++)
		  if (pre[j][i]){
		  	for (int k=1;k<=n;k++)dis[k]=20000;
			SPFA(j,0);
			for (int k=1;k<=n;k++)
			  if (k!=j){
			  	ans1-=dist[j][k];
			  	ans1+=dis[k];
			  }	
		  }
		edge[i]=0;
		ans1>=20000?printf("INF\n"):printf("%d\n",ans1);
	}
}
int main(){
	freopen("hdu2433.in","r",stdin);
	freopen("hdu2433.out","w",stdout);
	while (scanf("%d%d",&n,&m)!=EOF){
		dd=0;
		for (int i=1;i<=n;i++)
	      for (int j=1;j<=n;j++)dist[i][j]=20000,tou[i]=0;
		for (int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		solve();
	}
	return 0;
}
