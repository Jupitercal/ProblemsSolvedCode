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
struct aa{
	int x,y,z,ste;
}poi[3000];
int T,n;
int sqr(int x){return x*x;}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		int lx,ly,rx,ry;
		lx=ly=200;
		rx=ry=-200;
		for (int i=1;i<=n;i++){
			scanf("%d%d%d%d",&poi[i].x,&poi[i].y,&poi[i].z,&poi[i].ste);
			lx=std::min(lx,poi[i].x);
			ly=std::min(ly,poi[i].y);
			rx=std::max(rx,poi[i].x);
			ry=std::max(ry,poi[i].y);
		}
		double max=-0x5f5f5f5f;
		for (int i=lx;i<=rx;i++)
		  for (int j=ly;j<=ry;j++){
		  	double ans=0;
		  	for (int k=1;k<=n;k++){
		  		double R=sqrt(sqr(poi[k].x-i)+sqr(poi[k].y-j)+sqr(poi[k].z));
		  		ans+=poi[k].ste*poi[k].z/(R*R*R);
		  	}
		  	max=std::max(max,ans);
		  }
		printf("%.2f\n",max);
	}
	return 0;
}

