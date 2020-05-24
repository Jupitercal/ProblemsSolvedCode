#include<bits/stdc++.h>
#define N 1000005
int next[N],t,n;
char s[N];
int find(int x){
	int j=-1;
	for (int i=x;i<n-x;i++){
		while (j>=0&&s[j+1]!=s[i])j=next[j];
		if (s[j+1]==s[i])++j;
		if (j==x-1)return x;
	}
	return -1;
}
void GetNextval(char* p, int next[]){
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
		scanf("%s",s);
		GetNextval(s,next);
		n=strlen(s);
		int t=next[n];
		int ans=0;
		while (t){
			int len=find(t);
			if (len==t){
				ans=t;
				break;
			}
			t=next[t];
		}
		printf("%d\n",ans);
	}
	return 0;
}