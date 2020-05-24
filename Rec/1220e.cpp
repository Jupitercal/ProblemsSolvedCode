#include<bits/stdc++.h>
#define N 200005
typedef long long LL;
int n,m,s;
LL F[N],tot,ans,w[N];
std::queue<int>q;
int in[N],dd,tou[N];
bool b[N],f[N];
struct aa{
	int p,next;
}da[N*2];
void add(int x,int y){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;
}
void dfs(int x){
	f[x]=1;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (f[v])continue;
		if (b[v]){
			ans=std::max(ans,F[v]);
			continue;
		}
		tot+=w[v];
		dfs(v);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)scanf("%lld",&w[i]);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
		++in[x];++in[y];
	}
	scanf("%d",&s);
	//LL ans=0;
	for (int i=1;i<=n;i++){
		if (in[i]==1&&i!=s)q.push(i),b[i]=1,F[i]=w[i];
	}
	while (!q.empty()){
		int u=q.front();q.pop();
		for (int i=tou[u];i;i=da[i].next){
			int v=da[i].p;
			--in[v];
			F[v]=std::max(F[v],F[u]+w[v]);
			if (in[v]==1&&v!=s){
				b[v]=1;
				q.push(v);
			}
		}
	}
	tot=w[s];
	dfs(s);
	printf("%lld\n",tot+ans);
	return 0;
}