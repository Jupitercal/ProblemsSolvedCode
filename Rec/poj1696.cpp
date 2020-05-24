#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 300
#define eps 1e-8
struct poi{
	int x,y,id;
}stack[N],pt[N],point;
int T,n,top;
int sqr(int x){return x*x;}
double dist(poi a,poi b){return (sqrt((double)sqr(a.x-b.x)+(double)sqr(a.y-b.y)));}
int xmul(poi a,poi b,poi x){return ((a.x-x.x)*(b.y-x.y)-(b.x-x.x)*(a.y-x.y));}
bool cmp(poi a,poi b){
	int k=xmul(a,b,point);
	if (k>0)return true;
	if (k<0)return false;
	double k1=dist(a,point);
	double k2=dist(b,point);
	if (k1-k2<eps)return false;
	else return true;
}
void Findpoint(){
	point=pt[1];
	int tm=1;
	for (int i=2;i<=n;i++){
		if (point.y>pt[i].y||(point.y==pt[i].y&&point.x>pt[i].x)){
			tm=i;
			point=pt[i];
		}
	}
	pt[tm]=pt[1];
	pt[1]=point;
}
int main(){
	freopen("poj1696.in","r",stdin);
	freopen("poj1696.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)scanf("%d%d%d",&pt[i].id,&pt[i].x,&pt[i].y);
		printf("%d",n);
		Findpoint();
		for (int i=1;i<=n;i++){
		    printf(" %d",point.id);
			std::sort(pt+i+1,pt+1+n,cmp);
			point=pt[i+1];
		}
		printf("\n");
	}
	return 0;
}