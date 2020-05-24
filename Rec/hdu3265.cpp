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
#define N 200005
typedef long long LL;
int n,lx,rx,num,flag[N];
LL tr[N],ans;
struct aa{
	int l,r,h,f;
}line[N*2];
void add(int x1,int x2,int h,int f){
	line[++num].l=x1;line[num].r=x2;line[num].h=h;line[num].f=f;
}
bool cmp(aa a,aa b){return a.h<b.h;}
void clac(int x,int ll,int rr,int l,int r,int c){
	if (l>r)return ;
	if (l<=ll&&rr<=r){
		flag[x]+=c;
		if (flag[x])tr[x]=rr-ll+1;
		else if (ll==rr)tr[x]=0;
		else tr[x]=tr[x*2]+tr[x*2+1];
		return ;
	}
	int mid=(ll+rr)/2;
	if (l<=mid)clac(x*2,ll,mid,l,r,c);
	if (r>mid)clac(x*2+1,mid+1,rr,l,r,c);
	if (flag[x])tr[x]=rr-ll+1;
		else if (ll==rr)tr[x]=0;
		else tr[x]=tr[x*2]+tr[x*2+1];
	//tr[x]=tr[x*2]+tr[x*2+1];
}
int main(){
	freopen("hdu3265.in","r",stdin);
	freopen("hdu3265.out","w",stdout);
	scanf("%d",&n);
	while (n){
		memset(flag,0,sizeof(flag));
		memset(tr,0,sizeof(tr));
		num=0;
		lx=0x5f5f5f5f;rx=0;
		for (int i=1;i<=n;i++){
			int x1,y1,x2,y2,x3,y3,x4,y4;
			scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
			add(x1,x2,y1,1);add(x1,x2,y3,-1);
			add(x1,x3,y3,1);add(x1,x3,y4,-1);
			add(x4,x2,y3,1);add(x4,x2,y4,-1);
			add(x1,x2,y4,1);add(x1,x2,y2,-1);
			lx=std::min(lx,x1);
			rx=std::max(rx,x2);
		}
		std::sort(line+1,line+num+1,cmp);
		ans=0;
		for (int i=1;i<num;i++){
			clac(1,lx,rx,line[i].l,line[i].r-1,line[i].f);
			ans+=tr[1]*(LL)(line[i+1].h-line[i].h);
		}
		printf("%I64d\n",ans);
		scanf("%d",&n);
	}
	return 0;
}
