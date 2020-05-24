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
double dist[N];
int tou[N],dd,in[N];
int n,m,s;
std::queue<int>q;
double v;
bool it[N];
struct aa{
	int p,next;
	double r,c;
}da[N*N];
void add(int x,int y,double r,double c){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].r=r;da[dd].c=c;
}
bool spfa(){
	q.push(s);
	dist[s]=v;
	++in[s];it[s]=1;
	while (!q.empty()){
		int u=q.front();q.pop();it[u]=0;
		for (int i=tou[u];i;i=da[i].next){
			int vi=da[i].p;
			if (dist[vi]<(dist[u]-da[i].c)*da[i].r){
				dist[vi]=(dist[u]-da[i].c)*da[i].r;
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
	while (scanf("%d%d%d%lf",&n,&m,&s,&v)!=EOF){
		dd=0;
		memset(tou,0,sizeof(tou));
		memset(dist,0,sizeof(dist));
		memset(in,0,sizeof(in));
		memset(it,0,sizeof(it));
		for (int i=1;i<=m;i++){
			double r1,c1,r2,c2;
			int x,y;
			scanf("%d%d%lf%lf%lf%lf",&x,&y,&r1,&c1,&r2,&c2);
			add(x,y,r1,c1);
			add(y,x,r2,c2);
		}
		if (spfa())printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

