#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#define N 50
int F[N][N],ws[N]; 
int x,y,k,b;
int solve(int x){
	ws[0]=0;
	while (x)ws[++ws[0]]=x%b,x/=b;
	int i;
	for ( i=ws[0];i;i--)if (ws[i]!=1&&ws[i]!=0)break;
	for (;i;i--)ws[i]=1;
	ws[ws[0]+1]=0;
	int m=0;
	int lj=0;
	for (int i=ws[0];i;i--){
		if (ws[i])m+=F[i-1][k-lj];
		if (ws[i])lj++;
	}
	if (lj==k)++m;
	return m;
}
int main(){
	freopen("ural1057.in","r",stdin);
	freopen("ural1057.out","w",stdout);
	scanf("%d%d",&x,&y);
    scanf("%d%d",&k,&b);
    int ly=0;int lx=y;
	while (lx)ly++,lx/=b;
	F[0][0]=1;
	for (int i=1;i<=ly;i++) 
	  for (int j=0;j<=k;j++){
			F[i][j]+=F[i-1][j];
			if(j)F[i][j]+=F[i-1][j-1];
	    }
	printf("%d",solve(y)-solve(x-1));
	return 0;
}
