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
struct aa{
	int p,next;
}da[N*N];
int tou[N],dd,n,m,in[N];
bool vis[N];
void add(int x,int y){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;
}
void Topo(){
	for (int i=1;i<=n;i++){
		int j;
		for (j=1;j<=n;j++)
		  if (!in[j]&&!vis[j])break;
		printf("%d",j);
		if (i!=n)printf(" ");
		vis[j]=1;
		for (int k=tou[j];k;k=da[k].next)--in[da[k].p];
	}
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d%d",&n,&m)!=EOF){
		dd=0;
		memset(tou,0,sizeof(tou));
		memset(in,0,sizeof(in));
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);++in[y];
		}
		Topo();
		printf("\n");
	}
	return 0;
}

