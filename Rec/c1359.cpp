#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#define N 40000
int n,son[N*6][2];
bool col[N*6],vis[N*6],ins[N*6];
struct ac_auto{
	std::queue<int>q; 
	int fail[N*6],nod;
	char s[N];
	void insert(){
		for (int i=1;i<=n;i++){
			scanf("%s",s);
			int len=strlen(s);
			int p=0;
			for (int ii=0;ii<len;ii++){
				int x=s[ii]-'0';
				if (!son[p][x])son[p][x]=++nod;
				p=son[p][x];
			}
			col[p]=1;
		}
	}
	void build(){
		for (int i=0;i<=1;i++)if (son[0][i])q.push(son[0][i]);
		while (!q.empty()){
			int u=q.front();q.pop();
			for (int i=0;i<=1;i++)
				if (!son[u][i])son[u][i]=son[fail[u]][i];
				else{
					fail[son[u][i]]=son[fail[u]][i];
					col[son[u][i]]|=col[fail[son[u][i]]];
					q.push(son[u][i]);
				}
		}
	} 
}Ac;
bool dfs(int x){
	ins[x]=1;
	for (int i=0;i<=1;i++){
		int v=son[x][i];
		if (ins[v])return 1;
		if (col[v]||vis[v])continue;
		vis[v]=1;
		if (dfs(v))return 1;
	}
	ins[x]=0;
	return 0;
}
int main(){
	freopen("c1359.in","r",stdin);
	freopen("c1359.out","w",stdout);
	scanf("%d",&n);
	Ac.insert();
	Ac.build();
	if (dfs(1))printf("TAK");
	else printf("NIE");
	return 0;
}
