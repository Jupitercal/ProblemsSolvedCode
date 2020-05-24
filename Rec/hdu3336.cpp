#include<bits/stdc++.h>
#define N 200005
int next[N],ans,t,n,d[N];
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
		scanf("%d",&n);
		memset(next,0,sizeof(next));
		d[0]=0;
		for (int i=1;i<=n;i++)d[i]=1;
		scanf("%s",s);
		GetNextval(s,next);
		ans=0;
		for (int i=1;i<=n;i++){
			d[i]=d[next[i]]+1;
			ans+=d[i]%10007;
		}
		//for (int i=0;i<=n;i++)printf("%d\n",next[i]);
		printf("%d\n",ans%10007);
	}
	return 0;
}