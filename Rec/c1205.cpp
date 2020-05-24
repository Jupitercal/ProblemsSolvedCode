#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#define N 200
int F[N][N*30],n,m,nod;
bool col[N*30];
char s[N];
int son[N*30][26],fail[N*30];
std::queue<int>q;
struct ac_auto{
	void insert(){
		for (int i=1;i<=n;i++){
			scanf("%s",s);
			int len=strlen(s);
			int p=0;
			for (int ii=0;ii<len;ii++){
				int x=s[ii]-'A';
				if (!son[p][x])son[p][x]=++nod;
				p=son[p][x];
			}
			col[p]=1;
		}
	}
	void build(){
		for (int i=0;i<26;i++)
		   if (son[0][i])q.push(son[0][i]);
		while (!q.empty()){
			int u=q.front();q.pop();
			for (int i=0;i<26;i++)
			  if (!son[u][i])son[u][i]=son[fail[u]][i];
			  else{
					fail[son[u][i]]=son[fail[u]][i];
					if (col[fail[son[u][i]]])col[son[u][i]]=1;
					q.push(son[u][i]);
			  }
		}
	}
}Ac;
void dp(int x){
	for (int i=0;i<=nod;i++){
		if (col[i]||!F[x-1][i])continue;
		for (int ii=0;ii<26;ii++)
		  F[x][son[i][ii]]=(F[x][son[i][ii]]+F[x-1][i])%10007;
	}
}
int main(){
	freopen("c1205.in","r",stdin);
	freopen("c1205.out","w",stdout);
	scanf("%d%d",&n,&m);
	Ac.insert();
	Ac.build();
	F[0][0]=1;
	for (int I=1;I<=m;I++)dp(I);
	int sum=1;
	int ans=0;
	for (int i=1;i<=m;i++)sum=(sum*26)%10007;
	for (int i=0;i<=nod;i++)
	  if (!col[i])ans=(ans+F[m][i])%10007;
	printf("%d",(sum-ans+10007)%10007);
	return 0;
} 
