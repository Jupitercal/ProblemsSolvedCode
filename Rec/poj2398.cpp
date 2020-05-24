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
int ans[N],ac[N];
bool ba;
bool cmp(const kk& l1, const kk& l2) {  
    if (std::min(l1.a.x, l1.b.x) == std::min(l2.a.x, l1.b.x))  
        return std::max(l1.a.x, l1.b.x) < std::max(l2.a.x, l1.b.x);  
    return std::min(l1.a.x, l1.b.x) < std::min(l2.a.x, l1.b.x);  
}  
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
	std::sort(line,line+n+1,cmp);
}
void work(){
	poi p;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&p.x,&p.y);
		ans[poc(p)]++;
	}
	printf("Box\n");
	for (int i=0;i<n;i++)++ac[ans[i]];
	for (int i=1;i<=n;i++)if (ac[i])printf("%d: %d\n",i,ac[i]);
}
int main(){
	freopen("poj2398.in","r",stdin);
	freopen("poj2398.out","w",stdout);
	scanf("%d",&n);
	while (n){
		memset(ans,0,sizeof(ans));
		memset(ac,0,sizeof(ac));
		scanf("%d%d%d%d%d",&m,&le.x,&le.y,&ri.x,&ri.y);
		init();
		work();
		scanf("%d",&n);
	}
	return 0;
}