#include<bits/stdc++.h>
#define N 30005
int n,len,r[N],wa[N],tmp[N],wb[N],sa[N],rank[N],height[N],wv[N],ws[N];
int start[20],end[20];
char s[N];
bool b[20];
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
bool check(int x){
	int cnt=0;
	memset(b,0,sizeof(b));
	for (int i=1;i<=len;i++){
		if (height[i]<x){
			memset(b,0,sizeof(b));cnt=0;
		}else{
			for (int j=1;j<=n;j++){
				if (sa[i]<=end[j]&&sa[i]>=start[j]){
					if (!b[j])++cnt,b[j]=1;
				}
				if (i>=1)
				if (sa[i-1]<=end[j]&&sa[i-1]>=start[j]){
					if (!b[j])++cnt,b[j]=1;
				}
			}
		//	if (x==1)printf("%d ： %d\n",i,cnt);
			if (cnt>=n)return 1;
		}
	}
	return 0;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	#endif
	scanf("%d",&n);
	int bf=0;
	for (int i=1;i<=n;i++){
		scanf("%s",s+len);
		len=strlen(s);
		s[len++]='z'+i;
		start[i]=bf;
		end[i]=len-2;
		bf=len;
	//	printf("%d : %d , %d\n",i,start[i],end[i]);
	}
	//printf("%s\n%d\n",s,len);
	for (int i=0;i<len;i++)r[i]=s[i]-'a';
	r[len]=0;
	SA(r,sa,len+1,100);
	get_height(r,sa,len);
	//for (int i=1;i<=len;i++)printf("%d: %d\n",height[i],sa[i]);
	int l=0;int r=len;int ans=0;
	while (l<=r){
		int mid=(l+r)/2;
		//printf("%d\n",mid);
		if (check(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}