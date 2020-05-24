/*
ID: Rec
PROG: test
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
int T,n,a[3000],ans,ansnum;
int main(){
	freopen("hdu5704.in","r",stdin);
	freopen("hdu5704.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		double sum=0;
		int r=0;int l=0;
		for (int i=1;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
			r=std::max(r,a[i]);
		} 
		ansnum=n;
		for (int i=l;i<=r;i++){
			double stdi=(sum+i)/(double)n;
			stdi*=2.0/3;
			int num=1;int k=(int)stdi;
			if (i>k)continue;
			bool b=1;
			for (int j=1;j<n;j++)
			  if (a[j]>=i&&a[j]<=k){
			  	if (a[j]>i)b=0;
			  	if (a[j]==i)++num;
			  }
			if (!b)continue;
			if (num<ansnum){
				ansnum=num;
				ans=i;
			}else if (num==ansnum)ans=std::max(ans,i);
		}
		printf("%d %.2f\n",ans,1./ansnum);
	}
	return 0;
} 
