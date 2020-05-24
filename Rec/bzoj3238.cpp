#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cmath>
#define N 600000
#define INF 0x5f5f5f5f
typedef long long LL;
char r[N];
int wa[N],wb[N],height[N],sa[N],tmp[N],rank[N],n;
int L[N],R[N],stack[N],wv[N];
bool cmp(int *r,int a,int b,int l){
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
void SA(char *r,int *sa,int n,int m){
	int i,j,p;int *x=wa;int *y=wb;int *ws=tmp;
	for (i=0;i<m;i++)ws[i]=0;
	for (i=0;i<n;i++)ws[x[i]=r[i]]++;
	for (i=1;i<m;i++)ws[i]+=ws[i-1];
	for (i=n-1;i>=0;i--)sa[--ws[x[i]]]=i;
	for (j=1,p=1;p<n;m=p,j*=2){
		for (p=0,i=n-j;i<n;i++)y[p++]=i;
		for (i=0;i<n;i++)if (sa[i]>=j)y[p++]=sa[i]-j;
		for (i=0;i<m;i++)ws[i]=0;
		for (i=0;i<n;i++)wv[i]=x[y[i]];
		for (i=0;i<n;i++)++ws[wv[i]];
		for (i=1;i<m;i++)ws[i]+=ws[i-1];
		for (i=n-1;i>=0;i--)sa[--ws[wv[i]]]=y[i];
		for (std::swap(x,y),i=1,p=1,x[sa[0]]=0;i<n;i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j) ?p-1:p++;
	}
}
void get_height(char *r,int *sa,int n){
	int i,j,k=0;
	for (i=1;i<=n;i++)rank[sa[i]]=i;
	for (i=0;i<n;height[rank[i++]]=k)
		for (k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
	return;
}
void solve(){
	LL ans=0;
	int top=0;
	stack[0]=0;
	height[0]=-INF;
	height[n+1]=-INF;
	for (int i=1;i<=n;i++){
		while (height[stack[top]]>=height[i])--top;
		if (stack[top]==0)L[i]=1;
			else L[i]=stack[top]+1;
		stack[++top]=i;
	}
	top=0;stack[0]=n+1;
	for (int i=n;i>=1;i--){
		while (height[stack[top]]>height[i])--top;
		if (stack[top]==n+1)R[i]=n;
			else R[i]=stack[top]-1;
		stack[++top]=i;
	}
	for (int i=1;i<=n;i++)ans=ans+(LL)i*(n-1)-(LL)2*(i-L[i]+1)*(R[i]-i+1)*height[i];
	printf("%lld",ans);
}
int main(){
	freopen("bzoj3238.in","r",stdin);
	freopen("bzoj3238.out","w",stdout);
	scanf("%s",r);
	n=strlen(r);
	SA(r,sa,n+1,256);
	get_height(r,sa,n);
	solve();
	return 0;
}