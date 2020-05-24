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
int a[20];
int main(){
	for (int i=1;i<=11;i++)scanf("%d",&a[i]);
	for (int i=1;i<=11;i++){
		int max=i;
		for (int j=i;j<=11;j++)
		   if (a[max]<a[j])max=j;
		std::swap(a[max],a[i]);
	}
	for (int i=1;i<=11;i++)printf("%d ",a[i]);
	return 0;
}
