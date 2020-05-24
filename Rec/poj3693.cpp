#include<cmath>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdio>
#define N 100005
int min[N][20],LOG[N],wa[N],wb[N],tmp[N];
int sa[N],wv[N],rank[N],height[N],n,ans[N],cnt,r[N];
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
void RMQ_init(){
	for (int i=1;i<=n;i++)min[i][0]=height[i];
	for (int i=1;i<=20;i++){
		for (int j=1;j<=n;j++){
			if (j-(1<<i)<=0)continue;
			min[j][i]=std::min(min[j][i-1],min[j-(1<<(i-1))][i-1]);
		}
	}
}
int lcp(int x,int y){
	x=rank[x];
	y=rank[y];
	if (x>y)std::swap(x,y);
	//x++;
	int v=LOG[y-x];
	return std::min(min[y][v],min[x+(1<<v)][v]);
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	LOG[1]=0;LOG[2]=1;
	for (int i=3;i<=N-5;i++)LOG[i]=LOG[i/2]+1;
	int cases=0;
	while (scanf("%s",s)!=EOF){
		if (s[0]=='#')break;
		++cases;
		n=strlen(s);
		for (int i=0;i<n;i++)r[i]=(int)s[i];
		SA(r,sa,n+1,256);
		get_height(r,sa,n);
		RMQ_init();
		int mx=-1;
		cnt=0;
		for (int l=1;l<n;l++){
			for (int i=0;i<n-l;i+=l){
				int K=lcp(i,i+l);
				int p=K/l+1;
				int t=l-K%l;
				if (i-t>=0&&K%l){
					int mk=lcp(i-t,i+l-t);
					if (mk/l+1>p)p=mk/l+1;
				}	
				if (p>mx){
					mx=p;
					cnt=0;
					ans[++cnt]=l;
				}else if (p==mx){
					ans[++cnt]=l;
				}
			}
		}
		bool f=0;
		int anspos=0;
		int ansl=0;
		for (int i=1;i<=n;i++){
			if (f)break;
			for (int j=1;j<=cnt;j++){
				if (lcp(sa[i],sa[i]+ans[j])>=(mx-1)*ans[j]){
					f=1;
					anspos=sa[i];
					ansl=ans[j]*mx;
					//printf("%d %d\n",ans[j],mx);
					break;
				}
			}
		}
		printf("Case %d: ",cases);
		for (int i=0;i<ansl;i++)printf("%c",s[i+anspos]);
		//printf("%d\n",mx);
		printf("\n");
	}
	return 0;
}