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
struct aa{
	int p,next;
}da[N*6];
struct ne{
	int x,y;
}line[N*6];
int dfn[N],low[N],col[N],stack[N],sz,color,tail;
int in[N],tot,out[N],ans1,ans2,dd,n,tou[N];
bool v[N],f[N];
void dit(int x){
	++color;
	while (stack[tail]!=x){
		col[stack[tail]]=color;
		tail--;
	}
	col[stack[tail]]=color;
	tail--;
}
void dfs(int x){
	dfn[x]=low[x]=++sz;v[x]=f[x]=1;
	stack[++tail]=x;
	for (int i=tou[x];i;i=da[i].next){
		int vi=da[i].p;
		if (!v[vi]){
			dfs(vi);
			low[x]=std::min(low[x],low[vi]);
		}else if (f[vi])low[x]=std::min(low[x],dfn[vi]);
	}
	if (dfn[x]==low[x])dit(x);
}
void add(int x,int y){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		memset(tou,0,sizeof(tou));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(col,0,sizeof(col));
		memset(v,0,sizeof(v));
		memset(f,0,sizeof(f));
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		color=0;dd=0;tot=0;tail=0;sz=0;
		ans1=ans2=0;
		for (int i=1;i<=n;i++){
			int c;
			scanf("%d",&c);
			while (c){
				if (c==i){
					scanf("%d",&c);
					continue;
				}
				++tot;
				add(i,c);
				line[tot].x=i;
				line[tot].y=c;
				scanf("%d",&c);
			}
		}
		for (int i=1;i<=n;i++)
		  if (!v[i])dfs(i);
		for (int i=1;i<=n;i++)
		  if (!col[i])col[i]=++color;		
		for (int i=1;i<=tot;i++){
			int x1=col[line[i].x];
			int y1=col[line[i].y];
			if (x1!=y1){
				++out[x1];
				++in[y1];
			}
		}
		for (int i=1;i<=color;i++){
			if (!in[i])++ans1;
			if (!out[i])++ans2;
		}
		if (color==1)printf("1\n0\n");
		else printf("%d\n%d\n",ans1,std::max(ans1,ans2));
	}
	return 0;
}

