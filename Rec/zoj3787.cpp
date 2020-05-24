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
#define N 30000
int T,n,L;
int ans[N];
struct aa{
	int x,pos;
}a[N];
bool cmp(aa x,aa y){return x.x<y.x;}
bool cz(int x,int y){return x<y;}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		memset(ans,0,sizeof(ans));
		scanf("%d%d",&n,&L);
		for (int i=1;i<=n;i++){
			int x,y,z;
			scanf("%d:%d:%d",&x,&y,&z);
			a[i].x=x*60*60+y*60+z;
			a[i].pos=i;
		}
		std::sort(a+1,a+n+1,cmp);
		int l;
		for (int i=1;i<=n;){
			l=a[i].x+L;
			ans[++ans[0]]=a[i].pos;
			while (a[i].x<l)++i;
		}
		std::sort(ans+1,ans+ans[0]+1,cz);
		printf("%d\n%d",ans[0],ans[1]);
		for (int i=2;i<=ans[0];i++)printf(" %d",ans[i]);
		if (T)printf("\n");
	}
	return 0;
}

