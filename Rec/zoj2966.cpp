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
#define N 600
struct aa{
	int x,y,len;
}line[N*N];
int T,n,e,tot,ans,fa[N];
bool cmp(aa a,aa b){return a.len<b.len;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&e);
		for (int i=1;i<=n;i++)fa[i]=i;
		for (int i=1;i<=e;i++)scanf("%d%d%d",&line[i].x,&line[i].y,&line[i].len);
		std::sort(line+1,line+1+e,cmp);
		tot=0;ans=0;
		for (int i=1;i<=e;i++){
			int fx=find(line[i].x+1);
			int fy=find(line[i].y+1);
			if (fx!=fy){
				++tot;
				fa[fx]=fy;
				ans+=line[i].len;
				if (tot==n-1)break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

