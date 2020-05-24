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
int ans,T;
char s[200000];
bool B[29];
int main(){
	freopen("hdu5842.in","r",stdin);
	freopen("hdu5842.out","w",stdout);
	scanf("%d",&T);
	int x=0;
	while (T--){
		memset(B,0,sizeof(B));
		scanf("%s",s);
		ans=0;
		int len=strlen(s);
		for (int i=0;i<len;i++)
		  if (!B[s[i]-'a'])B[s[i]-'a']=1,++ans;
		printf("Case #%d: %d\n",++x,ans);
	}
	return 0;
}
