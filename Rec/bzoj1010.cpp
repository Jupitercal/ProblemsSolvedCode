#include<bits/stdc++.h>
typedef long long LL;
#define N 500005
int q[N],n,m,tail,head;
LL F[N],c[N],s[N],L;
LL UP(int x,int y){
	return F[x]+s[x]*s[x]+2*L*s[x]-F[y]-s[y]*s[y]-2*L*s[y];
}
LL down(int x,int y){
	return 2*(s[x]-s[y]);
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d%lld",&n,&L)!=EOF){
		memset(F,0,sizeof(F));
		memset(q,0,sizeof(q));
		for (int i=1;i<=n;i++){
			scanf("%lld",&c[i]);
			c[i]++;
			s[i]=s[i-1]+c[i];
		}
		L++;
		head=1;tail=1;
		for (int i=1;i<=n;i++){
			while (head<tail&&UP(q[head+1],q[head])<s[i]*down(q[head+1],q[head]))++head;
			F[i]=F[q[head]]+1LL*(s[i]-s[q[head]]-L)*(s[i]-s[q[head]]-L);
			while (head<tail&&UP(i,q[tail])*down(q[tail],q[tail-1])<UP(q[tail],q[tail-1])*down(i,q[tail]))--tail;
			q[++tail]=i;
		}
		printf("%lld\n",F[n]);
	}
	return 0;
}