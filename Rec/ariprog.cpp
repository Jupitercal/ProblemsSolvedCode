/*
ID: Rec
PROG: ariprog
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define N 200000
int n,m,num,a[N],cl[N],ans[20000][3],an;
bool cmp(int x,int y){return x<y;}
bool B[N];
int main(){
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=0;i<=m;i++)
	  for (int j=i;j<=m;j++){
  	    a[++num]=i*i+j*j;
  	    B[a[num]]=1;
      }
  	std::sort(a+1,a+1+num,cmp);
  	int lr=a[num]-a[num-24];
	for (int i=1;i<=lr;i++){
		for (int j=1;j<=num;j++)
		  if(a[j]+(n-1)*i<=a[num]){
			bool b=0;
			for (int k=1;k<=n-1;k++)
			  if (!B[a[j]+k*i]){
			  	b=1;
			  	break;
			  }
			if (!b){
				if (ans[an][1]==a[j]&&ans[an][2]==i)continue;
				++an;
				ans[an][1]=a[j];
				ans[an][2]=i;
			}
		}else break;
	}
	if (an)for (int i=1;i<=an;i++)printf("%d %d\n",ans[i][1],ans[i][2]);
	else printf("NONE\n");
	return 0;
} 
