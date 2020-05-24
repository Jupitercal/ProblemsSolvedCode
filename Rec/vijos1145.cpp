#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#define N 3000 
double F[N][N];
int n,m,c;
int main(){
	freopen("vijos1145.in","r",stdin);
	freopen("vijos1145.out","w",stdout);
	scanf("%d",&c);
	while (c){
		scanf("%d%d",&n,&m);
		memset(F,0,sizeof(F));
		if (m<=c){
		   if(n>1000){ if(n%2==1) n=1001; else n=1000; }
		   F[0][0]=1;
		   for (int i=1;i<=n;i++)
		     for (int j=0;j<=std::min(c,i);j++){
			   if (j)F[i][j]+=F[(i-1)][j-1]*(c-j+1)/c;
			   if (j+1<=c&&j+1<=i+1)F[i][j]+=F[(i-1)][j+1]*(j+1)/c;	
		     }
		     printf("%.3f\n",F[n][m]);
	    }
		else printf("0.000\n");
		scanf("%d",&c);
	}
	return 0;
} 
