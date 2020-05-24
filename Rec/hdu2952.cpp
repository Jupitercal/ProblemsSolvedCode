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
int T,n,m,fa[20000];
int x[3],y[3],tot;
char s[300][300];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	freopen("hdu2952.in","r",stdin);
	freopen("hdu2952.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		tot=0;
		for (int i=1;i<=n;i++)
		  for (int j=1;j<=m;j++)fa[(i-1)*m+j]=(i-1)*m+j;
		for (int i=1;i<=n;i++)scanf("%s",s[i]);
		x[0]=0;y[0]=-1;x[1]=-1;y[1]=0;
		for (int i=1;i<=n;i++)
		  for (int j=1;j<=m;j++)
		   if (s[i][j-1]=='#')++tot;
		for (int i=1;i<=n;i++)
		  for (int j=1;j<=m;j++)
		   if (s[i][j-1]=='#'){
		   		for (int k=0;k<=1;k++){
		    		int X=x[k]+i;int Y=y[k]+j;
		    		if (X<=0||Y<=0)continue;
		    		int u=(i-1)*m+j;int v=(X-1)*m+Y;
		    		if (s[X][Y-1]=='#'){
		    			int fx=find(fa[u]);
		    			int fy=find(fa[v]);
		    			if (fx!=fy){
		    				fa[fx]=fy;
		    				--tot;
		    			}
		    		}
		   	 }	
		   }
		   printf("%d\n",tot);
	}
	return 0;
}
