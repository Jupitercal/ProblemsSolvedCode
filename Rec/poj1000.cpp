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
double goal,ci;
int main(){
	scanf("%lf",&goal);
	while (fabs(goal)>1e-5){
		int n=0;
		double sum=0;
		while (sum<goal){
			sum+=1.0/(n+2);
			n++;
		}
		printf("%d card(s)\n",n);
		scanf("%lf",&goal);
	}
	return 0;
}
