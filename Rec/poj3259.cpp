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
#define N 1005
#define INF 0x5f5f5f5f
int dist[N];
int tou[N],dd,in[N];
int n,m,w,s;
std::queue<int>q;
bool it[N];
struct aa{
	int p,next,len;
}da[N*30];
void add(int x,int y,int c){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].len=c;
}
bool spfa(){
	q.push(s);
	dist[s]=0;
	++in[s];it[s]=1;
	while (!q.empty()){
		int u=q.front();q.pop();it[u]=0;
		for (int i=tou[u];i;i=da[i].next){
			int vi=da[i].p;
			if (dist[vi]>dist[u]+da[i].len){
				dist[vi]=dist[u]+da[i].len;
				if (!it[vi]){
					it[vi]=1;
					++in[vi];
					if (in[vi]==n)return 1;
					q.push(vi);
				}
			}
		}
	}
	return 0;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	int cases;
	scanf("%d",&cases);s=1;
	while (cases--){
		dd=0;
		memset(tou,0,sizeof(tou));
		memset(dist,INF,sizeof(dist));
		memset(in,0,sizeof(in));
		memset(it,0,sizeof(it));
		scanf("%d%d%d",&n,&m,&w);
		for (int i=1;i<=m;i++){
			int x,y,c;
			scanf("%d%d%d",&x,&y,&c);
			add(x,y,c);
			add(y,x,c);
		}
		for (int i=1;i<=w;i++){
			int x,y,c;
			scanf("%d%d%d",&x,&y,&c);
			add(x,y,-c);
		}
		if (spfa())printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

