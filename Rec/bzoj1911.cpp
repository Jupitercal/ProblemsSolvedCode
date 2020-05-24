#include<bits/stdc++.h>
#define N 1000005
typedef long long LL;
LL F[N],a,b,c,x[N],s[N];
int q[N],head,tail,n;
LL getUP(int x,int y){
	return F[x]-F[y]+a*s[x]*s[x]-a*s[y]*s[y]-b*s[x]+b*s[y]; 
}
LL getDown(int x,int y){
	return (s[x]-s[y]);
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&n);
	scanf("%lld%lld%lld",&a,&b,&c);
	for (int i=1;i<=n;i++)scanf("%lld",&x[i]),s[i]=s[i-1]+x[i];
	head=tail=1;
	for (int i=1;i<=n;i++){
		while (head<tail&&getUP(q[head+1],q[head])>2*a*s[i]*getDown(q[head+1],q[head]))++head;
		F[i]=F[q[head]]+a*(s[i]-s[q[head]])*(s[i]-s[q[head]])+b*(s[i]-s[q[head]])+c;
		while (head<tail&&getUP(q[tail],q[tail-1])*getDown(i,q[tail])<getUP(i,q[tail])*getDown(q[tail],q[tail-1]))--tail;
		q[++tail]=i;
	}
	printf("%lld",F[n]);
	return 0;
}