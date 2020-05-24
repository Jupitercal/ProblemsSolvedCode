#include<bits/stdc++.h>
#define N 300000
int len,T,m,q,n,a[N],b[N];
char s[30];
void FWT_or(int *a,int opt,int n){
	for (int i=1;i<n;i<<=1)
		for (int p=i<<1,j=0;j<n;j+=p)
			for (int k=0;k<i;k++){
				if (opt==1)a[i+j+k]=(a[j+k]+a[j+i+k]);
				else a[i+j+k]=(a[i+j+k]-a[j+k]);
			}
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	for (int cases=1;cases<=T;cases++){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		printf("Case #%d:\n",cases);
		scanf("%d%d",&n,&m);
		int len=1<<m;
		for (int i=1;i<=n;i++){
			scanf("%s",s);
			int le=strlen(s);
			int l=0;
			for (int j=0;j<le;j++) l=l*2+s[j]-'0';
			a[l]++;
		}
		for (int i=1;i<=n;i++){
			scanf("%s",s);
			int le=strlen(s);
			int l=0;
			for (int j=0;j<le;j++) l=l*2+s[j]-'0';
			b[l]++;
		}
		FWT_or(a,1,len);
		FWT_or(b,1,len);
		for (int i=0;i<len;i++)b[i]=(b[i]*a[i]);
		FWT_or(b,-1,len);
		int q;
		scanf("%d",&q);
		for (int i=1;i<=q;i++){
			scanf("%s",s);
			int le=strlen(s);
			int l=0;
			for (int j=0;j<le;j++) l=l*2+s[j]-'0';
			printf("%d\n",b[l]);
		}
	}
	return 0;
}