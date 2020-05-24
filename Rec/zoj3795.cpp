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
#define N 100010
int stack[N],dfn[N],low[N],tail,sz,dd,tou[N];
int to[N],col[N],color,dm,cnt[N],n,m,F[N],du[N];
bool f[N],v[N];
struct aa{
	int p,next;
}da[N*4],db[N*4];
void dit(int x){
	++color;
	while (stack[tail]!=x){
		f[stack[tail]]=0;
		col[stack[tail]]=color;
		tail--;
	}
	col[stack[tail]]=color;
	f[stack[tail]]=0;--tail;
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
	if (low[x]==dfn[x])dit(x);
}
void add(int x,int y,bool b){
	if (b){
		da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;
	}else{
		db[++dm].p=y;db[dm].next=to[x];to[x]=dm;
	}
}
int dfz(int x,int fa){
	if (F[x]!=-1)return F[x];
	F[x]=0;
	int ma=0;
	for (int i=to[x];i;i=db[i].next){
		int vi=db[i].p;
		if (vi==fa)continue;
		dfz(vi,x);
		ma=std::max(ma,F[vi]);
	}
	F[x]=ma+cnt[x];
	return F[x];
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d%d",&n,&m)!=EOF){
		tail=dm=dd=sz=color=0;
		memset(dfn,0,sizeof(dfn));
		memset(tou,0,sizeof(tou));
		memset(low,0,sizeof(low));
		memset(to,0,sizeof(to));
		memset(cnt,0,sizeof(cnt));
		memset(col,0,sizeof(col));
		memset(v,0,sizeof(v));
		memset(f,0,sizeof(f));
		memset(F,-1,sizeof(F));
		memset(du,0,sizeof(du));
		for (int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y,1);
		}
		for (int i=1;i<=n;i++)
		  if (!v[i])dfs(i);
		for (int i=1;i<=n;i++)
		  if (!col[i]){
		  	col[i]=++color;
		  	cnt[color]=1;
		  }else ++cnt[col[i]];
		for (int i=1;i<=n;i++)
		 for (int j=tou[i];j;j=da[j].next)
		   if (col[i]!=col[da[j].p])add(col[i],col[da[j].p],0),++du[col[da[j].p]];
		int ans=0;
		for (int i=1;i<=color;i++)
		  if (!du[i]){
		  	dfz(i,0);
		  	ans=std::max(ans,F[i]);
		  }
		printf("%d\n",ans);
	}
	return 0;
}

