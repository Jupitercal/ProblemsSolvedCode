#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#define N 300
#define eps 1e-8
int n,l,m;
int son[N][26],nod,di[N],fail[N];
double F[N][N],c[N],ans[N];
bool col[N];
void insert(){
	char s[N];
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		int p=0;
		for (int j=0;j<l;j++){
			int x=s[j]-'A';
			if (!son[p][x])son[p][x]=++nod;
			p=son[p][x];
		}
		col[p]=1;
		di[i]=p;
	}
	std::queue<int>q;
	for (int i=0;i<26;i++)if (son[0][i])q.push(son[0][i]);
	while (!q.empty()){
		int u=q.front();q.pop();
		for (int i=0;i<m;i++){
			if (!son[u][i])son[u][i]=son[fail[u]][i];
			else{
				fail[son[u][i]]=son[fail[u]][i];
				q.push(son[u][i]);
			}
		} 
	}
}
void gauss(){
	for (int i=1;i<nod+1;i++){
		int mi=i;
		for (int j=i+1;j<=nod+1;j++)
		  if (fabs(F[j][i])>fabs(F[mi][i]))mi=j;
		for (int j=1;j<=nod+2;j++)std::swap(F[i][j],F[mi][j]);
		for (int j=i+1;j<=nod+1;j++){
			double x=F[j][i]/F[i][i];
			for (int k=i;k<=nod+2;k++)F[j][k]-=x*F[i][k];
		}
	}
	for (int i=nod+1;i>=1;i--){
		double x=F[i][nod+2];
		for (int j=nod+1;j>=i+1;j--)x-=ans[j]*F[i][j];
		ans[i]=x/F[i][i];
	}
} 
int main(){
	freopen("vijos1569.in","r",stdin);
	freopen("vijos1569.out","w",stdout);
	scanf("%d%d%d",&n,&l,&m);
	for (int i=1;i<=m;i++){
		int p,q;
		scanf("%d%d",&p,&q);
		c[i]=1.0*p/q;
	}
	insert();
	F[1][nod+2]=-1;
	for (int i=0;i<=nod;i++){
		int x=fail[i];
		while (x&&!col[i]){
			F[x+1][i+1]=1;
			x=fail[x];
		}
		F[i+1][i+1]=-1;
		for (int j=0;j<m;j++)
		  if (son[i][j]&&!col[j])F[son[i][j]+1][i+1]=c[j+1]; 
	}
	gauss();
	for (int i=1;i<=n;i++)
	  printf("%.2f\n",fabs(ans[di[i]]));
	return 0;
} 
