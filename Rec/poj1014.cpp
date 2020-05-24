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
#define N 10
#define MAXN 30000
int a[N],sum,cases;
bool f;
void dfs(int tot){
	if (tot>=sum/2){
		if (tot==sum/2)f=1;	
	}else
	for (int i=6;i>=1;i--)
	 if (a[i]){
	 	if (i+tot<=sum/2){
	 		a[i]--;
			dfs(i+tot);
	 	}
		if (f)return ;
	}
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	cases=0;sum=0;
	for (int i=1;i<=6;i++)scanf("%d",&a[i]),sum+=a[i]*i;
    while (a[1]||a[2]||a[3]||a[4]||a[5]||a[6]){
    	++cases;f=0;
    	printf("Collection #%d:\n",cases);
    	if (sum%2)printf("Can't be divided.\n\n");
    	else{
    		dfs(0);
    		if (f)printf("Can be divided.\n\n");
    		else printf("Can't be divided.\n\n");
    	}
		sum=0;
    	for (int i=1;i<=6;i++)scanf("%d",&a[i]),sum+=a[i]*i;
    }
	return 0;
}

