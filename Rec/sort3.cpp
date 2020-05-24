/*
ID: Rec
PROG: sort3
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define N 2000
int n;
int a[N],d[N],swi[4][4],ans;
bool cmp(int x,int y){return x<y;}
int main(){
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),d[i]=a[i];
	std::sort(d+1,d+1+n,cmp);
	for (int i=1;i<=n;i++)
	  if (d[i]!=a[i])++swi[a[i]][d[i]];
	for (int i=1;i<=3;i++)
	  for (int j=1;j<=3;j++){
	  	int mi=std::min(swi[i][j],swi[j][i]);
	  	swi[i][j]-=mi;
	  	swi[j][i]-=mi;
	  	ans+=mi;
	  }
	ans+=(swi[1][2]+swi[2][1])*2;
	printf("%d\n",ans);
	return 0;
}
