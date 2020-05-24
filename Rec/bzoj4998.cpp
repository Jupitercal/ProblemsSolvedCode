#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 200000
struct aa{
	int p,next;
}da[N*2];
struct bian{
	int u,v;
}line[N],ask[N];
int dd,tou[N],n,m,q,fa[N],ff[N],tot[N],f[N],dep[N];
void add(int x,int y){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;
}
int find1(int x){
	return fa[x]==x?x:fa[x]=find1(fa[x]);
}
int find2(int x){
	return ff[x]==x?x:ff[x]=find2(ff[x]);
}
void dfs(int x){
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (v!=f[x]){
			dep[v]=dep[x]+1;
			f[v]=x;
			dfs(v);
		}
	}
}
void merge(int x,int y){
	x=find2(x),y=find2(y);
	while (x!=y){
		if (dep[x]>dep[y])std::swap(x,y);
		int fy=find2(f[y]);
		ff[y]=fy;tot[fy]+=tot[y];
		y=fy;
	}
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)fa[i]=i;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&line[i].u,&line[i].v);
		int fx=find1(line[i].u),fy=find1(line[i].v);
		if (fx!=fy)fa[fx]=fy,add(line[i].u,line[i].v),add(line[i].v,line[i].u);
	}
	for (int i=1;i<=q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		int fx=find1(u),fy=find1(v);
		if (fx!=fy)fa[fx]=fy,add(u,v),add(v,u);
		ask[i].u=u;ask[i].v=v;
	}
	for (int i=1;i<=n;i++)if (!dep[i])dfs(i);
	for (int i=1;i<=n;i++)fa[i]=ff[i]=i,tot[i]=1;
	for (int i=1;i<=m;i++){
		int u=line[i].u,v=line[i].v;
		int fx=find1(u),fy=find1(v);
		if (fx!=fy)fa[fx]=fy;
		else merge(u,v);
	}
	for (int i=1;i<=q;i++){
		int u=ask[i].u,v=ask[i].v;
		int fx=find1(u),fy=find1(v);
		if (fx!=fy)fa[fx]=fy,printf("No\n");
		else merge(u,v),printf("%d\n",tot[find2(v)]);
	}
	return 0;
}