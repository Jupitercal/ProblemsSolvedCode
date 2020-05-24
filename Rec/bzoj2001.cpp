#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#define INF 0x3f3f3f3f 
#define N 60000
typedef long long LL;
int size[N],fa[N],c[N],a[N],sum[N],n,m,q;
LL ans[N];
struct que{
	int x,y,pos;
}Q[N];
struct aa{
	int l,r,w,pos;
}e[30][N],t[N],d[N];
inline bool cmp(const aa a,const aa b){return a.w<b.w;}
int find(int x){
	if (fa[x]==x)return fa[x];
	return fa[x]=find(fa[x]);
}
void clear(int tot){
	for (int i=1;i<=tot;i++){
		fa[d[i].l]=d[i].l;
		fa[d[i].r]=d[i].r;
		size[d[i].l]=size[d[i].r]=1;
	}
}
void merge(int x,int y){
	if (size[x]<size[y])fa[x]=y,size[y]+=size[x];
	else fa[y]=x,size[x]+=size[y]; 
}
void reduction(int &tot){
	clear(tot);
	std::sort(d+1,d+tot+1,cmp);
	int tmp=0;
	for (int i=1;i<=tot;i++){
		int fx=find(d[i].l);
		int fy=find(d[i].r);
		if (fx!=fy){
			merge(fx,fy);t[++tmp]=d[i];c[d[i].pos] = tmp;
		}else if (d[i].w==INF){
			t[++tmp]=d[i];c[d[i].pos] = tmp;
		}
	}
	for (int i=1;i<=tmp;i++)d[i]=t[i];
	tot=tmp;
}
void contraction(int &tot,LL &cnt){
	clear(tot);
	std::sort(d+1,d+tot+1,cmp);
	int tmp=0;
	for (int i=1;i<=tot;i++){
		int fx=find(d[i].l);
		int fy=find(d[i].r);
		if (fx!=fy){
			merge(fx,fy);t[++tmp]=d[i];
		} 
	}
	for (int i=1;i<=tmp;i++){
		fa[t[i].l]=t[i].l;
		fa[t[i].r]=t[i].r;
		size[t[i].l]=size[t[i].r]=1; 
	} 
	for (int i=1;i<=tmp;i++){
		int fx=find(t[i].l);
		int fy=find(t[i].r);
		if (fx!=fy&&t[i].w!=-INF){
			merge(fx,fy);cnt+=t[i].w;
		} 
	}
	tmp=0;
	for (int i=1;i<=tot;i++){
		int fx=find(d[i].l);
		int fy=find(d[i].r);
		if (fx!=fy){
			t[++tmp]=d[i];
			c[d[i].pos]=tmp;
			t[tmp].l=fx;
			t[tmp].r=fy;
		}
	}
	for (int i=1;i<=tmp;i++)d[i]=t[i];
	tot=tmp;
}
void solve(int l,int r,int now,LL cnt){
	if (l==r)a[Q[l].x]=Q[l].y;
	int tot=sum[now];
	for (int i=1;i<=tot;i++)e[now][i].w=a[e[now][i].pos];
	for (int i=1;i<=tot;i++)d[i]=e[now][i],c[d[i].pos] = i;
	if (l==r){
		ans[l]=cnt;
		clear(tot);
		std::sort(d+1,d+tot+1,cmp);
		for (int i=1;i<=tot;i++){
			int fx=find(d[i].l);
			int fy=find(d[i].r);
			if (fx!=fy){
				merge(fx,fy);ans[l]+=d[i].w;
			} 
		}
		return ;
	}
	for (int i=l;i<=r;i++)d[c[Q[i].x]].w=-INF;
	contraction(tot,cnt);
	for (int i=l;i<=r;i++)d[c[Q[i].x]].w=INF;
	reduction(tot);
	for (int i=1;i<=tot;i++)e[now+1][i]=d[i];
	int mid=(l+r)/2;
	sum[now+1]=tot;
	solve(l,mid,now+1,cnt);
	solve(mid+1,r,now+1,cnt);
}
int main(){
	freopen("bzoj2001.in","r",stdin);
	freopen("bzoj2001.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&e[0][i].l,&e[0][i].r,&e[0][i].w),e[0][i].pos=i;
		a[i]=e[0][i].w;
	}
	for (int i=1;i<=q;i++)
	    scanf("%d%d",&Q[i].x,&Q[i].y);
	sum[0]=m;
	solve(1,q,0,0);
	for (int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;
}
