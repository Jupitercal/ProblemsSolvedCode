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
#define N 100
struct aa{
	int cu;
	int a[N],b[N];
}poi[N];
int sum,T,n,t,tot,k,num[N];
int spe[N][N],dow[N],m,su[N],sp[N];
bool B[N];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("hdu3269.in","r",stdin);
	freopen("hdu3269.out","w",stdout);
	#endif
	scanf("%d",&T);
	while (T--){
		memset(B,0,sizeof(B));
		memset(su,0,sizeof(su));
		memset(dow,0,sizeof(dow));
		memset(poi,0,sizeof(poi));
		memset(sp,0,sizeof(sp));
		scanf("%d%d",&n,&t);
		scanf("%d%d",&k,&tot);
		sum=0;
		for (int i=1;i<=k;i++){
			int x;
			scanf("%d",&x);
			num[++sum]=x;
			B[x]=1;
		}
		for (int i=1;i<=n;i++)
		  for (int j=1;j<=n;j++) scanf("%d",&spe[i][j]);
		for (int i=1;i<=n;i++){
			scanf("%d",&poi[i].cu);
			for (int j=1;j<=poi[i].cu;j++)
			   scanf("%d%d",&poi[i].a[j],&poi[i].b[j]);
		}
		scanf("%d",&m);
		for (int i=1;i<=m;i++){
			int t1,id;
			scanf("%d%d",&t1,&id);
			dow[id]=t1;
		}
		for (int i=1;i<=t;i++){
			if (i==400){
				int m=123;
			}
			for (int j=1;j<=sum;j++)
			  if (sp[num[j]]<i)
			  for (int k=1;k<=poi[num[j]].cu;k++)
			    if (poi[num[j]].a[k]<i&&poi[num[j]].b[k]>=i){
				for (int kk=1;kk<=n;kk++)
				  if (!B[kk]){
				  for (int jj=1;jj<=poi[kk].cu;jj++)
				  if (poi[kk].a[jj]<i&&poi[kk].b[jj]>=i&&dow[kk]<i){
				  	 su[kk]+=spe[num[j]][kk];
				  	 if (su[kk]>=tot){
				  	 	num[++sum]=kk;
				  	 	B[kk]=1;
				  	 	sp[kk]=i;
				  	 	break;
				  	 }
				  }
			    }
			  }
		}
		for (int i=1;i<=n;i++)
		  if (B[i])printf("100%%\n");
		  else {
		  	double m=su[i]*100*1.0/tot;
		  	printf("%d%%\n",(int)m);
		  }
	}
	return 0;
}
