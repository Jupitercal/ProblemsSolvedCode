/*
ID: Rec
PROG: preface
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
std::string number[4][9]={{"I","II","III","IV","V","VI","VII","VIII","IX"},
{"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
{"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
{"M","MM","MMM","","","","","",""}};
int F[300],d[9],n;
void work(int x){
	int i=0;
	while (x){
		d[++i]=x%10;
		x/=10;
	}
	d[0]=i;
}
int main(){
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		work(i);
		for (int j=1;j<=d[0];j++)
		  if (d[j])
		  for (int x=0;number[j-1][d[j]-1][x];x++)
		    ++F[number[j-1][d[j]-1][x]];
	}
	if (F['I'])printf("I %d\n",F['I']);
	if (F['V'])printf("V %d\n",F['V']);
	if (F['X'])printf("X %d\n",F['X']);
	if (F['L'])printf("L %d\n",F['L']);
	if (F['C'])printf("C %d\n",F['C']);
	if (F['D'])printf("D %d\n",F['D']);
	if (F['M'])printf("M %d\n",F['M']);
	return 0;
}
