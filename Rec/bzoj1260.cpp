#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 55
char s[N];
int F[N][N];
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	memset(F,0x3f3f3f3f,sizeof(F));
	for (int i=1;i<=n;i++)F[i][i]=1;
	for (int l=1;l<n;l++)
		for (int i=1;i<=n;i++){
			int j=i+l;
			if (j>n)continue;
			F[i][j]=l+1;
			if (s[i]==s[j])F[i][j]=std::min(F[i][j],std::min(F[i+1][j],F[i][j-1]));
			if (s[j]==s[j-1])F[i][j]=std::min(F[i][j],F[i][j-1]);
			if (s[i]==s[i+1])F[i][j]=std::min(F[i][j],F[i+1][j]);
			for (int k=i;k<j;k++)F[i][j]=std::min(F[i][j],F[i][k]+F[k+1][j]);
		}
	printf("%d",F[1][n]);
	return 0;
}