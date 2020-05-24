#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define N 200000
#define INF 0x3f3f3f3f
struct aa{
	int p,next,len;
}da[N*3];
std::queue<int> q;
int n,k,a,b,c,dist[N],tou[N],dd,S,T,dx[5],dy[5];
bool inq[N],col[200][200];
void add(int x,int y,int len){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].len=len;
}
void spfa(){
	for (int i=S;i<=T;i++)dist[i]=INF;
	dist[S]=0;inq[S]=1;
	q.push(S);
	while (!q.empty()){
		int u=q.front();q.pop();inq[u]=0;
		for (int i=tou[u];i;i=da[i].next){
			int v=da[i].p;
			if (dist[u]+da[i].len<dist[v]){
				dist[v]=dist[u]+da[i].len;
				if (!inq[v]){
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
}
void build(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int l=0;l<=k;l++){
				if (l){
					if (!col[i][j])add(l*n*n+(i-1)*n+j,(i-1)*n+j,a+c);
					else add(l*n*n+(i-1)*n+j,(i-1)*n+j,a);
				}
				if (l<k&&!col[i][j]){
					for (int ii=1;ii<=4;ii++){
						int lx=i+dx[ii];
						int ly=j+dy[ii];
						if (lx<=0||lx>n||ly<=0||ly>n)continue;
						if (ii<=2) add(l*n*n+(i-1)*n+j,(l+1)*n*n+(lx-1)*n+ly,0);
					    else add(l*n*n+(i-1)*n+j,(l+1)*n*n+(lx-1)*n+ly,b);
					}
				}
				if (!l&&col[i][j]){                                      //强制买油233
				    for (int ii=1;ii<=4;ii++){
						int lx=i+dx[ii];
						int ly=j+dy[ii];
						if (lx<=0||lx>n||ly<=0||ly>n)continue;
						if (ii<=2) add(l*n*n+(i-1)*n+j,(l+1)*n*n+(lx-1)*n+ly,0);
					    else add(l*n*n+(i-1)*n+j,(l+1)*n*n+(lx-1)*n+ly,b);
					}
				}
			}
}
int main(){
	freopen("trav.in","r",stdin);
	freopen("trav.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&k,&a,&b,&c);
	dx[1]=0;dx[2]=1;dx[3]=-1;dx[4]=0;
	dy[1]=1;dy[2]=0;dy[3]=0;dy[4]=-1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			int x;
			scanf("%d",&x);
			col[i][j]=x;
		}
	S=1;
	T=n*n*(k+1);
	build();
	spfa();
	int ans=INF;
	for (int i=1;i<=k+1;i++)ans=std::min(ans,dist[i*n*n]);
	printf("%d",ans);
	return 0;
}