#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 300
#define eps 1e-8
#define INF 0x3f3f3f3f
struct poi{
	double x,y;
}po[N*N];
struct kk{
	poi a,b;
}line[N];
int n,num;
bool B[N][N];
double dist[N][N];
double sqr(double x){return x*x;}
double xmul(poi x,poi a,poi b){
	return ((x.x-b.x)*(a.y-b.y)-(a.x-b.x)*(x.y-b.y));
}
bool check(poi l,poi r){
	if (fabs(l.x-r.x)<eps&&fabs(l.y-r.y)<eps)return 1;
	for (int i=1;i<=3*n;i++)
		if (r.x-line[i].b.x>eps&&line[i].a.x-l.x>eps)
		  if (xmul(l,r,line[i].a)*xmul(l,r,line[i].b)<eps)return 0;
	return 1;
}
void floyd(){
	for (int i=1;i<=num;i++)
		for (int j=1;j<=num;j++)
			if (B[i][j])dist[i][j]=sqrt(sqr(po[i].x-po[j].x)+sqr(po[i].y-po[j].y));
			else dist[i][j]=INF;
	for (int k=1;k<=num;k++)
		for (int i=1;i<=num;i++)
			for (int j=1;j<=num;j++)
				if (dist[i][j]-(dist[i][k]+dist[k][j])>eps)dist[i][j]=dist[i][k]+dist[k][j];
}
void init(){
	for (int i=1;i<=num;i++)
		for (int j=1;j<=num;j++)
			B[i][j]=check(po[i],po[j]);
}
int main(){
	freopen("poj1556.in","r",stdin);
	freopen("poj1556.out","w",stdout);
	scanf("%d",&n);
	while (n!=-1){
		num=0;
		po[++num].x=0;
		po[num].y=5;
		for (int i=1;i<=n;i++){
			double x;
			scanf("%lf%lf%lf%lf%lf",&x,&line[3*i-2].b.y,&line[3*i-1].a.y,&line[3*i-1].b.y,&line[3*i].a.y);
			line[3*i-1].a.x=line[3*i-1].b.x=line[3*i-2].a.x=line[3*i-2].b.x=line[3*i].a.x=line[3*i].b.x=x;
			line[3*i-2].a.y=0;line[3*i].b.y=10;
			po[++num].x=x;po[num].y=line[3*i-2].b.y;
			po[++num].x=x;po[num].y=line[3*i-1].a.y;
			po[++num].x=x;po[num].y=line[3*i-1].b.y;
			po[++num].x=x;po[num].y=line[3*i].a.y;
		}
		po[++num].x=10;po[num].y=5;
		init();
		floyd();
		printf("%.2f\n",dist[1][num]);
		scanf("%d",&n);
	}
	return 0;
}