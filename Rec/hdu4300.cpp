#include<bits/stdc++.h>
#define N 100005
char s[N*3],tran[30],s1[N*3],tra[30],ans[N*3];
int next[N*3],T;
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
		}
		else
		{
			k = next[k];
		}
	}
} 
int main(){
	//freopen("test.in","r",stdin);
	//("test.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		memset(next,0,sizeof(next));
		scanf("%s",tra);
		for (int i=0;i<26;i++){
			tran[tra[i]-'a']=i+'a';
		}
		scanf("%s",s);
		int len=strlen(s);
		for (int i=0;i<len;i++)s1[i]=tran[s[i]-'a'];
		//s[len]='#';
		for (int i=0;i<len;i++)ans[i]=s1[i];
		ans[len]='#';
		int mid=len/2;
		if (len%2)++mid;
		for (int i=0;i<mid;i++)ans[i+len+1]=s[i];
		ans[len+mid+1]='%';
		for (int i=mid;i<len;i++)ans[i+2+len]=s[i];
		ans[len*2+2]='\0';
		GetNextval(ans,next);
		int tot=next[len*2+2];
		//printf("%s %d\n",ans,tot);
		for (int i=0;i<len-tot;i++)printf("%c",s[i]);
		for (int i=0;i<len-tot;i++)printf("%c",s1[i]);
		printf("\n");
	}
	return 0;
}