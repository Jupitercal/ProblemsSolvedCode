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
#define N 5000
struct aa{
	int x,y;
}ans[N];
bool vis[27][27],f;
int x[8],y[8],n,p,q;
void dfs(int tot,int xx,int yy){
	if (tot==p*q){
		f=1;
		return;
	}
	for (int i=0;i<=7;i++){
		if (f)return;
		if (xx+x[i]>0&&xx+x[i]<=p&&yy+y[i]>0&&yy+y[i]<=q){
			if (!vis[xx+x[i]][yy+y[i]]){
				vis[xx+x[i]][yy+y[i]]=1;
				ans[tot+1].x=xx+x[i];
				ans[tot+1].y=yy+y[i];
				dfs(tot+1,xx+x[i],yy+y[i]);
				vis[xx+x[i]][yy+y[i]]=0;
			}
		}
	}
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&n);
	int T=0;
	x[0]=-1;x[1]=1;x[2]=-2;x[3]=2;x[4]=-2;x[5]=2;x[6]=-1;x[7]=1;
	y[0]=-2;y[1]=-2;y[2]=-1;y[3]=-1;y[4]=1;y[5]=1;y[6]=2;y[7]=2;
	while (++T<=n){
		scanf("%d%d",&p,&q);
		for (int i=1;i<=p;i++)
		  for (int j=1;j<=q;j++)vis[i][j]=0;
		f=0;
		printf("Scenario #%d:\n",T);
		vis[1][1]=1;
		ans[1].x=1;ans[1].y=1;
		dfs(1,1,1);
		if (!f)printf("impossible\n\n");
		else {
			for (int i=1;i<=p*q;i++){
				char c=ans[i].y-1+'A';
				printf("%c%d",c,ans[i].x);
			}
			printf("\n\n");
		}
	}
	return 0;
}

