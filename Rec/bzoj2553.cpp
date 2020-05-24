#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define N 30000
typedef long long LL;
int son[N][26],fail[N],wq[N],n,len,ai,nod;
int dd;
long double B[100][100],C[100][100],A[100][100];
bool col[N];
struct Ac_auto{
	int q[N];
	char s[100];
	void insert(){
		for (int i=1;i<=n;i++){
			scanf("%s",s);
			int len=strlen(s);
			int p=0;
			for (int j=0;j<len;j++){
				int x=s[j]-'a';
				if (!son[p][x]) son[p][x]=++nod;
				p=son[p][x];
			}
			col[p]=1;
		}
	}
	void build(){
		int head=0;int tail=0;
		for (int i=0;i<ai;i++){
			if (son[0][i])q[++tail]=son[0][i];
			B[0][son[0][i]]+=1/ai;
			if (!col[son[0][i]])B[0][son[0][i]]+=(double)1.0/ai;
					else B[0][nod+1]+=(double)1.0/ai,B[0][0]+=(double)1.0/ai;
		}
		while (head<tail){
			int u=q[++head];
			for (int i=0;i<ai;i++){
				if (!son[u][i])son[u][i]=son[fail[u]][i];
				else{
					fail[son[u][i]]=son[fail[u]][i];
					col[son[u][i]]|=col[fail[son[u][i]]];
					q[++tail]=son[u][i];
				}
				if (!col[son[u][i]])B[u][son[u][i]]+=(double)1.0/ai;
					else {
						B[u][nod+1]+=(double)1.0/ai;B[u][0]+=(double)1.0/ai;
					}
			}
		}
	}
}AC;
void mul(LL x){
	for (int i=0;i<=nod;i++){
		for (int j=0;j<=nod;j++)A[i][j]=B[i][j];
	}
	x--;
	while (x){
		if (x&1){
			for (int i=0;i<=nod;i++)
				for (int j=0;j<=nod;j++)C[i][j]=0;
			for (int i=0;i<=nod;i++)
				for (int j=0;j<=nod;j++)
					 for (int k=0;k<=nod;k++)
						 C[i][j]=C[i][j]+(A[i][k]*B[k][j]);
			for (int i=0;i<=nod;i++)
				for (int j=0;j<=nod;j++)A[i][j]=C[i][j];
		}
		for (int i=0;i<=nod;i++)
				for (int j=0;j<=nod;j++)C[i][j]=0;
			for (int i=0;i<=nod;i++)
				for (int j=0;j<=nod;j++)
					 for (int k=0;k<=nod;k++)
						 C[i][j]=(C[i][j]+(B[i][k]*B[k][j]));
			for (int i=0;i<=nod;i++)
				for (int j=0;j<=nod;j++)B[i][j]=C[i][j];
		x/=2;
	}
}
int main(){
	freopen("bzoj2553.in","r",stdin);
	freopen("bzoj2553.out","w",stdout);
	scanf("%d%d%d",&n,&len,&ai);
	AC.insert();
	AC.build();
	++nod;
	B[nod][nod]=1.0;
	mul(len);
	double ans=A[0][nod];
	printf("%.6lf",ans);
	return 0;
}