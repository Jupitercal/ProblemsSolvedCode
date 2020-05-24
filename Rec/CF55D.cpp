#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#define MOD 2520
typedef long long LL;
int T,tot,ws[30],n,m,t[MOD],len;
LL F[30][2530][51];
void init(){
	tot=0;
	for (int i=1;i<=MOD;i++)if (MOD%i==0)t[tot++]=i;
	memset(F,-1,sizeof(F));
} 
int gcd(int a,int b){
	if (b==0)return a;
	else return gcd(b,a%b);
}
int lcm(int x,int y){return x*y/gcd(x,y);}
int find(int x){
	int l=0;int r=tot;
	while (l+1!=r){
		int mid=(l+r)/2;
		if (x<t[mid])r=mid;
		else l=mid;
	}
	return l;
}
LL dfs(int pos,int mo,int nmo,int f){
	if (pos==-1){
		if (mo%t[nmo]==0)return 1;
		else return 0;
	} 
	if (!f&&F[pos][mo][nmo]!=-1)return F[pos][mo][nmo];
	int ma=f?ws[pos]:9;LL m=0;
	for (int i=0;i<=ma;i++){
		int nkmo=nmo;
		if (i)nkmo=find(lcm(t[nmo],i));
		m+=dfs(pos-1,(mo*10+i)%MOD,nkmo,f&&i==ma);
	}
	if (!f)F[pos][mo][nmo]=m;
	return m;
}
LL solve(LL x){
	len=0;
	while (x)ws[len++]=x%10,x/=10;
	return dfs(len-1,0,0,1);
}
int main(){
	freopen("CF55D.in","r",stdin);
	freopen("CF55D.out","w",stdout);
	scanf("%d",&T);
	init();
	while (T--){
		LL l,r;
		scanf("%I64d%I64d",&l,&r);
		printf("%I64d\n",solve(r)-solve(l-1));
	}
	return 0;
}
