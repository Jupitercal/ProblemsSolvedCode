#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
//using namespace std;
#define N 60005
int n,tmp[N],wa[N],wb[N],sa[N],r[N],rank[N],height[N];
int a[N],wv[N],k;
std::map<int,int>mp;
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
bool solve(int x){
	int count=1;
	for (int i=1;i<=n+1;i++){
		if (height[i]>=x){
			count++;
			if (count>=k)return 1;
		}else {
			count=1;
		}
	}
	return 0;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d%d",&n,&k);
	int cmp=0;
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if (mp[a[i]])a[i]=mp[a[i]];
		else {
			mp[a[i]]=++cmp;
			a[i]=cmp;
		}
	}
	SA(a,sa,n+1,cmp+1);
	get_height(a,sa,n);
	int l=1;int r=n;
	int ans=0;
	while (l<=r){
		int mid=(l+r)/2;
		//printf("%d %d %d\n",l,r,mid);
		if (solve(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}