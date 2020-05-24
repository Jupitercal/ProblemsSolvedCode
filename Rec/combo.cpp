/*
ID: Rec
PROG: combo
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
int ans[10000][4],sum,a[4],b[4],n,cl[5];
void dfs(int x){
	if (x>3){
		bool b=1;
		for (int i=1;i<=sum;i++){
		  bool bb=0;
		  for (int j=1;j<=3;j++)
		    if (cl[j]!=ans[i][j])bb=1;
		  b&=bb;
 	    }
 	    if (b){
 	    	 sum++;
 	    	 for (int i=1;i<=3;i++)
 	    	   ans[sum][i]=cl[i];
 	    }
 	    return;
	}
	for (int i=-2;i<=2;i++){
		int xx=(a[x]+i+n)%n;
		if (!xx)xx+=n;
		cl[x]=xx;
		dfs(x+1);
		cl[x]=0;
	}
}
void dfs1(int x){
	if (x>3){
		bool b=1;
		for (int i=1;i<=sum;i++){
		  bool bb=0;
		  for (int j=1;j<=3;j++)
		    if (cl[j]!=ans[i][j])bb=1;
		  b&=bb;
 	    }
 	    if (b){
 	    	 sum++;
 	    	 for (int i=1;i<=3;i++)
 	    	   ans[sum][i]=cl[i];
 	    }
 	    return;
	}
	for (int i=-2;i<=2;i++){
		int xx=(b[x]+i+n)%n;
		if (!xx)xx+=n;
		cl[x]=xx;
		dfs1(x+1);
		cl[x]=0;
	}
}
int main(){
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=3;i++)scanf("%d",&a[i]);
	for (int i=1;i<=3;i++)scanf("%d",&b[i]);
	dfs(1);
	dfs1(1);
	printf("%d\n",sum);
	return 0;
}
