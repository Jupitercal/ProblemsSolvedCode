#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define N 200000
struct aa{
	int p,ne;
}da[N];
int tr[N][2],fa[N],tou[N],dd,q;
int n,next[N],tmp,size;
char s[20];
void add(int x,int y){da[++dd].p=y;da[dd].ne=tou[x];tou[x]=dd;}
void build(int x){
	fa[x]=size;
	tr[size][1]=x;
	size=x;
	for (int i=tou[x];i;i=da[i].ne)build(da[i].p);
	fa[x+n]=size;
	tr[size][1]=x+n;
	size=x+n;
}
inline void rotate(int x,bool f){
	int y=fa[x];
	int z=fa[y];
	tr[y][!f]=tr[x][f];
	fa[tr[x][f]]=y;
	fa[x]=z;
	if (z)tr[z][tr[z][1]==y]=x;
	tr[x][f]=y;
	fa[y]=x;
}
void splay(int x,int k){
	int y=fa[x];
	while (y!=k){
		int z=fa[y];
		bool f=(tr[y][0]==x);
		if (z!=k&& f==(tr[z][0]==y))rotate(y,f);
		rotate(x,f);
		y=fa[x];
	}
}
void move(int x,int y){
	if (x==y)return;
	splay(x,0);splay(x+n,x);
	for (int i=y;i;i=fa[i])if (tr[x+n][0]==i)return;
	int a=tr[x][0];
	int b=tr[x+n][1];
	tr[x][0]=tr[x+n][1]=fa[a]=fa[b]=0;
	if (a&&b){
		while (tr[b][0])b=tr[b][0];
		tr[b][0]=a;
		fa[a]=b;
	}
	if (y==0)return;
	splay(y,0);
	int i;
	for (i=tr[y][1];tr[i][0];i=tr[i][0]);
	splay(i,y);
	tr[i][0]=x;
	fa[x]=i;
}
int query(int x){
	splay(x,0);
	for (;tr[x][0];x=tr[x][0]);
	return x;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("hdu2475.in","r",stdin);
	freopen("hdu2475.out","w",stdout);
	#endif
	bool xi=0;
	while (scanf("%d",&n)!=EOF){
		memset(tou,0,sizeof(tou));
		memset(next,0,sizeof(next));
		memset(da,0,sizeof(da));
		tmp=0;dd=0;
		if (!xi)xi=1;
		else printf("\n");
		for (int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if (x)add(x,i);
			else {
				next[tmp]=i;
				tmp=i;
			}
		}
		for (int i=next[0];i;i=next[i])size=0,build(i);
		scanf("%d",&q);
		for (int i=1;i<=q;i++){
			scanf("%s",s);
			if (s[0]=='Q'){
				int x;
				scanf("%d",&x);
				printf("%d\n",query(x));
			}else{
				int x,y;
				scanf("%d%d",&x,&y);
				move(x,y);
			}
		}
		for (int i=1;i<=2*n;i++)tr[i][1]=tr[i][0]=fa[i]=0;
		//printf("\n");
	}
	return 0;
}
