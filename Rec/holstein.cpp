/*
ID: Rec
PROG: holstein
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define N 100
int ans,num[N],ans1[N],fed[N][N],po[N];
int V,G,need[N];
bool B[N];
bool pd(int p){
	for (int i=1;i<=V;i++)num[i]=0;
	for (int i=1;i<=p-1;i++)
	  for (int j=1;j<=V;j++)
	    num[j]+=fed[po[i]][j];
	for (int i=1;i<=V;i++)
	  if (num[i]<need[i])return 0;
	return 1; 
}
void dfs(int x,int p){
	if (pd(x)){
		if (x-1<ans){
			ans=x-1;
			for (int i=1;i<=x;i++)ans1[i]=po[i];
			return ;
		}
	}
	for (int i=p;i<=G;i++)
	  if (!B[i]){
	    B[i]=1;
	    po[x]=i;
		dfs(x+1,i);	
		po[x]=0;
		B[i]=0;
	  }
}
int main(){
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	scanf("%d",&V);
	for (int i=1;i<=V;i++)scanf("%d",&need[i]);
	scanf("%d",&G);
	for (int i=1;i<=G;i++)
	  for (int j=1;j<=V;j++)scanf("%d",&fed[i][j]);
	ans=0x5f5f5f5f;
	dfs(1,1);
	printf("%d ",ans);
	for (int i=1;i<ans;i++)printf("%d ",ans1[i]);
	printf("%d\n",ans1[ans]);
	return 0;
}
