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
typedef long long LL;
int pos[30];
int T;
LL F[30][2][30];
LL dp(int x,int pre,int len,bool zero,bool f){
	if (x<=0)return (pre&1)!=(len&1);
	if (f&&F[x][pre][len]!=-1)return F[x][pre][len];
	int d=f?9:pos[x];
	LL sum=0;
	for (int i=0;i<=d;i++)
	  if (zero){
	  	if (i==0)sum+=dp(x-1,0,0,1,f||i!=d);
	  	else sum+=dp(x-1,i&1,1,0,f||i!=d);
	  }else {
	  	if (i&1){
	  		if (pre&1)sum+=dp(x-1,pre,len+1,0,f||i!=d);
	  		else {
	  			if (len&1)sum+=dp(x-1,i&1,1,0,f||i!=d);
	  		}
	  	}else{
	  		if (pre&1){if (!(len&1))sum+=dp(x-1,i&1,1,0,f||i!=d);}
	  	    else sum+=dp(x-1,pre,len+1,0,f||i!=d);
	  	}
	  }
	if (f)F[x][pre][len]=sum;
	return sum;
}
LL query(LL x){
	int len=0;
	while (x){
		pos[++len]=x%10;
		x/=10;
	}
	return dp(len,0,0,1,0);
}
int main(){
	freopen("hdu5898.in","r",stdin);
	freopen("hdu5898.out","w",stdout);
	scanf("%d",&T);
	for (int cases=1;cases<=T;cases++){
		memset(F,-1,sizeof(F));
		LL L,R;
		scanf("%I64d%I64d",&L,&R);
		printf("Case #%d: %I64d\n",cases,query(R)-query(L-1));
	}
	return 0;
} 
