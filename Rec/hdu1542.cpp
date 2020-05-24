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
#define N 1000
struct aa{
	double x;
	double y1,y2; 
	int f;
}line[N*5];
double y[N*5];
struct node{
	double x,y1,y2;
	int cover;
	bool f;
}tree[N*10];
int n;
int tot1,tot2;
bool cmp(aa a,aa b){return a.x<b.x;}
void build(int x,int l,int r){
	tree[x].y1=y[l];
	tree[x].y2=y[r];
	tree[x].x=0;
	tree[x].f=0;
	tree[x].cover=0;
	if (l+1==r){
		tree[x].f=1;
		return ;
	}
	build(x*2,l,(l+r)/2);
	build(x*2+1,(l+r)/2,r);
} 
double insert(int x,double x1,double y1,double y2,int f){
	if (y2<=tree[x].y1||tree[x].y2<=y1)return 0;
	if (tree[x].f){
		double cla=0;
		if (tree[x].cover>0){
			cla+=(x1-tree[x].x)*(tree[x].y2-tree[x].y1);
			tree[x].cover+=f;
			tree[x].x=x1;
		}else{
			tree[x].cover+=f;
			tree[x].x=x1;
		}
		return cla;
	}
	return insert(x*2,x1,y1,y2,f)+insert(x*2+1,x1,y1,y2,f);
}
void add(double x,double y1,double y2,int f){
	line[++tot1].x=x;line[tot1].y1=y1;line[tot1].y2=y2;line[tot1].f=f;
} 
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	int cases=0;
	scanf("%d",&n);
	while (n){
		tot1=tot2=0;
		for (int i=1;i<=n;i++){
			double x1,x2,y1,y2;
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			add(x1,y1,y2,1);
			add(x2,y1,y2,-1);
			y[++tot2]=y1;
			y[++tot2]=y2;
		}
		std::sort(y+1,y+tot2+1);
		std::sort(line+1,line+tot1+1,cmp);
		build(1,1,tot2);
		double ans=0;
		for (int i=1;i<=tot1;i++)
			ans+=insert(1,line[i].x,line[i].y1,line[i].y2,line[i].f);
		++cases;
		printf("Test case #%d\n",cases); 
        printf("Total explored area: %.2f\n\n",ans);
		scanf("%d",&n);
	}
	return 0;
}
