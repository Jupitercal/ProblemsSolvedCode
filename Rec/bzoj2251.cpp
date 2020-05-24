#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#define N 20000
char s[N];
int sa[N],tmp[N],wv[N],n;
int r[N];
int wa[N],wb[N],rank[N],height[N];
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
int main(){
	freopen("bzoj2251.in","r",stdin);
	freopen("bzoj2251.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=0;i<n;i++)r[i]=s[i]-'0'+1;
	SA(r,sa,n+1,3);
	get_height(r,sa,n);
	for (int i=1;i<=n;i++)
		for (int j=height[i]+1;sa[i]+j-1<n;j++){
			int L=0,R=0;
		    for (L=i;!L&&height[L]>=j;L--);
		    for (R=i+1;R<=n&&height[R]>=j;R++);
		    if (R-L>1)printf("%d\n",R-L);
		}
	return 0;
}