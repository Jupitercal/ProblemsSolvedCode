#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
const int N=4e5+10;
int next[N],n,ans[N],count;
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
	while (scanf("%s",s)!=EOF){
		count=0;
		memset(next,0,sizeof(next));
		GetNextval(s,next);
		n=strlen(s);
		int t=next[n];
		while (t){
			if (s[t-1]==s[n-1])ans[++count]=t;
			t=next[t];
		}
		for (int i=count;i>=1;i--)printf("%d ",ans[i]);
		printf("%d\n",n);
	}
	return 0;
}