/*
ID: Rec
PROG: zerosum
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define N 30
int stack[N],n,num[N],ans;
bool pd(){
	int l=1;
	num[1]=1;
	for (int i=1;i<n;i++){
		if (stack[i]==1){
			num[l]=num[l]*10+i+1;
		}else num[++l]=i+1;
	}
	l=1;
	for (int i=1;i<n;i++)
	  if (stack[i]!=1){
	  	if (stack[i]==3){
	  		num[l+1]=num[l]-num[l+1];
	  		l++;
	  	}
	  	else{
	  		num[l+1]=num[l]+num[l+1];
	  		l++;
	  	}
	  }
	if (num[l]==0)return 1;
	else return 0;
}
void dfs(int x){
	if (x==n){
		if (pd()){
			printf("1");
			for (int i=1;i<n;i++){
				if (stack[i]==1)printf(" ");
				if (stack[i]==2)printf("+");
				if (stack[i]==3)printf("-");
				printf("%d",i+1);
			}
			printf("\n");
		}
		return;
	}
	for (int i=1;i<=3;i++){
		stack[x]=i;
		dfs(x+1);
		stack[x]=0; 
	}
}
int main(){
	freopen("zerosum.in","r",stdin);
	freopen("zerosum.out","w",stdout);
	scanf("%d",&n);
	ans=0;
	dfs(1);
	return 0;
}
