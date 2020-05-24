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
char st[300];
int main(){
	freopen("hdu2734.in","r",stdin);
	freopen("hdu2734.out","w",stdout);
	gets(st);
	while (st[0]!='#'){
		int len=strlen(st);
		long long ans=0;
		for (int i=0;i<len;i++)
			if (st[i]<='Z'&&st[i]>='A')ans+=(st[i]-'A'+1)*(i+1);
		printf("%lld\n",ans);
		gets(st);
	}
	return 0;
}
