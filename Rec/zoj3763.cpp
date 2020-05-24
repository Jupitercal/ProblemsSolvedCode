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
#define N 1005
typedef double db;
int xx,yy,c,t;
int x[N],y[N],vx[N],vy[N],n,ans;
db dx,dy;
bool solve(db x1,db y1,db v1,db v2){
	dx=x1-xx;
	dy=y1-yy;
	db A=v1*v1+v2*v2-c*c;
	db B=2*dx*v1+2*dy*v2;
	db C=dx*dx+dy*dy;
	if (A>0){
		db delta=B*B-4*A*C;
		if (delta<0) return 0;
		db lx=(-B-sqrt(delta))/2/A;
		if ((lx>=0&&lx<=t*1.0))return 1;
	}else if (A<0){
		db delta=B*B-4*A*C;
		if (delta<0)return 1;
		db lx=(-B-sqrt(delta))/2/A;
		db rx=(-B+sqrt(delta))/2/A;
		if ((lx>=0&&lx<=t*1.0)||(rx>0&&rx<=t*1.0))return 1;
	}else if (A==0){
		db T=(-dx*dx+-dy*dy)/(2*dx*v1+2*dy*v2);
		if (T>=0&&T<=t*1.0)return 1;
	}
	return 0;
}
int main(){
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
	while (scanf("%d%d%d%d",&xx,&yy,&c,&t)!=EOF){
		scanf("%d",&n);ans=0;
		for (int i=1;i<=n;i++){
			scanf("%d%d%d%d",&x[i],&y[i],&vx[i],&vy[i]);
			ans+=solve(x[i]*1.0,y[i]*1.0,vx[i]*1.0,vy[i]*1.0)|
			solve(x[i]+vx[i]*t*2*1.0,y[i]+vy[i]*t*2*1.0,-vx[i]*1.0,-vy[i]*1.0);
		}
		printf("%d\n",ans);
	}
	return 0;
}
