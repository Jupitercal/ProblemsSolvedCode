/*
ID: Rec
PROG: test
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 2010 
#define INF 0x5f5f5f5f5f5f5f5f
typedef long long LL;
struct aa{
	int op,next,p;
	LL f;
}da[400010];
int dd,n,S,T,dist[N],tou[N],l[N],r[N],cnt[N];
LL X[N],Y[N],ans,P,Xor[N],And[N];
LL gcd(LL x,LL y){return y?gcd(y,x%y):x;}
void add(int x,int y,LL f){
	da[++dd].p=y;da[dd].next=tou[x];tou[x]=dd;da[dd].op=dd+1,da[dd].f=f;
	da[++dd].p=x;da[dd].next=tou[y];tou[y]=dd;da[dd].op=dd-1;da[dd].f=0;
}
LL sap(int x,LL delta){
	if (x==T)return delta;
	LL sum=0;int mindis=T;
	for (int i=tou[x];i;i=da[i].next){
		int v=da[i].p;
		if (dist[x]==dist[v]+1&&da[i].f){
			LL save=sap(v,std::min(delta-sum,da[i].f));
			da[i].f-=save;
			da[da[i].op].f+=save;
			sum+=save;
			if (dist[S]>T || sum==delta)return sum; 
		}
		if (da[i].f)mindis=std::min(mindis,dist[v]);
	}
	if (sum==0){
		if (--cnt[dist[x]]==0)dist[S]=T+1;
		else cnt[dist[x]=mindis+1]++;
	}
	return sum;
}
int main(){
	freopen("zoj3760.in","r",stdin);
	freopen("zoj3760.out","w",stdout);
	while (scanf("%d%lld",&n,&P)!=EOF){
		dd=0;
		memset(dist,0,sizeof(dist));
		memset(cnt,0,sizeof(cnt));
		memset(tou,0,sizeof(tou));
		l[0]=r[0]=0;
		ans=0;
		S=0;T=n+1;
		for (int i=1;i<=n;i++){
			scanf("%lld%lld",&X[i],&Y[i]);
			if ((X[i]^Y[i])&1)l[++l[0]]=i;
			else r[++r[0]]=i;
			And[i]=X[i]&Y[i];
			Xor[i]=X[i]^Y[i];
			ans+=And[i];
		}
		for (int i=1;i<=l[0];i++)add(S,l[i],And[l[i]]);
		for (int i=1;i<=r[0];i++)add(r[i],T,And[r[i]]);
		for (int i=1;i<=l[0];i++){
			for (int j=1;j<=r[0];j++){
				if (gcd(Xor[l[i]]^Xor[r[j]],P)<=1)add(l[i],r[j],INF);
			}
		}
		while (dist[S]<=T)ans-=sap(S,INF);
		printf("%lld\n",ans);
	}
	return 0;
}
