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
#define N 1060
int cases,num[N][N];
int n,m;
int sum(int x,int y){
	int s=0;
	while (x>0){
		int yy=y;
		while (yy>0)s+=num[x][yy],yy-=yy&(-yy);
		x-=x&(-x);
	}
	return s;
}
void plus(int x,int y,int v){
	while (x<=n){
		int yy=y;
		while (yy<=n)num[x][yy]+=v,yy+=yy&(-yy);
		x+=x&(-x);
	}
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&cases);
	while (cases--){
		scanf("%d%d\n",&n,&m);
		for (int i=1;i<=n;i++)
		  for (int j=1;j<=n;j++)num[i][j]=0;
		for (int i=1;i<=m;i++){
			char c;
			scanf("%c",&c);
			if (c=='C'){
				int x,y,x1,y1;
				scanf("%d%d%d%d\n",&x,&y,&x1,&y1);
				plus(x,y,1);
				plus(x1+1,y1+1,1);
				plus(x,y1+1,-1);
				plus(x1+1,y,-1);
			}else{
				int x,y;
				scanf("%d%d\n",&x,&y);
				printf("%d\n",sum(x,y)%2);
			}
		}
		if (cases)printf("\n");
	}
	return 0;
}

