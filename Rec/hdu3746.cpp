#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
const int N=4e5+10;
int next[N],n,ans[N],count,t;
char s[N];
void GetNextval(char* p, int next[])
{
	int pLen = strlen(p);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j <= pLen - 1)
	{
		//p[k]表示前缀，p[j]表示后缀  
		if (k == -1 || p[j] == p[k])
		{
			++j;
			++k;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&t);
	while (t--){
		count=0;
		scanf("%s",s);
		memset(next,0,sizeof(next));
		GetNextval(s,next);
		n=strlen(s);
		int t=n-next[n];
		//printf("%d\n",next[n]);
		if (t==n)printf("%d\n",n);
		else if (n%t==0)printf("0\n");
		else printf("%d\n",t-n%t); 
	}
	return 0;
}