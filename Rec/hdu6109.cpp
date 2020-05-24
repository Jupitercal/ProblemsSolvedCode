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
#include<set>
#define N 100005
using namespace std;
set <int>q[N];
int L,ans[N],fa[N],tot;
void init(){for (int i=1;i<=L;i++)q[i].clear(),fa[i]=i;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	freopen("hdu6109.in","r",stdin);
	freopen("hdu6109.out","w",stdout);
	scanf("%d",&L);
	set<int>::iterator x;
	tot=0;
	init();
	for (int i=1;i<=L;i++){
		int I,J,E;
		scanf("%d%d%d",&I,&J,&E);
		int fx=find(I);
		int fy=find(J);
		if (E){
			if (fx==fy)continue;
			else if (q[fx].find(fy)!=q[fx].end()){
				ans[++tot]=i;
				init();
			}else{
				for (x=q[fy].begin();x!=q[fy].end();x++){
					q[fx].insert(*x);
					q[*x].erase(fy);
					q[*x].insert(fx);
				}
				q[fy].clear();
				fa[fy]=fx;
			}
		}else{
			if (fx!=fy){
				q[fx].insert(fy);
				q[fy].insert(fx);
			}else{
				ans[++tot]=i;
				init();
			}
		}
	}
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++)printf("%d\n",ans[i]-ans[i-1]);
	return 0;
}
