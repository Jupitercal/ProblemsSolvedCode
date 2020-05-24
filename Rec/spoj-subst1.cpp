#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
//using namespace std;
#define N 60005
int n,tmp[N],wa[N],wb[N],sa[N],r[N],rank[N],height[N];
int a[N],wv[N],k,t;
char s[N];
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
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&t);
	while (t--){
		scanf("%s",s);
		int cmp=0;
		n=strlen(s);
		for (int i=0;i<n;i++){
			a[i]=(int)s[i];
			cmp=std::max(cmp,a[i]);
		}
		SA(a,sa,n+1,cmp+1);
		get_height(a,sa,n);
		int ans=0;
		for (int i=1;i<=n;i++)ans+=n-sa[i]-height[i];
		printf("%d\n",ans);
	}
	return 0;
}