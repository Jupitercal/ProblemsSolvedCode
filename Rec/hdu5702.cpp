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
struct aa{
	int v,op;
}poi[90];
int T,n;
char s[30][30];
bool cmp(aa a,aa b){return a.v>b.v;}
int main(){
	freopen("hdu5702.in","r",stdin);
	freopen("hdu5702.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%s",s[i]);
			scanf("%d",&poi[i].v);
			poi[i].op=i;
		}	
		std::sort(poi+1,poi+n+1,cmp);
		for (int i=1;i<n;i++)printf("%s ",s[poi[i].op]);
		printf("%s\n",s[poi[n].op]);
	}
	return 0;
}
