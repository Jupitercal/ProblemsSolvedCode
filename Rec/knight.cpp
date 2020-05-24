#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 40001
#define INF 0x3f3f3f3f
struct aa{
	int p,op,f,next;
}da[N*10];
int tou[N],dist[N],cnt[N],T,S,n,m,ans,dx[9],dy[9],dd;
bool col[300][300],co[300][300];
void add(int x,int y,int len){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].f=len;da[dd].op=dd+1;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].f=0;da[dd].op=dd-1;
}
int sap(int x,int delta){
	if (x==T) return delta;
	int mindis=T;int sum=0;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (dist[x]==dist[v]+1&&da[i].f){
			int save=sap(v,std::min(da[i].f,delta-sum));
			da[i].f-=save;
			sum+=save;
			da[da[i].op].f+=save;
			if (dist[S]>=T ||sum==delta) return sum;
		}
		if (da[i].f)mindis=std::min(mindis,dist[v]);
	}
	if (sum==0){
		if (--cnt[dist[x]]==0)dist[S]=T;
		else ++cnt[dist[x]=mindis+1];
	}
	return sum;
}
void color(){
	for (int i=1;i<=n;i++){
		col[i][1]=col[i-1][1]^1;
		for (int j=2;j<=n;j++)col[i][j]=col[i][j-1]^1;
    }
}
void build(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (!co[i][j]&&col[i][j]){
				add(S,(i-1)*n+j,1);
				for (int x=1;x<=8;x++){
					int lx=dx[x]+i;
					int ly=dy[x]+j;
					if (lx>0&&lx<=n&&ly>0&&ly<=n){
						if (!co[lx][ly]&&!col[lx][ly])add((i-1)*n+j,(lx-1)*n+ly,INF);
					}
				}
			}else if (!co[i][j]&&!col[i][j])add((i-1)*n+j,T,1);
}
int main(){
	freopen("knight.in","r",stdin);
	freopen("knight.out","w",stdout);
	dx[1]=-1;dx[2]=-2;dx[3]=-1;dx[4]=-2;dx[5]=1;dx[6]=1;dx[7]=2;dx[8]=2;
	dy[1]=2;dy[2]=1;dy[3]=-2;dy[4]=-1;dy[5]=-2;dy[6]=2;dy[7]=-1;dy[8]=1;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		co[x][y]=1;
	}
	T=n*n+1;
	color();
	build();
	while (dist[S]<T)ans+=sap(S,INF);
	printf("%d",n*n-m-ans);
	return 0;
}