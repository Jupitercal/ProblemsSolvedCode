#include<bits/stdc++.h>
#define N 30005
int T,n,m,tou[N],dd,low[N],dfn[N],sz,tail,stack[N];
int col[N],colors,b[N][2];
bool f[N],v[N];
struct aa{
	int p,next;
}da[N*9];
void add(int x,int y){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;
}
void dit(int x){
	colors++;
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
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	int cases=0;
	scanf("%d",&T);
	while (T--){
		memset(tou,0,sizeof(tou));
		sz=dd=colors=0;
		tail=0;
		memset(v,0,sizeof(v));
		memset(f,0,sizeof(f));
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			b[i][0]=x%3;
			b[i][1]=(x+1)%3;
		}
		for (int i=1;i<=m;i++){
			int A,B,K;
			scanf("%d%d%d",&A,&B,&K);
			if (K==1){
				if (b[A][0]==b[B][0])add(2*A-1,2*B),add(2*B-1,2*A);
				if (b[A][0]==b[B][1])add(2*A-1,2*B-1),add(2*B,2*A);
				if (b[A][1]==b[B][0])add(2*A,2*B),add(2*B-1,2*A-1);
				if (b[A][1]==b[B][1])add(2*A,2*B-1),add(2*B,2*A-1);
			}else{
				if (b[A][0]!=b[B][0])add(2*A-1,2*B),add(2*B-1,2*A);
				if (b[A][0]!=b[B][1])add(2*A-1,2*B-1),add(2*B,2*A);
				if (b[A][1]!=b[B][0])add(2*A,2*B),add(2*B-1,2*A-1);
				if (b[A][1]!=b[B][1])add(2*A,2*B-1),add(2*B,2*A-1);
			}
		}
		for (int i=1;i<=2*n;i++)if (!v[i])dfs(i);
		bool F=0;
		for (int i=1;i<=n;i++){
			if (col[i*2-1]==col[i*2]){
				F=1;
				break;
			}
		}
		printf("Case #%d: ",++cases);
		if (!F)printf("yes\n");
		else printf("no\n");
	}
	return 0;
}