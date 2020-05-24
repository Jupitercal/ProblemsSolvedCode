#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 200000
#define INF 0x5f5f5f5f
typedef long long LL;
int wa[N],wb[N],wv[N],tmp[N],Log[N],sa[N];
char s[N];
int n,Q;
int height[N],rank[N];
LL ans[N],st[N][20],l1[N],r1[N],l2[N],r2[N],num[N];
bool cmp(int *r,int a,int b,int l){
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
void SA(char *r,int *sa,int n,int m){
	int i,j,p;int *x=wa;int *y=wb;int *ws=tmp;
	for (i=0;i<m;i++)ws[i]=0;
	for (i=0;i<n;i++)++ws[x[i]=r[i]];
	for (i=1;i<m;i++)ws[i]+=ws[i-1];
	for (i=n-1;i>=0;i--)sa[--ws[x[i]]]=i;
	for (p=1,j=1;p<n;m=p,j*=2){
		for (p=0,i=n-j;i<n;i++)y[p++]=i;
		for (i=0;i<n;i++)if (sa[i]>=j)y[p++]=sa[i]-j;
		for (i=0;i<n;i++)wv[i]=x[y[i]];
		for (i=0;i<m;i++)ws[i]=0;
	    for (i=0;i<n;i++)++ws[wv[i]];
	    for (i=1;i<m;i++)ws[i]+=ws[i-1];
	    for (i=n-1;i>=0;i--)sa[--ws[wv[i]]]=y[i];
		for (std::swap(x,y),p=1,x[sa[0]]=0,i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j) ?p-1:p++;
	}
}
void get_height(char *r,int *sa,int n){
	int i,j,k=0;
	for (i=1;i<=n;i++)rank[sa[i]]=i;
	for (i=0;i<n;height[rank[i++]]=k)
		for (k? k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
}
int RMQ(int l,int r){
	if (l>r)std::swap(l,r);
	int x=Log[r-l+1];
	return std::min(st[l][x],st[r-(1<<x)+1][x]);
}
void init_RMQ(){
	for (int i=1;i<=n;i++)st[i][0]=height[i];
	for (int i=1;i<=Log[n];i++)
		for (int j=1;j<=n-(1<<(i-1));j++)
			st[j][i]=std::min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
}
//---------------------------------------------------------------Suffix Array
int main(){
	freopen("bzoj3230.in","r",stdin);
	freopen("bzoj3230.out","w",stdout);
	scanf("%d%d",&n,&Q);
	scanf("%s",s);
	Log[0]=-1;
	for (int i=1;i<=n;i++)Log[i]=Log[i>>1]+1;
	SA(s,sa,n+1,256);
	get_height(s,sa,n);
	init_RMQ();
	for (int i=1;i<=n+1;i++)num[i]=num[i-1]+(n-sa[i])-height[i];
	for (int i=1;i<=Q;i++){
		LL x,y;
		scanf("%lld%lld",&x,&y);
		if(x>num[n]||y>num[n]) {l1[i]=-1;continue;}
		l1[i]=std::lower_bound(num+1,num+n+1,x)-num;
		r1[i]=sa[l1[i]]+x-num[l1[i]-1]-1+height[l1[i]];
		l1[i]=sa[l1[i]];
		l2[i]=std::lower_bound(num+1,num+n+1,y)-num;
		r2[i]=sa[l2[i]]+y-num[l2[i]-1]-1+height[l2[i]];
		l2[i]=sa[l2[i]];
	}
	for (int i=1;i<=Q;i++)
	if (l1[i]!=-1){
		int p=rank[l1[i]];int q=rank[l2[i]];
		if (p>q)std::swap(p,q);
		LL x=RMQ(p+1,q);
		if (l1[i]==l2[i])x=INF;
		x=std::min(x,(LL)std::min(r1[i]-l1[i]+1,r2[i]-l2[i]+1));
		ans[i]+=x*x;
	}
	std::reverse(s,s+n);
	SA(s,sa,n+1,256);
	get_height(s,sa,n);
	init_RMQ();
	for (int i=1;i<=Q;i++)
	if (l1[i]!=-1){
		int p=n-1-r1[i];int q=n-1-r2[i];
		p=rank[p];q=rank[q];
		if (p>q)std::swap(p,q);
		LL x=RMQ(p+1,q);
		if (r1[i]==r2[i])x=INF;
		x=std::min(x,(LL)std::min(r1[i]-l1[i]+1,r2[i]-l2[i]+1));
		ans[i]+=x*x;
	}
	for (int i=1;i<=Q;i++)
		if (l1[i]!=-1)printf("%lld\n",ans[i]);
			else printf("-1\n");
	return 0;
}