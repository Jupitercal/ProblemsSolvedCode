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
	int p,next,len;
}da[N*60];
int dist[N],dd,n,tou[N],in[N];
void add(int x,int y,int len){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].len=len;
}
void spfa(int x){
	q.push(x);
	in[x]=1;
	dist[x]=0;
	while (!q.empty()){
		int u=q.front();q.pop();in[u]=0;
		for (int i=tou[u];i;i=da[i].next){
			int v=da[i].p;
			if (dist[u]+da[i].len>dist[v]){
				dist[v]=dist[u]+da[i].len;
				if (!in[v]){
					in[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int main(){
	int l=0x5f5f5f5f;
	scanf("%d",&n);
	int r=0;dd=0;
	for (int i=1;i<=n;i++){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		add(x,y+1,c);
		l=std::min(l,x);
		r=std::max(r,y+1);
	}
	for (int i=l;i<=r;i++)dist[i]=-0x5f5f5f5f;
	for (int i=l;i<r;i++){
		add(i+1,i,-1);
		add(i,i+1,0);
	}
	spfa(l);
	printf("%d",dist[r]);
	return 0;
}
