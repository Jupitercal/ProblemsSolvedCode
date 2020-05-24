#include<bits/stdc++.h>
#define N 1000005
typedef long long LL;
LL s[N],c[N],a[N],b[N],F[N],ans;
int n,q[N],head,tail;
LL getUP(int x,int y){
	return F[x]-F[y]; 
}
LL getDown(int x,int y){
	return x-y;
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++)scanf("%lld",&b[i]);
	for (int i=1;i<=n;i++)s[i]=s[i-1]+b[i];
	for (int i=1;i<=n;i++)ans+=b[i]*(n-i);
	ans+=a[n];
	head=tail=1;
	q[head]=n;
	F[n]=0;
	LL cut=0;
	for (int i=n-1;i>=1;i--){
		while (head<tail&&getUP(q[head+1],q[head])>-s[i]*getDown(q[head+1],q[head]))++head;
		F[i]=F[q[head]]+s[i]*(q[head]-i)-a[i];
		cut=std::max(cut,F[i]);
		while (head<tail&&getUP(q[tail],q[tail-1])*getDown(i,q[tail])>getUP(i,q[tail])*getDown(q[tail],q[tail-1]))--tail;
		q[++tail]=i;
	}
	printf("%lld\n",ans-cut);
	return 0;
}