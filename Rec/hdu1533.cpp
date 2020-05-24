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
#define N 600
#define INF 0x5f5f5f5f
struct bb{
	int x,y;
}sta[N],end[N];
struct aa{
	int p,op,va,f,next;
}da[N*N];
int tou[N],tot1,tot2,from[N*N],path[N*N],dis[N*N],dd;
int n,m,S,T,ans;
char s[N];
std::queue<int>q;
bool bo[N];
void add(int x,int y,int f,int va){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].op=dd+1;da[dd].f=f;da[dd].va=va;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].op=dd-1;da[dd].f=0;da[dd].va=-va;
}
bool spfa(){
	for (int i=1;i<=N-1;i++)dis[i]=INF;
	memset(from,0,sizeof(from));
	memset(path,0,sizeof(path));
	q.push(S);
	dis[S]=0;
	while (!q.empty()){
		int now=q.front();q.pop();
		bo[now]=false;
		for (int i=tou[now];i;i=da[i].next)
		if (dis[da[i].p]>dis[now]+da[i].va &&da[i].f>0){
			dis[da[i].p]=dis[now]+da[i].va;
			path[da[i].p]=i;
			from[da[i].p]=now;
			if (!bo[da[i].p]){
				bo[da[i].p]=1;
				q.push(da[i].p);
			}
		}
	}
	return dis[T]<INF;
}
void work(){
	int mindis=INF;
	for (int i=T;i;i=from[i])mindis=std::min(mindis,da[path[i]].f);
	for (int i=T;i;i=from[i]){
		da[path[i]].f-=mindis;
		da[da[path[i]].op].f+=mindis;
		ans+=mindis*da[path[i]].va;
	}
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d%d",&n,&m)!=EOF&&n&&m){
		tot1=tot2=0;
		memset(tou,0,sizeof(tou));
		dd=0;S=0;ans=0;
		for (int i=1;i<=n;i++){
			scanf("%s",s);
			for (int j=0;j<m;j++)
			  if (s[j]=='m'){
			  	++tot1;
			  	sta[tot1].x=i;
			  	sta[tot1].y=j+1;
			  }else if (s[j]=='H'){
			  	++tot2;
			  	end[tot2].x=i;
			  	end[tot2].y=j+1;
			  }
		}
		T=tot1+tot2+1;
		for (int i=1;i<=tot1;i++)add(S,i,1,0);
		for (int i=1;i<=tot2;i++)add(i+tot1,T,1,0);
		for (int i=1;i<=tot1;i++)
		  for (int j=1;j<=tot2;j++)
		    add(i,j+tot1,1,abs(sta[i].x-end[j].x)+abs(sta[i].y-end[j].y));
		while (spfa())
		work();
		printf("%d\n",ans);
	}
	return 0;
}

