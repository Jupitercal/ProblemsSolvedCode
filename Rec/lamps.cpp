/*
ID: Rec
PROG: lamps
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define N 101
int n,c,off[N],on[N],r;
int col,num[N];
struct aa{
	int a[N]; 
}ans[N];
bool B[5];
bool cmp(aa a,aa b){
	for (int i=1;i<=n;i++)
	  if (a.a[i]<=b.a[i]){
	  	if (a.a[i]<b.a[i])return 1;
	  }
	  else return 0;
	return 0;
}
bool equal(aa a,aa b){
	for (int i=1;i<=n;i++)
	  if (a.a[i]!=b.a[i])return 0;
	return 1;
}
void operate(int x){
	if (x==0)for (int i=1;i<=n;i++)num[i]^=1;
	if (x==1)for (int i=2;i<=n;i+=2)num[i]^=1;
	if (x==2)for (int i=1;i<=n;i+=2)num[i]^=1;
	if (x==3)for (int i=0;3*i+1<=n;i++)num[3*i+1]^=1;
}
void dfs(int x){
	if (x==0){
		bool b=1;
		for (int i=1;i<=off[0];i++) if (num[off[i]])b=0;
		for (int i=1;i<=on[0];i++)if (!num[on[i]])b=0;
		if (b){
			col++;
			for (int i=1;i<=n;i++)ans[col].a[i]=num[i];
		}
		return;
	}
	for (int i=0;i<=3;i++)
	if (!B[i]){
		operate(i);
		B[i]=1;
		dfs(x-1);
		B[i]=0;
		operate(i);
	}
}
int main(){
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&c);
	for (int i=1;i<=n;i++)num[i]=1;
	int x;
	scanf("%d",&x);
	while (x!=-1)on[++on[0]]=x,scanf("%d",&x);
	scanf("%d",&x);
	while (x!=-1)off[++off[0]]=x,scanf("%d",&x);
	r=c;
	if (r>4){
		if (r%2==0)r=4;
		else r=3;
	}
	dfs(r);
	while (r>=2)dfs(r-=2);
	std::sort(ans+1,ans+col+1,cmp);
	if (col)
	for (int i=1;i<=col;i++){
		if (i!=1&&equal(ans[i-1],ans[i]))continue;
		for (int j=1;j<=n;j++)printf("%d",ans[i].a[j]);
		printf("\n");
	}else printf("IMPOSSIBLE\n");
	return 0;
}
