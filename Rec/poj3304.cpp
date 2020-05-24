#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 300
#define eps 1e-8
struct poi{
	double x,y;
};
struct aa{
	poi a,b;
}line[N];
int T,n;
bool d;
double xmul(poi x,poi a,poi b){
	return ((x.x-b.x)*(a.y-b.y)-(a.x-b.x)*(x.y-b.y));
}
double sqr(double x){return x*x;}
bool check(poi l,poi r){
	if (fabs(l.x-r.x)<eps&&fabs(l.y-r.y)<eps)return 0;
	for (int i=1;i<=n;i++){
		if (xmul(l,r,line[i].a)*xmul(l,r,line[i].b)>eps)return 0;
	}
	return 1;
}
void work(){
	d=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			if (check(line[i].a,line[j].b))d=1;
			if (check(line[i].a,line[j].a))d=1;
			if (check(line[i].b,line[j].b))d=1;
		}
}
int main(){
	freopen("poj3304.in","r",stdin);
	freopen("poj3304.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)scanf("%lf%lf%lf%lf",&line[i].a.x,&line[i].a.y,&line[i].b.x,&line[i].b.y);
		work();
		if (d||n<3)printf("Yes!\n");else printf("No!\n");
	}
	return 0;
}