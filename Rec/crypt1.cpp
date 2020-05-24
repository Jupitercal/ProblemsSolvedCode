/*
ID: Rec
PROG: crypt1
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
int n,num[30],a[10],b[10],c[10],d[10],m[10];
bool mun[30];
bool pd(){
	bool bb=1;
	int len1=3;
	int len2=4;
	for (int i=1;i<=3;i++)
	  c[i]=a[i]*b[1];
	for (int i=1;i<=3;i++){
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	if (c[len1+1])bb=0;
	for (int i=1;i<=3;i++)
	  d[i+1]=a[i]*b[2];
	for (int i=2;i<=4;i++){
		d[i+1]+=d[i]/10;
		d[i]%=10;
	}
	if (d[len2+1])bb=0;
	for (int i=1;i<=len1;i++) bb=bb&mun[c[i]];
	for (int i=2;i<=len2;i++) bb=bb&mun[d[i]];
	for (int i=1;i<=len2+1;i++)m[i]=c[i]+d[i];
	for (int i=1;i<=len2;i++){
		m[i+1]+=m[i]/10;
		m[i]%=10;
	}
	if (m[len2+1])bb=0;
	for (int i=1;i<=len2;i++)bb=bb&mun[m[i]];
	for (int i=1;i<=5;i++)c[i]=d[i]=m[i]=0;
	return bb;
}
int  dfs(int x){
	int sum=0;
	if (x>5)return pd();
	if (x<4){
	  for (int i=1;i<=n;i++){
	  	 a[x]=num[i];
	  	 sum+=dfs(x+1);
	  	 a[x]=0;
	  }
    }else{
      for (int i=1;i<=n;i++){
      	b[x-3]=num[i];
      	sum+=dfs(x+1);
      	b[x-3]=0;
      } 
    }
    return sum;
}
int main(){
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&num[i]),mun[num[i]]=1;;
	printf("%d\n",dfs(1));
	return 0;
}
