#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
#define N 500005
double val[N],s[N];
int n,d[N],dd,tou[N];
struct aa{
	int p,next;
}da[N*2];
void add(int x,int y){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;
}
void dfs(int x,int fa){
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (v==fa)continue;
		s[v]=s[x]+log(d[x]);
		dfs(v,x);
	}
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	memset(tou,0,sizeof(tou));
	dd=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%lf",&val[i]);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
		++d[x];++d[y];
	}
	s[1]=log(1);
	for (int i=2;i<=n;i++)--d[i];
	dfs(1,0);
	for (int i=1;i<=n;i++)s[i]+=log(val[i]);
	std::sort(s+1,s+n+1); 
	s[0]=-11000;
	int tmp=1;int ans=0;
	for (int i=1;i<=n;i++)
		if (s[i]-s[i-1]>1e-5)ans=std::max(tmp,ans),tmp=1;
		else tmp++;
	ans=std::max(tmp,ans);
	printf("%d\n",n-ans);
	for (int i=1;i<=n;i++)printf("%lf ",s[i]);
	return 0;
}