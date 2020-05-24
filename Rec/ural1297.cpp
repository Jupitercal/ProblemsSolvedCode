#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 10000
int sa[N],wa[N],wb[N],tmp[N],wv[N],ans;
int rank[N],height[N],n,Log[N],st[N][20],pos,len;
int r[N];
char s[N];
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
//--------------------------------------------------------------------------------Suffix Array
void init_RMQ(){
	for (int i=1;i<=n;i++)st[i][0]=height[i];
	for (int i=1;i<=Log[n];i++)
		for (int j=1;j<=n-(1<<(i-1));j++)
			st[j][i]=std::min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
}
int RMQ(int l,int r){
	l=rank[l];r=rank[r];
	if (l>r)std::swap(l,r);
	l++;
	int X=Log[r-l+1];
	return std::min(st[l][X],st[r-(1<<X)+1][X]);
}
//--------------------------------------------------------------------------------RMQ
int main(){
	freopen("ural1297.in","r",stdin);
	freopen("ural1297.out","w",stdout);
	Log[0]=-1;
	for (int i=1;i<=10000;i++)Log[i]=Log[i>>1]+1;
	while (scanf("%s",s)!=EOF){
	    len=strlen(s);
		for (int i=0;i<len;i++)r[i]=(int)s[i];
		r[len]=128;
		for(int i = 0; i < len; i++) r[len + 1 + i] = (int)s[len - 1 - i]; 
		n=len*2+1;
		r[n]=0;
	    SA(r,sa,n+1,130);
		ans=0;pos=0;
		get_height(r,sa,n);
		init_RMQ();
		for (int i=0;i<len;i++){
			int x=RMQ(i,n-i-1);
			if (x*2-1>ans){
				ans=x*2-1;
				pos=i-x+1;
			}
			x=RMQ(i,n-i);
			if (x*2>ans){
				ans=x*2;
				pos=i-x;
			}
		}
		for (int i=0;i<ans;i++)printf("%c",s[i+pos]);
		printf("\n");
	}
}