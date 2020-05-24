#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
#define N 60000
#define MOD 100000
typedef long long LL;
int n,m,son[N][26],nod,fail[N],tou[N],dd;
LL A[200][200],B[200][200],C[200][200];
bool col[N];
char goa[5];
struct AC_auto{
	char s[60];
	int q[N*2];
	void insert(){
		for (int i=1;i<=m;i++){
			scanf("%s",s);
			int len=strlen(s);
			int p=0;
			for (int j=0;j<len;j++){
				int x=s[j]-'A';
				if (!son[p][x])son[p][x]=++nod;
				p=son[p][x];
			}
			col[p]=1;
		}
	}
	void build(){
		int head=0;int tail=0;
		for (int l=1;l<=4;l++){
			int i=goa[l]-'A';
			if (son[0][i])q[++tail]=son[0][i];
			if (!col[0]&&!col[son[0][i]])B[0][son[0][i]]++;
		}
		while (head<tail){
			int u=q[++head];
			for (int l=1;l<=4;l++){
				int i=goa[l]-'A';
				if (!son[u][i])son[u][i]=son[fail[u]][i];
				else{
					fail[son[u][i]]=son[fail[u]][i];
					col[son[u][i]]|=col[fail[son[u][i]]];
					q[++tail]=son[u][i];
				}
				if (!col[u]&&!col[son[u][i]])B[u][son[u][i]]++;
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
						 C[i][j]=(C[i][j]+(A[i][k]*B[k][j])%MOD)%MOD;
			for (int i=0;i<=nod;i++)
				for (int j=0;j<=nod;j++)A[i][j]=C[i][j];
		}
		for (int i=0;i<=nod;i++)
				for (int j=0;j<=nod;j++)C[i][j]=0;
			for (int i=0;i<=nod;i++)
				for (int j=0;j<=nod;j++)
					 for (int k=0;k<=nod;k++)
						 C[i][j]=(C[i][j]+(B[i][k]*B[k][j])%MOD)%MOD;
			for (int i=0;i<=nod;i++)
				for (int j=0;j<=nod;j++)B[i][j]=C[i][j];
		x/=2;
	}
}
int main(){
	freopen("poj2778.in","r",stdin);
	freopen("poj2778.out","w",stdout);
	scanf("%d%d",&m,&n);
	goa[1]='A';goa[2]='T';
	goa[3]='C';goa[4]='G';
	AC.insert();
	AC.build();
	mul(n);
	LL ans=0;
	for (int i=0;i<=nod;i++)ans=(ans+A[0][i])%MOD;
	printf("%lld",ans);
	return 0;
}