#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 2100000
#define M 210000
typedef long long LL;
struct aa{
	int x,y,pos,v,cl;
	bool op;
}poi[M],tmp[M];
int num[N],s,w,count,anx;
LL ans[M];
bool cmp(aa a,aa b){return ((a.x<b.x)||(a.x==b.x&&a.y<b.y)||(a.x==b.x&&a.y==b.y&&a.op>b.op));}
void plus(int x,int v){
	while (x<=w){
		num[x]+=v;
		x+=x&(-x);
	}
}
LL sum(int x){
	LL m=0;
	while (x){
		m+=num[x];
		x-=x&(-x);
	}
	return m;
}
void solve(int l,int r){
	if (l>=r)return;
	int mid=(l+r)/2;
	for (int i=l;i<=r;i++){
		if (poi[i].pos<=mid&&poi[i].op)plus(poi[i].y,poi[i].v);
		if (poi[i].pos>mid&&!poi[i].op)ans[poi[i].cl]+=poi[i].v*sum(poi[i].y);
	}
	for (int i=l;i<=r;i++)if (poi[i].pos<=mid&&poi[i].op)plus(poi[i].y,-poi[i].v);
	int l1=l;int l2=mid+1;
	for (int i=l;i<=r;i++){
		if (poi[i].pos<=mid)tmp[l1++]=poi[i];
		else tmp[l2++]=poi[i];
	}
	for (int i=l;i<=r;i++)poi[i]=tmp[i];
	solve(l,mid);
	solve(mid+1,r);
}
int main(){
	freopen("bzoj1176.in","r",stdin);
	freopen("bzoj1176.out","w",stdout);
	scanf("%d%d",&s,&w);
	int o;
	scanf("%d",&o);
	while (o!=3){
		if (o==1){
			int x,y,a;
			scanf("%d%d%d",&x,&y,&a);
			poi[++count].x=x;poi[count].y=y;poi[count].op=1;poi[count].pos=count;poi[count].v=a;
		}else if (o==2){
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			++anx;
			ans[anx]=(x2-x1)*(y2-y1)*s;
			poi[++count].x=x1-1;poi[count].y=y1-1;poi[count].op=0;poi[count].pos=count;poi[count].v=1;poi[count].cl=anx;
			poi[++count].x=x1-1;poi[count].y=y2;poi[count].op=0;poi[count].pos=count;poi[count].v=-1;poi[count].cl=anx;
			poi[++count].x=x2;poi[count].y=y1-1;poi[count].op=0;poi[count].pos=count;poi[count].v=-1;poi[count].cl=anx;
			poi[++count].x=x2;poi[count].y=y2;poi[count].op=0;poi[count].pos=count;poi[count].v=1;poi[count].cl=anx;
		}
		scanf("%d",&o);
	}
	std::sort(poi+1,poi+count+1,cmp);
	solve(1,count);
	for (int i=1;i<=anx;i++)printf("%lld\n",ans[i]);
	return 0;
}