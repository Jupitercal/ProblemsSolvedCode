#include<bits/stdc++.h>
#define N 6000
struct aa{
	int p,next;
}da[N*N/6];
int colors,n,tail,sz,tou[N],dd,m,dfn[N],low[N],stack[N],col[N];
bool v[N],f[N];
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
void add(int x,int y){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d%d",&n,&m)!=EOF){
		memset(tou,0,sizeof(tou));
		dd=0;
		sz=0;tail=0;
		colors=0;
		memset(v,0,sizeof(v));
		memset(f,0,sizeof(f));
		for (int i=1;i<=m;i++){
			int a1,a2,c1,c2;
			scanf("%d%d%d%d",&a1,&a2,&c1,&c2);
			++a1,++a2;
			if (c1==0){
				if (c2==0) add(2*a1-1,2*a2),add(2*a2-1,2*a1);
				else add(2*a1-1,2*a2-1),add(2*a2,2*a1);
			}else {
				if (c2==0)add(2*a1,2*a2),add(2*a2-1,2*a1-1);
					else add(2*a1,2*a2-1),add(2*a2,2*a1-1);
			}
		}
		for (int i=1;i<=2*n;i++)
			if (!v[i])dfs(i);
		bool f=1;
		for (int i=1;i<=n;i++)
			if (col[2*i]==col[2*i-1]){
				f=0;
				break;
			}
		if (f)	printf("YES\n");
			else printf("NO\n");
	}
	return 0;
}