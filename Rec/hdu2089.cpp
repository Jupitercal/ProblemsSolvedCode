#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#define N 30
int F[N][N],n,m,ws[N];
int solve(int x){
	if (!x)return x;
	ws[0]=0;
	while (x)ws[++ws[0]]=x%10,x/=10;
	ws[ws[0]+1]=0;  
	int m=0;
	for (int i=ws[0];i;i--){
		for (int j=0;j<ws[i];j++)
		  if (j!=4&&(!(j==2&&ws[i+1]==6)))m+=F[i][j];
		if (ws[i]==4||(ws[i]==2&&ws[i+1]==6))break;
	}
	return m;
} 
int main(){
	freopen("hdu2089.in","r",stdin);
	freopen("hdu2089.out","w",stdout);
	scanf("%d%d",&n,&m);
	F[0][0]=1;
	for (int i=1;i<=7;i++)
		for (int j=0;j<=9;j++)
		    for (int k=0;k<=9;k++)
		      if (j!=4&&(!(j==6&&k==2)))F[i][j]+=F[i-1][k];
	while (n!=0||m!=0){
		printf("%d\n",solve(m+1)-solve(n));
		scanf("%d%d",&n,&m);
	}
	return 0;
} 
