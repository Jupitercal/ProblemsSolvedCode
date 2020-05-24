#include<bits/stdc++.h>
using namespace std;
#define N 51
struct aa{
	int p,next,op,f;
}da[300005];
#define INF 0x3f3f3f3f
int tou[N*N*2],dd,t,n,m;
int S,T,dx[5],dy[5],id[N][N],vis[N*N*2];
char s[N][N];
void add(int x,int y,int f){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].f=f;da[dd].op=dd+1;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].f=0;da[dd].op=dd-1;
}
bool bfs(int start, int over)
{
    queue<int>Q;
    Q.push(start);
    memset(vis, 0, sizeof(vis));
    vis[start] = 1;
    while(!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        if(now == over)
            return true;
        for(int i=tou[now]; i; i=da[i].next)
        {
            int v = da[i].p;
            if(!vis[v] && da[i].f>0)
            {
                vis[v] = vis[now]+1;
                Q.push(v);
            }
        }
    }
    return false;
}
int dfs(int u, int over, int Maxflow)
{
    if(u == over)
        return Maxflow;
    int now_flow = 0;

    for(int i=tou[u]; i; i=da[i].next)
    {
        int v = da[i].p;
        if(vis[v] == vis[u]+1 && da[i].f>0 && Maxflow-now_flow>0)
        {
            int flow = min(Maxflow-now_flow, da[i].f);

            flow = dfs(v, over, flow);

            da[i].f -= flow;
            da[da[i].op].f += flow;

            now_flow += flow;
        }
    }
    if(!now_flow)
        vis[u] = -1;
    return now_flow;
}
int dinic(int start, int over)
{
    int ans = 0;
    while(bfs(start, over))
        ans += dfs(start, over, INF);
    return ans;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&t);
	dx[0]=1;dx[1]=-1;dx[2]=0;dx[3]=0;
	dy[0]=0;dy[1]=0;dy[2]=-1;dy[3]=1;
	int cases=0;
	while (t--){
		memset(tou,0,sizeof(tou));
		dd=0;
		scanf("%d%d",&n,&m);
		S=(n+2)*(m+2)+1;T=(n+2)*(m+2)+2;
		for (int i=1;i<=n;i++)scanf("%s",s[i]+1);
		for (int i=0;i<=n+1;i++)s[i][0]=s[i][m+1]='D';
		for (int i=0;i<=m+1;i++)s[0][i]=s[n+1][i]='D';
		int c=1;
		for (int i=0;i<=n+1;i++)
			for (int j=0;j<=m+1;j++)
				id[i][j]=c++;
		c=0;
		for (int i=0;i<=n+1;i++)
			for (int j=0;j<=m+1;j++){
				for (int k=0;k<4;k++){
					int x=i+dx[k];
					int y=j+dy[k];
					if (x<0||x>n+1||y<0||y>m+1){
						continue;
					}
					add(id[i][j],id[x][y],1),++c;
				}
				if (s[i][j]=='E')continue;
				if (((i+j)%2==0&&s[i][j]=='.')||((i+j)%2==1&&s[i][j]=='D'))add(S,id[i][j],INF);
				else add(id[i][j],T,INF);
			}
		//printf("%d\n",ans);
		++cases;
		printf("Case %d: %d\n",cases,c/2-dinic(S,T));
	}
	return 0;
}