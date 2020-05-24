#include<bits/stdc++.h>
#define N 1000006
#define MOD 1000000007
int T,ans[N],tot,next[N];
char s[N],a[N];
int KmpSearch(char* s, char* p){
	int i = 0;
	int j = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	while (i < sLen && j < pLen){
		if (j == -1 || s[i] == p[j]){
			i++;
			j++;
			tot=(tot+ans[j])%MOD;
			if (j==pLen)j=next[j];
		}else{
			j = next[j];
		}
	}
	if (j == pLen)
		return i - j;
	else
		return -1;
}
void GetNextval(char* p, int next[]){
	int pLen = strlen(p);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j <= pLen - 1){
		//p[k]表示前缀，p[j]表示后缀  
		if (k == -1 || p[j] == p[k])
		{
			++j;
			++k;
			next[j] = k;
			ans[j]=(ans[j]+ans[k])%MOD;
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
		memset(next,0,sizeof(next));
		tot=0;
		int len1=strlen(a);
		for (int i=0;i<len1/2;i++)std::swap(a[i],a[len1-i-1]);
		int len2=strlen(s);
		for (int i=0;i<len2/2;i++)std::swap(s[i],s[len2-i-1]);
		for (int i=1;i<=len1;i++)ans[i]=i;
		//printf("%s\n%s\n",s,a);
		GetNextval(a,next);
		//for (int i=1;i<=len1;i++)printf("%d ",ans[i]);
		//printf("\n");
		KmpSearch(s,a);
		printf("%d\n",tot);
	}
	return 0;
}