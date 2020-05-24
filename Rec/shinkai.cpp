#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define N 300
#define INF 0x3f3f3f3f
struct aa{
	int p,next,op,f,fy;
}da[N*N];
int dist[N*N],from[N*N],bia[N*N],a,b,p,q,ans;
int S,T,tou[N*N],dd;
bool inq[N*N];
std::queue<int>Q;
void add(int x,int y,int va,int len){
    da[++dd].p=y;da[dd].op=dd+1;da[dd].next=tou[x];tou[x]=dd;da[dd].f=len;da[dd].fy=va;
    da[++dd].p=x;da[dd].op=dd-1;da[dd].next=tou[y];tou[y]=dd;da[dd].f=0;da[dd].fy=-va;
}
bool spfa(){
	Q.push(S);
	for (int i=0;i<=T;i++)dist[i]=-INF;
	inq[S]=1;
	dist[S]=0;
	while (!Q.empty()){
		int u=Q.front();Q.pop();inq[u]=0;
		for (int i=tou[u];i;i=da[i].next){
			int v=da[i].p;
			if (dist[u]+da[i].fy>dist[v]&&da[i].f>0){
				dist[v]=dist[u]+da[i].fy;
				from[v]=u;
				bia[v]=i;
				if (!inq[v]){
					inq[v]=1;
					Q.push(v);
				}
			}
		}
	}
	if (dist[T]==-INF)return 0;else return 1;
}
void csum(){ 
	int mindis=INF;
	for (int i=T;i;i=from[i])mindis=std::min(mindis,da[bia[i]].f);
	for (int i=T;i;i=from[i]){
		int x=bia[i];
		da[x].f-=mindis;
		da[da[x].op].f+=mindis;
		ans+=mindis*da[x].fy;
	}
}
int main(){
	freopen("shinkai.in","r",stdin);
	freopen("shinkai.out","w",stdout);
	scanf("%d%d",&a,&b);
	scanf("%d%d",&p,&q);
	S=0;T=1+(q+1)*(p+1);
	for (int i=0;i<=p;i++)
		for (int j=0;j<=q-1;j++){
			int c;
			scanf("%d",&c);
			add(i*(q+1)+j+1,i*(q+1)+j+2,c,1);
			add(i*(q+1)+j+1,i*(q+1)+j+2,0,INF);
	}
	for (int j=0;j<=q;j++)
		for (int i=0;i<=p-1;i++){
			int c;
			scanf("%d",&c);
			add(i*(q+1)+j+1,(i+1)*(q+1)+j+1,c,1);
			add(i*(q+1)+j+1,(i+1)*(q+1)+j+1,0,INF);
		}
	for (int i=1;i<=a;i++){
		int r,x,y;
		scanf("%d%d%d",&r,&x,&y);
		add(S,x*(q+1)+y+1,0,r);
	}
	for (int i=1;i<=b;i++){
		int r,x,y;
		scanf("%d%d%d",&r,&x,&y);
		add(x*(q+1)+y+1,T,0,r);
	}
	while (spfa())csum();
	printf("%d",ans);
	return 0;
}