#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 100000
int sa[N],r[N],wa[N],wb[N],tmp[N],wv[N];
int rank[N],height[N],n,m,A[N],len,lz,v[N],wz[N],ans;
int vi[N],sum[N],vs[N];
bool cmp(int *r,int a,int b,int l){
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
void SA(int *r,int *sa,int n,int m){
	int i,j,p;int *x=wa;int *y=wb;int *ws=tmp;
	for (i=0;i<m;i++)ws[i]=0;
	for (i=0;i<n;i++)++ws[x[i]=r[i]];
	for (i=1;i<m;i++)ws[i]+=ws[i-1];
	for (i=n-1;i>=0;i--)sa[--ws[x[i]]]=i;
	for (p=1,j=1;p<n;m=p,j*=2){
		for (p=0,i=n-j;i<n;i++)y[p++]=i;
		for (i=0;i<n;i++)if (sa[i]>=j)y[p++]=sa[i]-j;
		for (i=0;i<m;i++)ws[i]=0;
		for (i=0;i<n;i++)wv[i]=x[y[i]];
	    for (i=0;i<n;i++)++ws[wv[i]];
	    for (i=1;i<m;i++)ws[i]+=ws[i-1];
	    for (i=n-1;i>=0;i--)sa[--ws[wv[i]]]=y[i];
		for (std::swap(x,y),p=1,x[sa[0]]=0,i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j) ?p-1:p++;
	}
}
void get_height(int *r,int *sa,int n){
	int i,j,k=0;
	for (i=1;i<=n;i++)rank[sa[i]]=i;
	for (i=0;i<n;height[rank[i++]]=k)
		for (k ?k--:0, j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
}
//---------------------------------------------------------------Suffix Array
int main(){
	freopen("c1360.in","r",stdin);
	freopen("c1360.out","w",stdout);
	scanf("%d%d",&n,&m);
	len=-1;lz=1000;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		for (int j=1;j<=x;j++)scanf("%d",&r[++len]),v[len]=i;
		r[++len]=++lz;
		scanf("%d",&x);
		for (int j=1;j<=x;j++)scanf("%d",&r[++len]),v[len]=i;
		r[++len]=++lz;
	}
	for (int i=1;i<=m;i++){
		scanf("%d",&A[i]);
		wz[i]=len+1;
		for (int j=1;j<=A[i];j++)scanf("%d",&r[++len]);
		r[++len]=++lz;
	}
	SA(r,sa,len+1,lz+1);
	get_height(r,sa,len);
	for (int i=1;i<=m;i++){
		int x=rank[wz[i]];
		int L,R;L=R=x;ans=0;
		while (height[L]>=A[i])L--;
		while (height[R]>=A[i])R++;
		for (int j=L;j<R;j++){
			int y=v[sa[j]];
			if (y&&vi[y]!=i){
				++ans;
				vi[y]=i;
				++sum[y];
			}
		}
		printf("%d\n",ans);
	}
	for (int i=1;i<=n;i++)printf("%d ",sum[i]);
	return 0;
}