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
#define INF 0x3f3f3f3f
std::queue<int>q;
int n,d;
double dist[N][N];
int it[N];
char s[N][N],a[N],b[N];
bool in[N];
void Floyd(){
	for (int k=1;k<=n;k++)
	  for (int i=1;i<=n;i++)
	    for (int j=1;j<=n;j++)
	      dist[i][j]=std::max(dist[i][j],dist[i][k]*dist[k][j]);
}
int find(char* q){
	int len1=strlen(q);
	for (int i=1;i<=n;i++){
		bool b=1;int len=strlen(s[i]);
		if (len1!=len)continue;
		for (int j=0;j<len;j++)
		  if (q[j]!=s[i][j]){
		  	b=0;break;
		  }
		if (b)return i;
	}
	return 0;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	int cases;cases=0;
	while (scanf("%d",&n)&&n){
		memset(dist,0,sizeof(dist));
		++cases;
		for (int i=1;i<=n;i++)scanf("%s",s[i]);
		for (int i=1;i<=n;i++)dist[i][i]=1;
		scanf("%d",&d);
		for (int i=1;i<=d;i++){
			double x;
			scanf("%s%lf%s",a,&x,b);
 			int a1=find(a);int b1=find(b);
			dist[a1][b1]=x;
		}
		printf("Case %d: ",cases);
		bool b=0;
		Floyd();
		for (int i=1;i<=n;i++)
			if (dist[i][i]>1){
				b=1;
				break;
			}
		if (b)printf("Yes\n");
		else printf("No\n");
	} 
	return 0;
}

