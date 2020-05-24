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
#define N 2000
int T,n,m,num[N],lim[N],u[N],w[N][N],edge[N][N];
bool B[N];
int main(){
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		memset(num,sizeof(num),0);
		for (int i=1;i<=(1<<n);i++)B[i]=edge[i][0]=0;
		for (int i=1;i<=(1<<n);i++)scanf("%d",&lim[i]);
		for (int i=1;i<=(1<<n);i++)scanf("%d",&u[i]);
		for (int i=1;i<=(1<<n);i++)
		  for (int j=0;j<(1<<m);j++)
		    scanf("%d",&w[i][j]);
	    for (int i=1;i<=(1<<n);i++)
	      for (int j=1;j<=(1<<n);j++){
	      	int pd=i^j;
			int su=0;
			while (pd){
			    su+=(pd&1);
			    pd/=2;
			}
			if (su==1){
				edge[i][++edge[i][0]]=j;
				edge[j][++edge[j][0]]=i;
			}
	      }
		for (int i=1;i<=(1<<n);i++){
		  int ma=-0x5f5f5f5f;		
		  for (int j=0;j<(1<<m);j++){
		  	int x=w[i][j];
		  	if (j>=lim[i])
		  	for (int ii=1;ii<=edge[i][0];ii++)
			  if (!B[edge[i][ii]]){
		  		x+=u[i]^u[edge[i][ii]];
		  	  }
		    if (ma<x){
		    	ma=x;
		    	num[i]=j;
		    }
		  }
		  if (num[i]>=lim[i])B[i]=1;
	    }
	    for (int i=1;i<=(1<<n);i++)printf("%d ",num[i]);
	    printf("\n");
    }
	return 0;
}
