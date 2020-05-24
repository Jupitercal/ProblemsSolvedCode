/*
ID: Rec
PROG: sprime
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
int n;
int num[20],ans[30000];
bool cmp(int x,int y){return x<y;}
bool pd(int x){
	int m=(int)sqrt(x);
	if (x==1||x==0)return 0;
	for (int i=2;i<=m;i++)
	  if (x%i==0)return 0;
	return 1;
}
void dfs(int x){
	if (x>n){
		int h=0;
		for (int i=1;i<=x-1;i++)h=h*10+num[i];
		if (pd(h))ans[++ans[0]]=h;
		return ;
	}
	int wz=0;
	if (x==1)wz=1;
	for (int i=wz;i<=9;i++){
		num[x]=i;
		int h=0;
		for (int j=1;j<=x;j++)h=h*10+num[j];
		if (pd(h))dfs(x+1);
		num[x]=0;
	}
}
int main(){
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	scanf("%d",&n);
	dfs(1);
	std::sort(ans+1,ans+ans[0]+1,cmp);
	for (int i=1;i<=ans[0];i++)printf("%d\n",ans[i]);
	return 0;
}
