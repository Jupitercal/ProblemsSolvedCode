#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define N 3000
#define bit 100000000
typedef long long LL;
int n,tou[N],dd,size[N];
struct aa{
	int p,next;
}da[N];
struct cc{
	LL w[40];
	int len;
}F[705][705];
void add(int x,int y){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;
}
cc make(int x){
	cc a;
	memset(a.w,0,sizeof(a.w));
	a.w[1]=x;
	a.len=1;
	return a;
}
bool operator <(cc a,cc b){
	if (a.len!=b.len)return a.len<b.len;
	for (int i=a.len;i;i--)
	  if (a.w[i]>b.w[i])return 0;
	  else if (a.w[i]<b.w[i])return 1;
	return 0;
}
cc operator *(cc a,cc b){
	cc x;
	memset(x.w,0,sizeof(x.w));
	x.len=1;
	for (int i=1;i<=a.len;i++)
	  for (int j=1;j<=b.len;j++)
	    x.w[i+j-1]+=a.w[i]*b.w[j];
	x.len=a.len+b.len+1;
	for (int i=1;i<=x.len;i++){
		x.w[i+1]+=x.w[i]/bit;
		x.w[i]%=bit;
	}
	while (!x.w[x.len]&&x.len>1)--x.len;
	return x;
}
void dfs(int x,int fa){
	F[x][1]=make(1);
	size[x]=1;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (fa==v)continue;
		dfs(v,x);
		for (int j=size[x];j;j--)
		  for (int k=size[v]+1;k>=0;k--)
		    if (F[x][j+k]<F[x][j]*F[v][k])F[x][j+k]=F[x][j]*F[v][k];
		size[x]+=size[v];
	}
	F[x][0]=make(size[x]);
	for (int i=1;i<=size[x];i++)
	  if (F[x][0]<F[x][i]*make(i))F[x][0]=F[x][i]*make(i);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); 
	}
	dfs(1,0);
	printf("%I64d",F[1][0].w[F[1][0].len]);
	for (int i=F[1][0].len-1;i;i--)printf("%.8I64d",F[1][0].w[i]);
	return 0;
}
