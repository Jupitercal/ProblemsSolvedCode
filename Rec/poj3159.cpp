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
#define N 40000
#define INF 0x5f5f5f5f
int stack[N],top;
int dist[N],n,m,dd,tou[N];
bool in[N];
struct aa{
	int p,next,len;
}da[N*10];
void add(int x,int y,int len){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].len=len;
}
void spfa(){
	stack[++top]=1;
	dist[1]=0;in[1]=1;
	while (top){
		int u=stack[top--];
		in[u]=0;
		for (int i=tou[u];i;i=da[i].next){
			int v=da[i].p;
			if (dist[u]+da[i].len<dist[v]){
				dist[v]=dist[u]+da[i].len;
				if (!in[v]){
					in[v]=1;
					stack[++top]=v;
				}
			}
		}
	}
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	memset(dist,INF,sizeof(dist));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		add(x,y,c);
	}
	spfa();
	printf("%d",dist[n]);
	return 0;
}
