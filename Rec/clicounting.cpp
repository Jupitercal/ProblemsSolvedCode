#include<bits/stdc++.h>
using namespace std;
#define M 1<<20
#define N 40 
vector<string>s;
int n;
int dp1[M],dp2[M];
int G[N][N],sta[N],idx[N],spc[N],p,m,stu[N];
void dfs1(int cur,int state,int tot){
	if (cur==p){
		dp1[state]=tot;
		return ;
	}
	dfs1(cur+1,state,tot);
	if ((state&stu[cur])!=state)return;
	dfs1(cur+1,state^(1<<cur),tot+1);
};
void dfs2(int cur,int used,int tot,int state){
	if (cur==n){
		dp2[used]=max(dp2[used],tot+dp1[state]);
		return;
	}
	dfs2(cur+1,used,tot,state);
	for (int i=0;i<tot;i++){
		if (G[idx[cur]][sta[i]]==-1)return;
		used|=G[idx[cur]][sta[i]];
	}
	sta[tot]=idx[cur];
	dfs2(cur+1,used,tot+1,state&stu[cur]);
};
bool cmp(int x,int y){
	return spc[x]<spc[y];
};
class Clicounting{
	public:
		int count(vector<string>g){
			n=g.size();
			memset(dp1,0,sizeof(dp1));
			memset(dp2,0,sizeof(dp2));
			memset(spc,0,sizeof(spc));
			memset(stu,0,sizeof(stu));
			//memset(G,)
			m=0;
			for (int i=0;i<n;i++)idx[i]=i;
			for (int i=0;i<n;i++)
				for (int j=0;j<n;j++)
					if (g[i][j]=='1')G[i][j]=0;
					else if (g[i][j]=='0')G[i][j]=-1;
					else {
						if (i>j)continue;
						G[i][j]=G[j][i]=1<<(m++);
						spc[i]=spc[j]=1;
					}
			sort(idx,idx+n,cmp);
			for (p=0;p<=n/2&&!spc[idx[p]];++p);
			for (int i=0;i<n;i++)
				for (int j=0;j<p;j++)
					if (G[idx[i]][idx[j]]==0){
						stu[i]|=1<<j;
					}
			dfs1(0,0,0);
			int n1=1<<p;
			for (int i=1;i<n1;i<<=1)
				for (int j=0;j<n1;j++){
					if ((i&j))continue ;
					dp1[j^i]=max(dp1[j],dp1[j^i]);
				}
			dfs2(p,0,0,n1-1);
			n1=1<<m;
			for (int i=1;i<n1;i<<=1)
				for (int j=0;j<n1;j++){
					if ((i&j))	continue;
					dp2[j^i]=max(dp2[j],dp2[j^i]);
				}
			int ans=0;
			for (int i=0;i<n1;i++)ans+=dp2[i];
			return ans;
		};
};
int main(){
	while (scanf("%d",&n)!=EOF){
		Clicounting* it=new Clicounting;
		s.clear();
		for (int i=0;i<n;i++){
			s.push_back("");
			cin>>s[i];
		}
		printf("%d\n",it->count(s));
	}
	return 0;
}