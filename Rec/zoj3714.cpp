#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define N 3000
int a[N],T,n,w,ans;
int main(){
	scanf("%d",&T);
	while (T--){
		memset(a,0,sizeof(a));
		ans=0;
		scanf("%d%d",&n,&w);
		for (int i=1;i<=n;i++)scanf("%d",&a[i]),a[i+n]=a[i];
		for (int i=1;i<=n;i++){
			int m=0;
			for (int j=1;j<=w;j++)m+=a[j+i-1];
			if (m>ans)ans=m;
		}
		printf("%d",ans);
		if (T)printf("\n");
	}
	return 0;
}
