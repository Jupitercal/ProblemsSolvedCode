#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
int n,ws[20];
int F[11][10][13][2];
int po(int x,int l){
	int m=1;
	for (int i=1;i<=l;i++)m*=10;
	return m;
}
int solve(int x){
	int m=0;
	int ys=0;
	ws[0]=0;
	while (x)ws[++ws[0]]=x%10,x/=10;
	ws[ws[0]+1]=0;
	bool b=0;
	for (int i=ws[0];i>=0;i--){
		for (int j=0;j<ws[i];j++){
			if (b)m+=F[i][j][(13-ys)%13][0]+F[i][j][(13-ys)%13][1];
			  else if (ws[i+1]==1&&j==3)m+=F[i][j][(13-ys)%13][0]+F[i][j][(13-ys)%13][1];
			  else m+=F[i][j][(13-ys)%13][1];
		}
		if (ws[i]==3&&ws[i+1]==1)b=1;
		ys=(ys+ws[i]*po(10,i-1))%13;
	}
	return m;
}
int main(){
	freopen("hdu3652.in","r",stdin);
	freopen("hdu3652.out","w",stdout);
	F[0][0][0][0]=1;
	for (int i=1;i<=10;i++)
	  for (int j=0;j<10;j++)
	    for (int k=0;k<10;k++)
	     for (int ys=0;ys<13;ys++)
	      for (int l=0;l<2;l++){
				if (l==1){
					if (j==1&&k==3)F[i][j][(ys+j*po(10,i-1))%13][l]+=F[i-1][k][ys][0];
					F[i][j][(ys+j*po(10,i-1))%13][l]+=F[i-1][k][ys][1];
				}else{
					if (j==1&&k==3)continue;
					F[i][j][(ys+j*po(10,i-1))%13][l]+=F[i-1][k][ys][l];
				}
	      }
	while (scanf("%d",&n)!=EOF)printf("%d\n",solve(n));
}
