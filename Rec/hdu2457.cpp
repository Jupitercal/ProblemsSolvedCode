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
#define N 1500
#define MAX 0x5f5f5f5f
int fail[N],son[N][5],sz,F[N][N],n,ans,val[N];
char s[N];
std::queue<int>q;
int getnum(char x){
	int m=0;
	switch (x){
		case 'A':m=0;break;
		case 'C':m=1;break;
		case 'G':m=2;break;
		case 'T':m=3;break;
	}
	return m;
}
void build(){
	int len=strlen(s);
	int p=0;
	for (int i=0;i<len;i++){
		int k=getnum(s[i]);
		if (!son[p][k])son[p][k]=++sz;
		p=son[p][k];
	}
	val[p]=1;
}
void build_Ac(){
	for (int i=0;i<4;i++)
	  if (son[0][i])q.push(son[0][i]);
	while (!q.empty()){
		int u=q.front();q.pop();
		for (int i=0;i<4;i++)
			if (!son[u][i])son[u][i]=son[fail[u]][i];
			else {
				fail[son[u][i]]=son[fail[u]][i];
			    val[son[u][i]]|=val[fail[son[u][i]]];
			    q.push(son[u][i]);
			}
	}
}
void solve(){
	ans=MAX;
	int len=strlen(s);
	for (int i=0;i<=len;i++)
	  for (int j=0;j<=sz;j++)F[i][j]=MAX;
	F[0][0]=0;
	for (int i=0;i<len;i++)
	  for (int j=0;j<=sz;j++){
	  	if (val[j]||F[i][j]==MAX)continue;
	  	for (int k=0;k<4;k++){
	  		int v=son[j][k];
	  		if (v){
	  			if (val[v])continue;
	  			if (getnum(s[i])==k)F[i+1][v]=std::min(F[i+1][v],F[i][j]);
	  			else F[i+1][v]=std::min(F[i+1][v],F[i][j]+1);
	  		}else {
	  			int x=j;
	  			while (!son[x][k]&&x)x=fail[x];
	  			v=son[x][k];
	  			if (val[v])continue;
	  			if (getnum(s[i])==k)F[i+1][v]=std::min(F[i+1][v],F[i][j]);
	  			else F[i+1][v]=std::min(F[i+1][v],F[i][j]+1);
	  		}
	  	}
	  }
	for (int i=0;i<=sz;i++)ans=std::min(ans,F[len][i]);
}
int main(){
	freopen("hdu2457.in","r",stdin);
	freopen("hdu2457.out","w",stdout);
	scanf("%d",&n);
	int cases=0;
	while (n){
		memset(fail,0,sizeof(fail));
		sz=0;
		memset(son,0,sizeof(son));
		memset(val,0,sizeof(val));
		for (int i=1;i<=n;i++){
			scanf("%s",s);
			build();
		}
		build_Ac();
		scanf("%s",s);
		solve();
		printf("Case %d: ",++cases);
		if (ans==MAX)printf("-1\n");
		else printf("%d\n",ans);
		scanf("%d",&n);
	}
	return 0;
}
