#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#define N 100010
int prime[N],last[N],num[N],ans[N],MOD,f[N];
int mu[N],T,mx;
struct aa{
	int id,x,y,a;
}poi[N];
struct sa{
	int id,x;
}F[N];
bool flag[N];
bool cmp(aa a,aa b){return a.a<b.a;}
bool cm(sa a,sa b){return a.x<b.x;}
void Mobius(){
	memset(flag,1,sizeof(flag));
	mu[1]=1;f[1]=1;
	for (int i=2;i<N;i++){
		if (flag[i]){
			prime[++prime[0]]=i;
			last[i]=1;
			f[i]=i+1;
			mu[i]=-1;
		}
		for (int j=1;j<=prime[0];j++){
			int t=prime[j]*i;
			if (t>=N)break;
			flag[t]=0;
			if (i%prime[j]==0){
				mu[t]=0;
				f[t]=last[i]+prime[j]*f[i]; 
				last[t]=last[i];
				break;
			}
			mu[t]=-mu[i];
			f[t]=f[i]*(1+prime[j]);
			last[t]=f[i];
		}
	}
}
void plus(int x,int v){
	for (;x<=mx;x+=x&(-x))num[x]+=v;
}
int Sum(int x){
	int cal=0;
	for(;x;x-=x&(-x))cal+=num[x];
	return cal;
}
int solve(int n,int m){
	if (n>m)std::swap(n,m);
	int j=0;
	int cal=0;
	for (int i=1;i<=n;i=j+1){
		j=std::min(n/(n/i),m/(m/i));
		cal+=(Sum(j)-Sum(i-1))*(n/i)*(m/i);
	}
	cal=cal&MOD;
	return cal;
}
int main(){
	freopen("bzoj3529.in","r",stdin);
	freopen("bzoj3529.out","w",stdout);
	MOD=(1u<<31)-1;
	Mobius();
	scanf("%d",&T);
	int ii=1;
	while (ii<=T){
		scanf("%d%d%d",&poi[ii].x,&poi[ii].y,&poi[ii].a);
		mx=std::max(mx,poi[ii].x);
		mx=std::max(mx,poi[ii].y); 
		poi[ii].id=ii;ii++; 
	}
	std::sort(poi+1,poi+T+1,cmp);
	for (int i=1;i<=mx;i++)F[i].id=i,F[i].x=f[i];
	std::sort(F+1,F+mx+1,cm);
	int now=1;
	for (int i=1;i<=T;i++){
		while (F[now].x<=poi[i].a&&now<=mx){
			for (int j=1;j<=mx/F[now].id;j++)plus(j*F[now].id,F[now].x*mu[j]);
			++now;
		}
		ans[poi[i].id]=solve(poi[i].x,poi[i].y);
	}
	for (int i=1;i<=T;i++)printf("%d\n",ans[i]);
	return 0; 
} 
