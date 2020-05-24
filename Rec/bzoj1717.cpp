#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define N 60000
#define INF 0x5f5f5f5f
struct po{
	int v,pos;
}poi[N];
int r[N],sa[N],wa[N],wb[N],tmp[N],wv[N];
int rank[N],height[N],n,K;
bool cmp(int *r,int a,int b,int l){
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
void SA(int *r,int *sa,int n,int m){
	int i,j,p;int *x=wa;int *y=wb;int *ws=tmp;
	for (i=0;i<m;i++)ws[i]=0;
	for (i=0;i<n;i++)++ws[x[i]=r[i]];
	for (i=1;i<m;i++)ws[i]+=ws[i-1];
	for (i=n-1;i>=0;i--)sa[--ws[x[i]]]=i;
	for (j=1,p=1;p<n;j*=2,m=p){
		for (p=0,i=n-j;i<n;i++)y[p++]=i;
		for (i=0;i<n;i++)if (sa[i]>=j) y[p++]=sa[i]-j;
		for (i=0;i<n;i++)wv[i]=x[y[i]];
		for (i=0;i<m;i++)ws[i]=0;
		for (i=0;i<n;i++)++ws[wv[i]];
		for (i=1;i<m;i++)ws[i]+=ws[i-1];
		for (i=n-1;i>=0;i--)sa[--ws[wv[i]]]=y[i];
		for (std::swap(x,y),p=1,i=1,x[sa[0]]=0;i<n;i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j) ?p-1:p++;
	}
}
void get_height(int *r,int *sa,int n){
	int i,j,k=0;
	for (i=1;i<=n;i++)rank[sa[i]]=i; 
	for (i=0;i<n;height[rank[i++]]=k)
		for (k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];++k);
}
//------------------------------------------------Suffix Array
bool cm(po a,po b){return a.v<b.v;}
bool check(int x){
	int tmp=0;
	for (int i=1;i<=n;i++)
		if (height[i]<x)tmp=0;
		else{
			++tmp;
			if (tmp+1>=K)return 1;
		}
	return 0;
}
void solve(){
	int l=0;int r=n;int ans=0;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	printf("%d",ans);
}
int main(){
	freopen("bzoj1717.in","r",stdin);
	freopen("bzoj1717.out","w",stdout);
	scanf("%d%d",&n,&K);
	for (int i=0;i<n;i++)scanf("%d",&poi[i].v),poi[i].pos=i;
	std::sort(poi,poi+n,cm);
	int j=1;
	r[poi[0].pos]=1;
	for (int i=1;i<n;i++){
		if (poi[i].v!=poi[i-1].v)j++;
		r[poi[i].pos]=j;
	}
	SA(r,sa,n+1,j+1);
	get_height(r,sa,n);
	solve();
	return 0;
}