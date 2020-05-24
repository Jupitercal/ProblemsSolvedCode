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
#define N 60000
std::queue<int>q; 
struct aa{
	int p,next;
}da[N*3];
struct noz{
	int x,y,len;
}line[N*2];
int fa[N],dd,tou[N],mx[N][21],mi[N][21],fm[N][21],dp[N][21],dp2[N][21];
int n,b[N],m,dep[N];
bool vis[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void add(int x,int y){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;
}
void bfs(){
	q.push(1);
	vis[1]=1;
	dep[1]=1;
	while (!q.empty()){
		int u=q.front();q.pop();
		for (int i=tou[u];i;i=da[i].next){
			int v=da[i].p;
			if (!vis[v]){
				dep[v]=dep[u]+1;
				q.push(v),vis[v]=1;
				fm[v][0]=u;
				mx[v][0]=std::max(b[v],b[u]);
				mi[v][0]=std::min(b[v],b[u]);
				dp[v][0]=b[u]-b[v];
				dp2[v][0]=b[v]-b[u];
			}
		}
		for (int i=1;i<=20;i++){
			fm[u][i]=fm[fm[u][i-1]][i-1];
			if (!fm[u][i])break;
			mx[u][i]=std::max(mx[u][i-1],mx[fm[u][i-1]][i-1]);
			mi[u][i]=std::min(mi[u][i-1],mi[fm[u][i-1]][i-1]);
			dp[u][i]=std::max(dp[u][i-1],mx[fm[u][i-1]][i-1]-mi[u][i-1]);
			dp[u][i]=std::max(dp[u][i],dp[fm[u][i-1]][i-1]);
			dp2[u][i]=std::max(dp2[u][i-1],mx[u][i-1]-mi[fm[u][i-1]][i-1]);
			dp2[u][i]=std::max(dp2[u][i],dp2[fm[u][i-1]][i-1]);
		}
	}
}
int lca(int x,int y){
	if (dep[x]<dep[y])std::swap(x,y);
	for (int i=20;i>=0;i--)
	  if (dep[x]-dep[y]>=1<<i)x=fm[x][i];
	if (x==y)return x;
	for (int i=20;i>=0;i--)
	  if (fm[x][i]!=fm[y][i]){
	  	x=fm[x][i];
	  	y=fm[y][i];
	  }
	if (x==y)return x;
	else return fm[x][0];
}
int getMAX(int x,int goal){
	int ma=0;
	for (int i=20;i>=0;i--)
	  if (dep[x]-dep[goal]>=1<<i){
	  	ma=std::max(ma,mx[x][i]);
	  	x=fm[x][i];
	  }
	return ma;
} 
int  getMIN(int x,int goal){
	int ma=0x5f5f5f5f;
	for (int i=20;i>=0;i--)
	  if (dep[x]-dep[goal]>=1<<i){
	  	ma=std::min(ma,mi[x][i]);
	  	x=fm[x][i];
	  }
	return ma;
}
int opre1(int x,int goal){
	int ma=0x5f5f5f5f;
	int num=0;
	for (int i=20;i>=0;i--)
	 if (dep[x]-dep[goal]>=1<<i){
	 	num=std::max(num,dp[x][i]);
	 	num=std::max(num,mx[x][i]-ma);
	 	ma=std::min(ma,mi[x][i]);
	 	x=fm[x][i];
	}
	return num;
}
int opre2(int x,int goal){
	int ma=-0x5f5f5f5f;
	int num=0;
	for (int i=20;i>=0;i--)
	 if (dep[x]-dep[goal]>=1<<i){
	 	num=std::max(num,dp2[x][i]);
	 	num=std::max(num,ma-mi[x][i]);
	 	ma=std::max(ma,mx[x][i]);
	 	x=fm[x][i];
	}
	return num;
}
bool cmp(noz a,noz b){return a.len>b.len;}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		dd=0;
		memset(tou,0,sizeof(tou));
		memset(vis,0,sizeof(vis));
		memset(dep,0,sizeof(dep));
		for (int i=1;i<=n;i++)fa[i]=i;
		for (int i=1;i<=n;i++)
		  for (int j=0;j<=20;j++)
		    mx[i][j]=dp[i][j]=dp2[i][j]=fm[i][j]=0,mi[i][j]=0x5f5f5f5f;
		for (int i=1;i<=n;i++)scanf("%d",&b[i]); 
		scanf("%d",&m);
		for (int i=1;i<=m;i++)scanf("%d%d%d",&line[i].x,&line[i].y,&line[i].len);
		std::sort(line+1,line+1+m,cmp);
		int tot=0;int sum=0;
		for (int i=1;i<=m;i++){
			int fx=find(line[i].x);
			int fy=find(line[i].y);
			if (fx!=fy){
				fa[fx]=fy;
				++tot;
				sum+=line[i].len;
				add(line[i].x,line[i].y);
				if (tot==n-1)break;
			}
		}
		printf("%d\n",sum);
		bfs();
		int q;
		scanf("%d",&q);
		for (int i=1;i<=q;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			int LCA=lca(x,y);
			int x1=opre1(x,LCA);
			int x2=opre2(y,LCA);
			printf("%d\n",std::max(std::max(x1,x2),getMAX(y,LCA)-getMIN(x,LCA)));
		}
	}
	return 0;
}

