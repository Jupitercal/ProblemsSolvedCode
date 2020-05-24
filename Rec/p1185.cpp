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
#define N 200
int sta[N],F[N][N][N];
int stas,n,m,za[N],c[N];
char s[N];
void dfs(int x,int stu){
	if (x==m){
		sta[++stas]=stu;
		for (int i=1;i<=m;i++)
		  if (1<<(i-1)&stu)++c[stas];
		return ;
	}else{
		dfs(x+1,stu*2);
		if ((x>=2&&stu/2%2==0&&stu%2==0)||(x==0)||(x==1&&stu%2==0))dfs(x+1,stu*2+1);
	}
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		for (int j=1;j<=m;j++)
			if (s[j-1]=='P')za[i]=za[i]*2;
			else za[i]=za[i]*2+1;
	}
	dfs(0,0);
	for (int i=1;i<=stas;i++)
		if ((za[1]&sta[i])==0)F[1][1][i]=c[i];
	for (int i=2;i<=n;i++)
		for (int j=1;j<=stas;j++){
			for (int k=1;k<=stas;k++)
			   if ((sta[j]&sta[k])==0)
			  	for (int l=1;l<=stas;l++)
			  		if ((sta[k]&sta[l])==0&&(za[i]&sta[l])==0&&(sta[l]&sta[j])==0)
			  			F[i][k][l]=std::max(F[i][k][l],F[i-1][j][k]+c[l]);
		}
	int ans=0;
	for (int i=1;i<=stas;i++)
		for (int j=1;j<=stas;j++)
		  ans=std::max(ans,F[n][i][j]);
	printf("%d",ans);
	return 0;
}

