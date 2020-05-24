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
#include<set>
std::set<std::string>v;
int n,len;
char s[300],s1[300];
int getMINIREPRESENT(){
	int i=0,j=1,k=0;
	while (i<len&&j<len&&k<len){
		int tmp=s[(i+k)%len]-s[(j+k)%len];
		if (tmp==0)k++;
		else{
			if (tmp>0)i+=k+1;
			else j+=k+1;
			if (i==j)++j;
			k=0;
		}
	}
	return std::min(i,j);
}
void getMIN(char *st){
	st[len/2]='\0';
	v.insert(st);
}
int main(){
	freopen("hdu2609.in","r",stdin);
	freopen("hdu2609.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		v.clear();
		for (int i=1;i<=n;i++){
			scanf("%s",s1);
			strcpy(s,s1);
			strcat(s,s1);
			len=strlen(s);
			int k=getMINIREPRESENT();
			getMIN(s+k);
		}
		printf("%d\n",v.size());
	}
	return 0;
}
