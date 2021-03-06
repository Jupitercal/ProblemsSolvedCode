#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#define N 130000
int root[N*2],q[N*2],ls[N*18],rs[N*18],c[N*18];
int n,m,Q,wz[N],val[N*2],f[N*2],fa[N*2][18],tou[N*2],dd,top;
int st[N*2],ed[N*2],tot,ma[N*2][18];
bool vis[N];
struct aa{
	int len,x,y;
}dz[N*6];
struct pp{
	int va,pos;
}poi[N];
struct az{
	int p,next;
}da[N*4];
inline bool cmp(const aa a,const aa b){return a.len<b.len;}
inline bool cm(pp a,pp b){return a.va<b.va;}
int build(int l,int r){
	int rt=++tot;
	c[rt]=0;
	if (l==r)return rt;
	int mid=(l+r)/2;
	if (l<=mid)ls[rt]=build(l,mid);
	if (mid+1<=r)rs[rt]=build(mid+1,r);
	return rt;
}
int update(int rt,int pos){
	int tmp,rt1;tmp=rt1=++tot;
	int l=1;int r=n;
	c[rt1]=c[rt]+1;
	while (l<r){
		int mid=(l+r)/2;
		if (pos<=mid){
			ls[rt1]=++tot;rs[rt1]=rs[rt];
			rt1=ls[rt1];rt=ls[rt];
			r=mid;
		}else{
			rs[rt1]=++tot;ls[rt1]=ls[rt];
			rt1=rs[rt1];rt=rs[rt];
		    l=mid+1;
		} 
		c[rt1]=c[rt]+1;
	}
	return tmp;
}
int query(int rt,int rt1,int l,int r,int pos){
	while (l<r){
		int mid=(l+r)/2;
		int num=c[ls[rt1]]-c[ls[rt]];
		if (pos<=num){
			rt1=ls[rt1];rt=ls[rt];
			r=mid;
		}else{
			pos-=num;
			rt1=rs[rt1];rt=rs[rt];
			l=mid+1;
		} 
	}
	return poi[l].va;
}
//-----------------------------------------主席树 
void add(int x,int y){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;
}
//-----------------------------------------建边 
int find(int x){
	if (f[x]==x)return x;
	f[x]=find(f[x]);
	return f[x];
}
//-----------------------------------------并查集
int findd(int x,int va){
	for (int i=17;i>=0;i--)
	  if (fa[x][i]&&ma[x][i]<=va)x=fa[x][i];
	return x;
}
void dfs(int x){
	q[++top]=x;vis[x]=1;
	for (int i=1;i<=17;i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
		ma[x][i]=std::max(ma[x][i-1],ma[fa[x][i-1]][i-1]);
		if (!fa[x][i])break;
	}
	for (int i=tou[x];i;i=da[i].next){
		fa[da[i].p][0]=x;
		ma[da[i].p][0]=val[x];
		dfs(da[i].p);
	}
	if(x>n)q[++top]=x;
}
//-----------------------------------------dfs序+倍增 
void tree_build(){
	int nod=n;
	for (int i=1;i<=2*n;i++)f[i]=i;
	for (int i=1;i<=m;i++){
		int fx=find(dz[i].x);
		int fy=find(dz[i].y);
		if (fx!=fy){
			f[fx]=f[fy]=++nod;
			val[nod]=dz[i].len;
			add(nod,fx);add(nod,fy);
			if (nod==2*n-1)break;
		}
	}
	for (int i=1;i<=n;i++)
	  if (!vis[i])dfs(find(i));
	for (int i=1;i<=top;i++){
		int x=q[i];
		if (x<=n)root[i]=update(root[i-1],wz[x]);
		else{
			root[i]=root[i-1];
			if (!st[x])st[x]=i;
			else ed[x]=i;
		}
	}
}
void tree_solve(){
	int last;
	last=-1;
	for (int i=1;i<=Q;i++){
		int x,v,k;
		scanf("%d%d%d",&v,&x,&k);
		if (last!=-1)v=v^last,x=x^last,k=k^last;
		int nods=findd(v,x);
		if (c[root[ed[nods]]]-c[root[st[nods]]]<k)printf("-1\n"),last=-1;
		else {
			last=query(root[st[nods]],root[ed[nods]],1,n,c[root[ed[nods]]]-c[root[st[nods]]]+1-k);
			printf("%d\n",last);
		}
	}
}
//-----------------------------------------主程序 
int main(){
	freopen("bzoj3551.in","r",stdin);
	freopen("bzoj3551.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q);
	for (int i=1;i<=n;i++)scanf("%d",&poi[i].va),poi[i].pos=i;
	std::sort(poi+1,poi+n+1,cm);
	root[0]=build(1,n);
	for (int i=1;i<=n;i++)wz[poi[i].pos]=i;
	for (int i=1;i<=m;i++)
		scanf("%d%d%d",&dz[i].x,&dz[i].y,&dz[i].len);
	std::sort(dz+1,dz+m+1,cmp);
	tree_build();
	tree_solve();
	return 0;
}
