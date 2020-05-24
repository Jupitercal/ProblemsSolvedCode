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
#define N 20000
int dfn[N],low[N],col[N],tail,stack[N],colors,sz;
int tou[N],dd,n,m,in[N],out[N];
bool v[N],f[N];
struct aa{
	int p,next;
}da[N*3];
void add(int x,int y){da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;}
void dit(int x){
	++colors;
	while (stack[tail]!=x){
		col[stack[tail]]=colors;
		f[stack[tail]]=0;
		--tail;
	}
	col[stack[tail]]=colors;
	f[stack[tail]]=0;
	--tail;
}
void dfs(int x){
	v[x]=f[x]=1;
	stack[++tail]=x;dfn[x]=low[x]=++sz; 
	for (int i=tou[x];i;i=da[i].next){
		int vi=da[i].p;
		if (!v[vi]){
			dfs(vi);
			low[x]=std::min(low[x],low[vi]);
		}else if (f[vi])low[x]=std::min(low[x],dfn[vi]);
	}
	if (dfn[x]==low[x])dit(x);
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d%d",&n,&m);
	sz=tail=colors=0;
	dd=0;memset(tou,0,sizeof(tou));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(v,0,sizeof(v));
	memset(f,0,sizeof(f));
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for (int i=1;i<=n;i++)
	  if (!v[i])dfs(i);
    int cnt=0;int gol=0;
	for (int i=1;i<=n;i++)
	  for (int j=tou[i];j;j=da[j].next){
	  	int vi=da[j].p;
	  	if (col[i]!=col[vi]){
	  		++out[col[i]];
	  		++in[col[vi]];
	  	}
	  }
	for (int i=1;i<=colors;i++)
	  if (!out[i])++cnt,gol=i;
	if (cnt!=1)printf("0");
	else {
		int ans=0;
		for (int i=1;i<=n;i++)
		  if (col[i]==gol)++ans;
		printf("%d",ans);
	}
	return 0;
}

