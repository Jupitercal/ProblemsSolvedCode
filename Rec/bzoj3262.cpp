#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#define M 400000
int n,k,tot;
struct aa{
	int num[3],pos;
	bool op;
	void make(int x,int y,int z,bool o,int i){
		num[0]=x;num[1]=y;num[2]=z;op=o;pos=i;
	}
}tem[4][M],p[4][M],q[4][M],tmp[M];
int ans[M],anx[M];
void solve(int l,int r,int x){
	if (x==3){
		int cnt=0;
		for (int i=l;i<=r;i++){
			if (tem[x][i].op)ans[tem[x][i].pos]+=cnt;
			else cnt++;
		}
		return;
	}
	if (l>=r)return ;
	int mid=(l+r)/2;
	solve(l,mid,x);
	solve(mid+1,r,x);
	int l1=0;int l2=0;
	for (int i=l;i<=mid;i++)
	  if (!tem[x][i].op)q[x][++l1]=tem[x][i];
	for (int i=mid+1;i<=r;i++)
	  if (tem[x][i].op)p[x][++l2]=tem[x][i];
	int cnt=0;
	for (int i=1,j=1;i<=l1||j<=l2;)
	   if (i<=l1&&(j>l2 ||q[x][i].num[x]<=p[x][j].num[x]))
	     tem[x+1][++cnt]=q[x][i++];
	    else tem[x+1][++cnt]=p[x][j++];
	solve(1,cnt,x+1);
	cnt=l-1;
	for (int i=l,j=mid+1;i<=mid||j<=r;)
	   if (i<=mid&&(j>r ||tem[x][i].num[x]<=tem[x][j].num[x]))
	     tmp[++cnt]=tem[x][i++];
	    else tmp[++cnt]=tem[x][j++];
	for (int i=l;i<=r;i++)tem[x][i]=tmp[i];
} 
int main(){
	freopen("bzoj3262.in","r",stdin);
	freopen("bzoj3262.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		tem[0][i].make(x,y,z,0,i);
		tem[0][i+n].make(x,y,z,1,i);
	}
	solve(1,2*n,0);
	for (int i=1;i<=n;i++)anx[ans[i]-1]++;
	for (int i=0;i<n;i++)printf("%d\n",anx[i]);
	return 0;
}
