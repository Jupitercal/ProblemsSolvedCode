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
#define N 2100
struct aa{
	int x,y,dist;
}line[N*N];
int fa[N],n;
bool cmp(aa a,aa b){return a.dist<b.dist;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
char s[N][10];
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d",&n)&&n){
		for (int i=1;i<=n;i++)scanf("%s",s[i]);
		for (int i=1;i<=n;i++)fa[i]=i;
		int tot=0;int cnt=0;
		for (int i=1;i<n;i++)
		  for (int j=i+1;j<=n;j++){
		  	int len=strlen(s[i]);
		  	int m=0;
		  	for (int k=0;k<len;k++)
		  	  if (s[i][k]!=s[j][k])++m;
		  	++tot;
		  	line[tot].dist=m;
		  	line[tot].x=i;
		  	line[tot].y=j;
		  }
		std::sort(line+1,line+tot+1,cmp);
		int ans=0;
		for (int i=1;i<=tot;i++){
			int x=line[i].x;int y=line[i].y;
			int fx=find(fa[x]);
			int fy=find(fa[y]);
			if (fx!=fy){
				fa[fx]=fy;
				ans+=line[i].dist;
				++cnt;
			}
			if (cnt==n-1)break;
		}
		printf("The highest possible quality is 1/%d.\n",ans);
	}
	return 0;
}

