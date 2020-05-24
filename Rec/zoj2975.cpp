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
int T,n,m,col[500][500],sum[30],ans;
char s[500];
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		ans=0;
		for (int i=1;i<=n;i++){
			scanf("%s\n",s);
			for (int j=0;j<m;j++){
				switch(s[j]){
					case 'B':col[i][j+1]=1;break;
					case 'J':col[i][j+1]=2;break;
					case 'H':col[i][j+1]=3;break;
					case 'Y':col[i][j+1]=4;break;
					case 'N':col[i][j+1]=5;break;
				}
			}
		}
		for (int i=1;i<n;i++)
		  for (int j=i+1;j<=n;j++){
		  	memset(sum,0,sizeof(sum));
		  	for (int k=1;k<=m;k++)
		  	  if (col[i][k]==col[j][k])++sum[col[i][k]];
		  	for (int k=1;k<=5;k++)ans+=(sum[k]*(sum[k]-1)/2);
		  }
		printf("%d\n",ans);
	}
	return 0;
}

