#include<bits/stdc++.h>
#define N 200005
int n,l,r,head,tail,q[N];
int F[N],a[N];
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d%d%d",&n,&l,&r);
	for (int i=0;i<=n;i++)scanf("%d",&a[i]);
	head=1;tail=0;
	memset(F,-0x5f5f5f5f,sizeof(F));
	F[0]=0;
	for (int i=l;i<=n;i++){
		while (head<=tail&&i-q[head]>r)++head;
		while (head<=tail&&F[q[tail]]<=F[i-l])--tail;
		q[++tail]=i-l;
		F[i]=F[q[head]]+a[i];
	}
	int ans=-0x5f5f5f5f;
	for (int i=n-r+1;i<=n;i++)ans=std::max(F[i],ans);
	printf("%d",ans);
	return 0;
}