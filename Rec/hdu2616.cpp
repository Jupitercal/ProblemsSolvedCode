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
#define N 30
int n,m,ans;
struct aa{
	int x,y,f,b;
}poi[N];
void dfs(int x,int hp){
	if (hp<=0){
		if (ans>x)ans=x;
		return;
	} 
	for (int i=1;i<=n;i++)
	  if (!poi[i].b){
	  	poi[i].b=1;
	  	for (int j=1;j<=n;j++)
	  	  if (!poi[j].b&&poi[j].f==-1)
	  	    if (poi[j].y>=hp-poi[i].x){
	  	    	poi[j].x*=2;
	  	    	poi[j].f=x;
	  	    }
	  	if (x+1<ans)dfs(x+1,hp-poi[i].x);
	  	poi[i].b=0;
	  	for (int j=1;j<=n;j++)
	  	  if (poi[j].f==x)poi[j].f=-1,poi[j].x/=2;
	  }
}
int main(){
	freopen("hdu2616.in","r",stdin);
	freopen("hdu2616.out","w",stdout);
	while (scanf("%d%d",&n,&m)!=EOF){
		ans=0x5f5f5f5f;
		for (int i=1;i<=n;i++)scanf("%d%d",&poi[i].x,&poi[i].y);
		for (int i=1;i<=n;i++)poi[i].b=0,poi[i].f=-1;
		dfs(0,m);
		if (ans==0x5f5f5f5f)printf("-1\n");else printf("%d\n",ans);
	}
	return 0;
}
