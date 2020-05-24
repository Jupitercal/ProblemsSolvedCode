#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#define N 60000 
#define MOD 1000000007
#define eps 1e-10
typedef long long LL;
LL f[N],ans[600][600],anx;
int n;
const double pi=acos(-1);
struct aa{
	int x,y,id;
	double ang;
}poi[N],p[N];
bool cmp(aa a,aa b){return a.ang<b.ang;}
void init(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d%d",&poi[i].x,&poi[i].y),poi[i].id=i;
	f[0]=f[1]=1;
	for (int i=2;i<=n*n;i++)f[i]=(f[i-1]+f[i-2])%(MOD-1);
}
LL ksm(LL x,int l){
	LL an=1;
	for (;l;l/=2,x=(x*x)%MOD)if (l&1)an=(an*x)%MOD;
	return an;
}
void solve(){
	for (int i=1;i<=n;i++){
		int tot=0;
		for (int j=1;j<=n;j++){
			if (j==i)continue;
			p[++tot]=poi[j];
			p[tot].ang=std::atan2(poi[j].y-poi[i].y,poi[j].x-poi[i].x);
		}
		std::sort(p+1,p+n,cmp);
		for (int j=1;j<n;j++){
			p[n - 1 + n - 1 + j] = p[n + j - 1] = p[j];
			p[n+j-1].ang=p[j].ang+2*pi;
			p[n+j-1+n-1].ang=p[n-j-1].ang+2*pi;
		}
		int l=1;
		for (int j=1;j<n;j++){
			int r=j+1;
			while (p[l].ang-p[j].ang-pi<eps)++l;
			for (int k=j+1;p[k].ang-p[j].ang-pi<=eps;k++){
				while (p[r+1].ang-p[k].ang-pi<=eps)++r;
				ans[p[j].id][p[k].id]+=(k-j-1)-(r-l+1);
				ans[p[k].id][p[j].id]=ans[p[j].id][p[k].id];
		    }
		}
	}
	for (int i=1;i<=n;i++)
	  for (int j=i+1;j<=n;j++){
			ans[i][j]/=2;
			anx=(anx*(ksm(ans[i][j],f[ans[i][j]])+1))%MOD;
	  }
}
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	init();
	anx=1;
	solve();
	printf("%lld",anx);
	return 0;
} 
