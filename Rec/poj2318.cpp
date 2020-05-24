#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 10000
struct poi{
	int x,y;
}le,ri;
struct kk{
	poi a,b;
}line[N];
int xmul(poi x,poi a,poi b){
	return ((x.x-b.x)*(x.y-a.y)-(x.x-a.x)*(x.y-b.y));
}
int n,m;
int ans[N];
bool ba;
int poc(poi a){
	int l=0;int r=n;
	while (l+1<r){
		int mid=(l+r)/2;
		if (xmul(a,line[mid].a,line[mid].b)<=0)l=mid;
		else r=mid;
	}
	for (int i=l;i<=r;i++)
		if (xmul(a,line[l].a,line[l].b)<=0&&xmul(a,line[l+1].a,line[l+1].b)>=0)return i;
	return 0;
}
void init(){
	line[0].a.x=le.x;line[0].a.y=le.y;
	line[0].b.x=le.x;line[0].b.y=ri.y;
	for (int i=1;i<=n;i++){
		int x1,x2;
		scanf("%d%d",&x1,&x2);
		line[i].a.x=x1;line[i].a.y=le.y;
		line[i].b.x=x2;line[i].b.y=ri.y;
	}
	line[++n].a.x=ri.x;line[n].a.y=le.y;
	line[n].b.x=ri.x;line[n].b.y=ri.y;
}
void work(){
	poi p;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&p.x,&p.y);
		ans[poc(p)]++;
	}
	for (int i=0;i<n;i++)printf("%d: %d\n",i,ans[i]);
}
int main(){
	freopen("poj2318.in","r",stdin);
	freopen("poj2318.out","w",stdout);
	scanf("%d",&n);
	ba=0;
	while (n){
		memset(ans,0,sizeof(ans));
		scanf("%d%d%d%d%d",&m,&le.x,&le.y,&ri.x,&ri.y);
		if (ba)printf("\n");
		ba=1;
		init();
		work();
		scanf("%d",&n);
	}
	return 0;
}