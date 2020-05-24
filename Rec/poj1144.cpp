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
#define N 2000
struct aa{
	int p,next;
}da[N];
int dd,dfn[N],low[N],tou[N],m,n,root,v[N],f[N],stack[N]; 
int tail,sz;
bool B[N];
void dit(int x){
	while (stack[tail]!=x)f[stack[tail]]=0,--tail;
	--tail;
}
void dfs(int x){
	dfn[x]=low[x]=++sz;v[x]=f[x]=1;
	stack[++tail]=x;
	int son=0;
	for (int i=tou[x];i;i=da[i].next){
		int vi=da[i].p;
		if (!v[vi]){
			dfs(vi);
			++son;
			if ((son>1&&x==root)||(x!=root&&dfn[x]<=low[vi]))B[x]=1;
			low[x]=std::min(low[x],low[vi]);
		}else if (f[vi])low[x]=std::min(low[x],dfn[vi]);
	}
	if (low[x]==dfn[x])dit(x);
}
void add(int x,int y){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d",&m)&&m!=0){
		memset(da,0,sizeof(da));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(tou,0,sizeof(tou));
		memset(f,0,sizeof(f));
		memset(v,0,sizeof(v));
		dd=0;
		memset(B,0,sizeof(B));
		tail=0;sz=0;
		while (scanf("%d",&n)&&n!=0){
			while (getchar()!='\n'){
				int x;
				scanf("%d",&x);
				add(x,n);
			}
		}
		root=1;
		dfs(1);
		int ans=0;
		for (int i=1;i<=m;i++)
		  if (B[i])++ans;
		printf("%d\n",ans);
	}
	return 0;
}
