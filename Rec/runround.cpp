/*
ID: Rec
PROG: runround
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
int n,num[30],a[30];
bool B[30],A[30];
void devide(int x){
	a[0]=0;
	while (x){
		a[++a[0]]=x%10;
		x/=10;
	}
	num[0]=a[0];
	for (int i=1;i<=num[0];i++)num[i]=a[num[0]-i+1];
}
bool pd(int x){
	devide(x);
	memset(B,0,sizeof(B));
	memset(A,0,sizeof(A));
	for (int i=1;i<=num[0];i++)
	  if (!A[num[i]])A[num[i]]=1;
	  else return 0;
	int start=1;
	while (1){
		int poi=start;
		for (int i=1;i<=num[start];i++){
			poi=(poi+1)%(num[0]+1);
			if (poi==0)poi++;
		}
		if (!B[poi])B[poi]=1;
		else {
			for (int i=1;i<=num[0];i++)
			  if (!B[i])return 0;
			return 1;
		}
		start=poi;
	}
}
int main(){
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	scanf("%d",&n);
	n++;
	while (!pd(n))
	  ++n;
	printf("%d\n",n);
	return 0;
}
