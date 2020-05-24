/*
ID: Rec
PROG: milk3
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define N 200
#define MOD 202021
bool B[N];
int hash[MOD],ans[N],lia,lib,lic;
bool cmp(int x,int y){return x<y;}
bool has(int x){
	int i=x%MOD;
	while (hash[i]){
		if (hash[i]==x)return 1;
		i=(i+1)%MOD;
	}
	hash[i]=x;
	return 0;
}
void dfs(int a,int b,int c){
	if (has(a*10000+b*100+c))return;
	if (a==0)
		if (!B[c])ans[++ans[0]]=c,B[c]=1;
	int x=std::min(lia-a,c);dfs(a+x,b,c-x);
	x=std::min(lia-a,b);dfs(a+x,b-x,c);
	x=std::min(lic-c,a);dfs(a-x,b,c+x);
	x=std::min(lic-c,b);dfs(a,b-x,c+x);
	x=std::min(lib-b,c);dfs(a,b+x,c-x);
	x=std::min(lib-b,a);dfs(a-x,b+x,c);
}
int main(){
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	scanf("%d%d%d",&lia,&lib,&lic);
	dfs(0,0,lic);
	std::sort(ans+1,ans+ans[0]+1,cmp);
	for (int i=1;i<ans[0];i++)printf("%d ",ans[i]);
	printf("%d",ans[ans[0]]);
	printf("\n");
	return 0; 
}

