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
int n,m,num[3000],a[3000],ans;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("hdu2800.in","r",stdin);
	freopen("hdu2800.out","w",stdout);
	while (scanf("%d%d",&n,&m)!=EOF){
		memset(num,0,sizeof(num));
		ans=0;
		char t;
		scanf("%c",&t);
		for (int i=1;i<=n;i++){
		  char c;
		  for (int j=1;j<=m;j++){
		  	scanf("%c",&c);
		  	if (c=='1')++num[j];
		  	else num[j]=0;
		  	a[j]=num[j];
		  }
		  std::sort(a+1,a+n+1,cmp);
		  for (int j=1;j<=n&&a[j];j++)
		    ans=std::max(ans,a[j]*j);
		  scanf("%c",&c);
	    }
	    printf("%d\n",ans);
	}
	return 0;
}
