/*
ID: Rec
PROG: concom
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define N 300
int d[N][N],n,r;
bool v[N][N];
int main(){
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	scanf("%d",&n);
	r=0;
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		scanf("%d",&d[x][y]);
		if (d[x][y]>=50)v[x][y]=1;
		r=std::max(std::max(x,y),r);
	}
	for (int x=1;x<=r;x++)
	  for (int i=1;i<=r;i++){
	  	v[i][i]=1;
	    for (int j=1;j<=r;j++){
	    	int sum=0;
	    	if (!v[i][j]){
	    		for (int k=1;k<=r;k++)
	    		  if (v[i][k])sum+=d[k][j];
	    		if (sum>=50)v[i][j]=1;
	    	}
	    }
      }
    for (int i=1;i<=r;i++)
      for (int j=1;j<=r;j++)
        if (v[i][j]&&i!=j)printf("%d %d\n",i,j);
	return 0;
} 
