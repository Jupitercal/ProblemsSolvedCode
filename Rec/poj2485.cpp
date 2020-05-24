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
#define N 510
int T,fa[N],n;
struct aa{
	int x,y,dist;
}line[N*N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
bool cmp(aa a,aa b){return a.dist<b.dist;}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		int tot=0;
		for (int i=1;i<=n;i++)fa[i]=i;
		for (int i=1;i<=n;i++) 
		  for (int j=1;j<=n;j++){
		  	int x;
		  	scanf("%d",&x);
		  	if (i!=j){
		  		++tot;
		  		line[tot].x=i;
		  		line[tot].y=j;
		  		line[tot].dist=x;
		  	}
		  }
		std::sort(line+1,line+tot+1,cmp);
		int cnt=0;int ans=0;
		for (int i=1;i<=tot;i++){
			int fx=find(line[i].x);
			int fy=find(line[i].y);
			if (fx!=fy){
				fa[fx]=fy;
				++cnt;
				if (cnt==n-1){
					ans=line[i].dist;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

