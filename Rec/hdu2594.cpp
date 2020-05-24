#include<bits/stdc++.h>
#define N 100005
char s[N];
int next[N];
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
		int len=strlen(s);
		memset(next,0,sizeof(next));
		s[len]='#';
		scanf("%s",s+len+1);
		GetNextval(s,next);
		int n=strlen(s);
		int t=next[n];
		int ans=0;
		while (t){
			if (t<=len){
				ans=t;
				break;
			}
			t=next[t];
		}
		if (ans){
			for (int i=0;i<ans;i++)printf("%c",s[i]);
			printf(" %d\n",ans);
		}else printf("0\n");
	}
	return 0;
}