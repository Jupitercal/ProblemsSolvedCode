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
int T,x;
int main(){
	scanf("%d",&T);
	while (T--){
	  scanf("%d",&x);
	  x--;
	  int r=(int)sqrt(x);
	  int B=0;
	  for (int i=1;i<=r;i++)
	    if (x%i==0)B+=2;	
	  if (r*r==x)B--;
	  printf("%d\n",B);
	}
	return 0;
} 
