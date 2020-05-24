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
char s[200][200];
int n,m;
int sum[5],ord[100],mi[100];
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	memset(ord,0,sizeof(ord));
	scanf("%d%d\n",&n,&m);
	for (int i=1;i<=m;i++){
		memset(sum,0,sizeof(sum));
		mi[i]=i;
		scanf("%s\n",s[i]);
		for (int j=n-1;j>=0;j--){
			char a=s[i][j];
			switch(a){
				case 'A':sum[1]++;break;
				case 'C':sum[2]++;ord[i]+=sum[1];break;
				case 'G':sum[3]++;ord[i]+=sum[1]+sum[2];break;
				case 'T':sum[4]++;ord[i]+=sum[1]+sum[2]+sum[3];break;
			}
			
		}
	}
	for (int i=m;i;i--)
		  for (int j=1;j<i;j++)
		    if (ord[j]>ord[j+1])std::swap(ord[j],ord[j+1]),std::swap(mi[j],mi[j+1]);
	for (int i=1;i<=m;i++)printf("%s\n",s[mi[i]]);
	return 0;
}

