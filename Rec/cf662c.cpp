#include<bits/stdc++.h>
#define N 200000
typedef long long LL;
int n,m;
LL b[1<<22],a[1<<22],g[22][N];
char s[N];
void FWT_xor(LL *a,int opt,int n){
	for (int i=1;i<n;i<<=1)
		for (int p=i<<1,j=0;j<n;j+=p)
			for (int k=0;k<i;k++){
				LL x=a[k+j],y=a[i+j+k];
				a[k+j]=x+y;a[i+j+k]=x-y;
				if (opt==-1)a[k+j]=1LL*a[k+j]/2,a[i+j+k]=1LL*a[i+j+k]/2;

			}
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		for (int j=0;j<m;j++)g[i][j+1]=s[j]-'0';
	}
	int len=1<<n;
	for (int i=1;i<=m;i++){
		int c=0;
		for (int j=1;j<=n;j++)c=c*2+g[j][i];
		a[c]++;
	}
	for (int i=0;i<len;i++)b[i]=b[i/2]+(i&1);
	for (int i=0;i<len;i++)b[i]=std::min(b[i],n-b[i]);
	FWT_xor(a,1,len);
	FWT_xor(b,1,len);
	for (int i=0;i<len;i++)b[i]*=a[i];
	FWT_xor(b,-1,len);
	LL ans=100000000;
	for (int i=0;i<len;i++)ans=std::min(ans,b[i]);
	printf("%lld",ans) ;
	return 0;
}