#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 205
int F[N][N][6],w,i,n,g;
int q[N*2],len,t[N];
char p[N*2],s[N],c[5][20][N];
int dfs(int l,int r,int x){
	if (F[l][r][x]!=-1)return F[l][r][x];
	if (l==r)return (F[l][r][x]=(s[l]==p[x]));
	bool res=0;
	for (int i=1;i<=t[x];i++)
		for (int j=l;j<=r-1;j++)
		if (dfs(l,j,q[c[x][i][1]-0])==1&&dfs(j+1,r,q[c[x][i][2]-0])==1){
			res=1;
			break;
		}
	return (F[l][r][x]=res);
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	for (int i=0;i<4;i++)scanf("%d",&t[i]);
	q['W']=0;q['I']=1;q['N']=2;q['G']=3;
	p[0]='W';p[1]='I';p[2]='N';p[3]='G';
	for (int i=0;i<=200;i++)
		for (int j=0;j<=200;j++)
			for (int k=0;k<=5;k++)F[i][j][k]=-1;
	for (int i=0;i<4;i++)
		for (int j=1;j<=t[i];j++)
			scanf("%s",c[i][j]+1);
	scanf("%s",s+1);
	//printf("%s\n",s+1);
	len=strlen(s+1);
	bool f=0;
	for (int i=0;i<4;i++)
		if (dfs(1,len,i)==1)f=1,printf("%c",p[i]);
	if (!f)printf("The name is wrong!");
	return 0;
}