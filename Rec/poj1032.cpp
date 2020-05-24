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
int n,ans[5000];
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		memset(ans,0,sizeof(ans));
		int num=1;
		ans[num++]=2;n-=ans[num-1];
		for (int i=num;n>=ans[i-1]+1;i++,num++)ans[i]=ans[i-1]+1,n-=ans[i];
		num--;
		while (n)
			for (int i=num;i&&n;i--)ans[i]++,--n;
		printf("%d",ans[1]);
		for (int i=2;i<=num;i++)printf(" %d",ans[i]);printf("\n");
	}
	return 0;
}
