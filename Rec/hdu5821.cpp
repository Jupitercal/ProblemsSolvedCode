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
#define N 2000
struct aa{
	int v,op;
}A[N];
int T,B[N],n,m;
bool cmp(aa a,aa b){return a.op<b.op;}
int main(){
	freopen("hdu5821.in","r",stdin);
	freopen("hdu5821.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)scanf("%d",&A[i].v),A[i].op=0;
		for (int i=1;i<=n;i++)scanf("%d",&B[i]);
		for (int i=1;i<=n;i++){
		 	 for (int j=1;j<=n;j++)
		      if (A[j].v==B[i]&&A[j].op==0){
		      	A[j].op=i;
		      	break;
		      }
		 }
		for (int i=1;i<=m;i++){
			int l,r;
			scanf("%d%d",&l,&r);
			std::sort(A+l,A+r+1,cmp);
		}
		bool b=1;
		for (int i=1;i<=n;i++)
		  if (A[i].v!=B[i]){
		  	b=0;
		  	break;
		  }
		if (b)printf("Yes\n");else printf("No\n");
	}
	return 0;
}
