#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
int n,m;
int main(){
	freopen("vijos1919.in","r",stdin);
	freopen("vijos1919.out","w",stdout);
	while (scanf("%d%d",&m,&n)!=EOF){
		double sum=m;
		for (int i=1;i<m;i++)
		  sum-=pow(double(i)/m,n);
		printf("%.4f\n",sum);
	}
	return 0;
} 
