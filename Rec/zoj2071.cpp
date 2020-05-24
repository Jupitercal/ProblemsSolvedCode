#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 2000
#define INF 0x3f3f3f3f
struct aa{
	int p,next,f,op;
}da[N*20];
int son[N*20][26],nod,dd,S,T;
int cost[N*6],tou[N*6],dist[N*6],cnt[N*6],t,n,m,bel[N*6],ans,su;
char s[N][N/10];
bool inq[N*3];
void add(int x,int y,int len){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].op=dd+1;da[dd].f=len;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].op=dd-1;da[dd].f=0;
}
int sap(int x,int delta){
	if (x==T)return delta;
	int mindis=T;int sum=0;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (dist[x]==dist[v]+1&&da[i].f){
			int save=sap(v,std::min(da[i].f,delta-sum));
			sum+=save;
			da[i].f-=save;
			da[da[i].op].f+=save;
			if (dist[S]>=T || sum==delta) return sum;
		}
		if (da[i].f) mindis=std::min(mindis,dist[v]);
	}
	if (sum==0){
		if (--cnt[dist[x]]==0)dist[S]=T;
		else ++cnt[dist[x]=mindis+1];
	}
	return sum;
}
void dfs(int x){
	inq[x]=1;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (da[i].f&&!inq[v])dfs(v);
	}
}
void insert(char *sa,int x,int len){
	int p=0;
	for (int i=0;i<len;i++){
		int xx=sa[i]-'A';
		if (!son[p][xx])son[p][xx]=++nod;
		p=son[p][xx];
	}
	bel[p]=x;
	add(x,T,cost[x]);
}
int run(char *sa,int len){
	int p=0;
	for (int i=0;i<len;i++){
		int xx=sa[i]-'A';
		p=son[p][xx];
	}
	return bel[p];
}
int main(){
	freopen("zoj2071.in","r",stdin);
	freopen("zoj2071.out","w",stdout);
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		dd=0;nod=0;ans=0;
		memset(tou,0,sizeof(tou));
		memset(dist,0,sizeof(dist));
		memset(son,0,sizeof(son));
		memset(cnt,0,sizeof(cnt));
		memset(inq,0,sizeof(inq));
		for (int i=1;i<=n;i++)
			scanf("%s%d",s[i],&cost[i]);
		scanf("%d",&m);
		S=0;T=n+m+1;su=0;
		for (int i=1;i<=n;i++)insert(s[i],i,strlen(s[i]));
		for (int i=1;i<=m;i++){
			int x,to;
			scanf("%s%d%d",s[i+n],&x,&to);
			add(S,i+n,x);
			su+=x;
			for (int j=1;j<=to;j++){
				char ss[N];
				scanf("%s",ss);
				int y=run(ss,strlen(ss));
				add(i+n,y,INF);
			}
		}
		while (dist[S]<T)ans+=sap(S,INF);
	    printf("%d\n",su-ans);
	    dfs(S);
	    int su1=0;int su2=0;
	    for (int i=1;i<=n+m;i++)
		if (inq[i]){
			if (i<=n)su2++;
			else su1++;
		}
	    printf("%d\n",su1);
	    for (int i=n+1;i<=n+m;i++)
		   if (inq[i])printf("%s\n",s[i]);
	    printf("%d\n",su2);
	    for (int i=1;i<=n;i++)
		    if (inq[i])printf("%s\n",s[i]);
	}
	return 0;
}