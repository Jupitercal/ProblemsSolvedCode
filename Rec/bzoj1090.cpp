#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 105
char s[N];
int n;
int F[N][N];
int get(int x){
	int t=0;
	while (x)++t,x/=10;
	return t;
}
bool judge(int l,int r,int len){
	int rr=l+len;
	for (int i=rr;i<=r;i++)
		if (s[i]!=s[(i-rr)%len+l])return 0;
	return 1;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%s",s+1);
	memset(F,0x3f3f3f3f,sizeof(F));
	n=strlen(s+1);
	for (int len=1;len<=n;len++)
		for (int l=1;l<=n;l++){
			if (len==1){
				F[l][l]=1;
				continue;
			}
			if (l+len-1>n)continue;
			int r=l+len-1;
			for (int j=l;j<r;j++)F[l][r]=std::min(F[l][r],F[l][j]+F[j+1][r]);
			for (int j=1;j<=len;j++)
				if (len%j==0&&judge(l,r,j))F[l][r]=std::min(F[l][r],F[l][l+j-1]+2+get((len-j)/j+1));
		}
	printf("%d",F[1][n]);
	return 0;
}