#include<bits/stdc++.h>
#define N 550005
typedef long long LL;
int min[N][20],wa[N],wb[N],tmp[N],T,a[N];
int sa[N],wv[N],rank[N],height[N],n,r[N],next[N],LOG[N],len;
char s[N];
LL sum[N];
bool cmp(int *r,int a,int b,int l){
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
void SA(int *r,int *sa,int n,int m){
	int i,j,p;int *x=wa;int *y=wb;int *ws=tmp;
	for (i=0;i<m;i++)ws[i]=0;
	for (i=0;i<n;i++)ws[x[i]=r[i]]++;
	for (i=1;i<m;i++)ws[i]=ws[i-1]+ws[i];
	for (i=n-1;i>=0;i--)sa[--ws[x[i]]]=i;
	for (j=1,p=1;p<n;m=p,j*=2){
		for (p=0,i=n-j;i<n;i++)y[p++]=i;
		for (i=0;i<n;i++)if (sa[i]>=j)y[p++]=sa[i]-j;
		for (i=0;i<n;i++)wv[i]=x[y[i]];
		for (i=0;i<m;i++)ws[i]=0;
		for (i=0;i<n;i++)ws[wv[i]]++;
		for (i=1;i<m;i++)ws[i]=ws[i]+ws[i-1];
		for (i=n-1;i>=0;i--)sa[--ws[wv[i]]]=y[i];
		for (std::swap(x,y),p=1,x[sa[0]]=0,i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j) ?p-1:p++;
	}
}
void get_height(int *r,int *sa,int n){
	int i,j,k=0;
	for (i=1;i<=n;i++)rank[sa[i]]=i; 
	for (i=0;i<n;height[rank[i++]]=k)
		for (k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];++k);
}
void RMQ_init(){
	for (int i=1;i<=n+1;i++){
		min[i][0]=i-1;
	}
	for (int i=1;i<=20;i++){
		for (int j=1;j<=n+1;j++){
			if (j-(1<<i)<=0)continue;
			if (height[min[j][i-1]]<=height[min[j-(1<<(i-1))][i-1]])min[j][i]=min[j][i-1];
			else min[j][i]=min[j-(1<<(i-1))][i-1];
		}
	}
}
int lcp(int x,int y){
	y++;
	if (x>y)std::swap(x,y);
	//y++;
	if (x==y)return y;
	int v=LOG[y-x];
	if (height[min[y][v]]<=height[min[x+(1<<v)][v]])return min[y][v];
	else return min[x+(1<<v)][v];
}
LL solve(int l,int r){
	if (l==r)return 0;
	int p=lcp(l+1,r);
	LL L=solve(l,p-1);
	LL R=solve(p,r);
	int h=height[p];
	LL count=(sum[r]-sum[p-1])*(p-l)+(sum[p-1]-sum[l-1])*(r-p+1);
	return count+L+R-1LL*(r-p+1)*(p-l)*2*h;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	#endif
	LOG[1]=0;
	for (int i=2;i<=500005;i++)LOG[i]=LOG[i/2]+1;
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<n;i++)r[i]=s[i]-'a'+1;
	r[n]=0;
	SA(r,sa,n+1,30);
	get_height(r,sa,n);
	RMQ_init();
	sum[0]=0;
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1]+n-sa[i];
	}
	printf("%lld\n",solve(1,n));
	return 0;
}