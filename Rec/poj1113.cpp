#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define eps 1e-12
#define N 2000
const double pi=acos(-1.0);
struct poi{
	int x,y;
}pt[N],stack[N],point;
int n,top,l;
double dist;
int sqr(int x){return x*x;}
int xmul(poi a,poi b,poi x){return ((a.x-x.x)*(b.y-x.y)-(a.y-x.y)*(b.x-x.x));}
double dis(poi a,poi b){return sqrt((double)sqr(a.x-b.x)+(double)sqr(a.y-b.y));}
bool cmp(poi a,poi b){
	int k=xmul(a,b,point);
	if (k>0)return true;
	if (k<0)return false;
	double k1=dis(a,point);
	double k2=dis(b,point);
	return k1<k2;
}
void Findpoint(){
	point=pt[1];
	int tm=1;
	for (int i=2;i<=n;i++)
		if ((pt[i].y<point.y)||( pt[i].y==point.y&&pt[i].x<point.x)){
			tm=i;
			point=pt[i];
		}
	pt[tm]=pt[1];
	pt[1]=point;
}
void Graham(){
    if(n==1) {top=0;stack[0]=pt[1];}
    if(n==2)
    {
        top=1;
        stack[0]=pt[1];
        stack[1]=pt[2];
    }    
    if(n>2)
    {
        for(int i=1;i<=2;i++) stack[i-1]=pt[i];
        top=1;
        
        for(int i=3;i<=n;i++)
        {
            while(top>0&&xmul(stack[top],pt[i],stack[top-1])<=0) top--;
            stack[++top]=pt[i];
        }    
    }    

}
int main(){
	freopen("poj1113.in","r",stdin);
	freopen("poj1113.out","w",stdout);
	while (scanf("%d%d",&n,&l)!=EOF){
	    for (int i=1;i<=n;i++)scanf("%d%d",&pt[i].x,&pt[i].y);
	    Findpoint();
	    std::sort(pt+2,pt+n+1,cmp);
	    Graham();
	    dist=2*pi*l;
	    for (int i=1;i<=top;i++)dist+=dis(stack[i],stack[i-1]);
	    dist+=dis(stack[0],stack[top]);
		dist+=0.5;
	    printf("%d\n",(int)dist);
	}
	return 0;
}