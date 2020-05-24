/*
ID: Rec
PROG: prefix
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#include<string>
#define N 200001
char s[201][12];
std::string tr="";
int cul,len,le[201],ma;
bool F[N];
char c;
int main(){
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	ma=0;
	scanf("%s",s[1]);cul=1;
	while (s[cul][0]!='.')
		scanf("%s",s[++cul]);
	while(std::cin>>c)tr=tr+c;
    //cin>>sa;
	cul--;
	F[0]=1;
	for (int i=1;i<=cul;i++)le[i]=strlen(s[i]);
	len=tr.size();
	for (int i=1;i<=len;i++){
	  for (int j=1;j<=cul;j++)
	    if (i>=le[j]){
	      bool o=1;
	  	  for (int k=0;k<le[j];k++)
	  	    if (tr[i-le[j]+1+k-1]!=s[j][k]){
	  	    	o=0;
	  	    	break;
	  	    }
	  	  if (o==1)F[i]=F[i]|F[i-le[j]];
	  	  if (F[i]){
	  	  	ma=std::max(ma,i);
	  	  	break;
	  	  }
	    }
    }
	printf("%d\n",ma);
	return 0;
} 
