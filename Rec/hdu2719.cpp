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
	freopen("hdu2719.in","r",stdin);
	freopen("hdu2719.out","w",stdout);
	gets(st);
	while (st[0]!='#'){
		int len=strlen(st);
		for (int i=0;i<len;i++){
			char x=st[i];
			switch (x){
				case ' ':printf("%%20");break;
				case '!':printf("%%21");break;
				case '$':printf("%%24");break;
				case '%':printf("%%25");break;
				case '(':printf("%%28");break;
				case ')':printf("%%29");break;
				case '*':printf("%%2a");break;
				default :printf("%c",x);break;
			}
		}
		printf("\n");
		gets(st);
	}
	return 0;
}
