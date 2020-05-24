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
char s[60];
int main(){
	freopen("hdu2700.in","r",stdin);
	freopen("hdu2700.out","w",stdout);
	scanf("%s",s);
	while (s[0]!='#'){
		int len=strlen(s);
		int ol=0;
		for (int i=0;i<len;i++)
		  if (s[i]=='1')++ol;
		if (s[len-1]=='e'){
			if (ol%2==0)s[len-1]='0';
			else s[len-1]='1';
		}else{
			if (ol%2==0)s[len-1]='1';
			else s[len-1]='0';
		}
		for (int i=0;i<len;i++)printf("%c",s[i]);
		printf("\n");
		scanf("%s",s);
	}
	return 0;
}
