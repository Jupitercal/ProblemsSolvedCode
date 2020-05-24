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
int n,a[20][20],ans;
bool B[20];
void dfs(int x,int p,int t){
	if (ans<t)ans=t;
	for (int i=0;i<n;i++)
	  if (!B[i]&&a[x][i]>=p){
	  	B[i]=1;
	  	dfs(i,a[x][i],t+1);
	  	B[i]=0;
	  }
}
int main(){
	freopen("hdu2614.in","r",stdin);
	freopen("hdu2614.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		memset(B,0,sizeof(B));
		for (int i=0;i<n;i++)
		  for (int j=0;j<n;j++)
		   scanf("%d",&a[i][j]);
		B[0]=1;ans=1;
		dfs(0,0,1); 
		printf("%d\n",ans);
	}
	return 0;
}
