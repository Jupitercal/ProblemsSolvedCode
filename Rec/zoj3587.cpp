#include<bits/stdc++.h>
#define N 200005
typedef long long LL;
int T;
int next[N];
LL cnt1[N],cnt2[N];
int len1,len2;
char s[N],st[N],a[N];
void GetNextval(char* p, int next[],LL cnt[]){
	int pLen=strlen(p);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j <= pLen - 1)
	{
		//p[k]表示前缀，p[j]表示后缀  
		if (k == -1 || p[j] == p[k])
		{	
			if (k!=-1)
				if (j>=len2&&p[j]==p[k])cnt[1+k]++;
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
	scanf("%d",&T);
	while (T--){
		scanf("%s",s);
		scanf("%s",a);
		len1=strlen(s);len2=strlen(a);
		for (int i=0;i<len2;i++)st[i]=a[i];
		st[len2]='#';
		for (int i=len2+1;i<=len2+len1;i++)st[i]=s[i-len2-1];
		st[len2+len1+1]='\0';
		for (int i=1;i<=len2;i++)cnt1[i]=cnt2[i]=0;
		GetNextval(st,next,cnt1);
		for (int i=len2;i>=1;i--){
			if (next[i])cnt1[next[i]]+=cnt1[i];
		}
		for (int i=len2-1;i>=0;i--)st[i]=a[len2-i-1];
		st[len2]='#';
		for (int i=len2+1;i<=len2+len1;i++)st[i]=s[len1+len2-i];
		st[len2+len1+1]='\0';
		GetNextval(st,next,cnt2);
		for (int i=len2;i>=1;i--){
			if (next[i])cnt2[next[i]]+=cnt2[i];
		}
		LL ans=0;
		for (int i=1;i<len2;i++)ans+=1LL*cnt1[i]*cnt2[len2-i];
		printf("%lld",ans);
		if (T)printf("\n");
	}
	return 0;
}