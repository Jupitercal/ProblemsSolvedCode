#include<bits/stdc++.h>
#define N 300
double ans;
int n,tou[N],dd,low[N],stack[N],dfn[N],colors,col[N],sz,tail;
double x[N][2],y[N][2];
bool v[N],f[N];
struct aa{
	int p,next;
}da[N*10];
void add(int x,int y){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;
}
double sqr(double x){return x*x;}
void dit(int x){
	++colors;
	while (stack[tail]!=x){
		col[stack[tail]]=colors;
		f[stack[tail]]=0;
		--tail;
	}
	col[stack[tail]]=colors;
	f[stack[tail]]=0;
	--tail;
}
void dfs(int x){
	dfn[x]=low[x]=++sz;v[x]=f[x]=1;
	stack[++tail]=x;
	for (int i=tou[x];i;i=da[i].next){
		int vi=da[i].p;
		if (!v[vi]){
			dfs(vi);
			low[x]=std::min(low[x],low[vi]);
		}else if (f[vi])low[x]=std::min(low[x],dfn[vi]);
	}
	if (dfn[x]==low[x])dit(x);
}
bool solve(double r){
	memset(tou,0,sizeof(tou));
	dd=sz=0;
	memset(v,0,sizeof(v));
	memset(col,0,sizeof(col));
	tail=0;colors=0;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++){
			if	(sqrt(sqr(x[i][0]-x[j][0])+sqr(y[i][0]-y[j][0]))<2*r)add(i*2-1,j*2),add(j*2-1,i*2);
			if	(sqrt(sqr(x[i][0]-x[j][1])+sqr(y[i][0]-y[j][1]))<2*r)add(i*2-1,j*2-1),add(j*2,i*2);
			if	(sqrt(sqr(x[i][1]-x[j][0])+sqr(y[i][1]-y[j][0]))<2*r)add(i*2,j*2),add(j*2-1,i*2-1);
			if	(sqrt(sqr(x[i][1]-x[j][1])+sqr(y[i][1]-y[j][1]))<2*r)add(i*2,j*2-1),add(j*2,i*2-1);
		}
	for (int i=1;i<=2*n;i++)
		if (!v[i])dfs(i);
	for (int i=1;i<=n;i++)
		if (col[2*i]==col[i*2-1])return 0;
	return 1;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		for (int i=1;i<=n;i++)scanf("%lf%lf%lf%lf",&x[i][0],&y[i][0],&x[i][1],&y[i][1]);
		double L=0;
		double R=1000000;
		for (int i=1;i<=100;i++){
			double mid=(L+R)/2;
			if (solve(mid))L=mid;
			else R=mid;
		}
		printf("%.2f\n",L);
	}
	return 0;
}