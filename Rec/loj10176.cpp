#include<bits/stdc++.h>
#define N 200020
typedef long long LL;
int n,m,tail,head;
int q[N];
LL a[N],ans,sum[N];
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];
	head=1;tail=1;
	ans=-10000000000;
	for (int i=1;i<=n;i++){
		while (head<=tail&&i-q[head]>m)++head;
		if(head<=tail)ans=std::max(ans,sum[i]-sum[q[head]]);
		while (head<=tail&&sum[q[tail]]>=sum[i])--tail;
		q[++tail]=i;
	}
	printf("%lld",ans);
	return 0;
}