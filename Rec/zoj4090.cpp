#include<bits/stdc++.h>
#define N 200000
int T,n,m;
struct aa{
	int h,pre;
}a[N],b[N];
bool cmp(aa a,aa b){
	return a.h<b.h;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)scanf("%d",&a[i].h);
		for (int i=1;i<=m;i++)scanf("%d",&b[i].h);
		for (int i=1;i<=n;i++)scanf("%d",&a[i].pre);
		for (int i=1;i<=m;i++)scanf("%d",&b[i].pre);
		std::sort(a+1,a+n+1,cmp);
		std::sort(b+1,b+m+1,cmp);
		int count=0;int ans1=0;
		int ans2=0;
		int ta=n,tb=m;
		while (ta){
			while (ta&&a[ta].pre==0)--ta;
			if (!ta)break;
			while (tb&&b[tb].h>a[ta].h){
				if (b[tb].pre==0)++count;
				--tb;
			}
			if (count-ans1>0){
				ans1++;
			}
			--ta;
		}
		ta=tb=1;
		count=0;
		while (ta<=n){
			while (ta<=n&&a[ta].pre!=0)++ta;
			if (ta>n)break;
			while (tb<=m&&b[tb].h<a[ta].h){
				if (b[tb].pre==1)++count;
				++tb;
			}
			if (count-ans2>0){
				ans2++;
			}
			++ta;
		}
		printf("%d\n",ans1+ans2);
	}
	return 0;
}