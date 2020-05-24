#include<bits/stdc++.h>
#define N 505
char s[N][N*4];
int next[N][N*4],n;
int T;
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
bool KmpSearch(char* s, char* p,int k){
	int i = 0;
	int j = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	while (i < sLen && j < pLen)
	{
		//①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++    
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]    
			//next[j]即为j所对应的next值      
			j = next[k][j];
		}
	}
	if (j == pLen)
		return 1;
	else
		return 0;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	for (int cases=1;cases<=T;cases++){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)scanf("%s",s[i]),GetNextval(s[i],next[i]);
		int ans=-1;
		int j=1;
		for (int i=2;i<=n;i++){
			while (i>j){
				if (KmpSearch(s[i],s[j],j)){
					j++;
				}else {
					ans=i;
					break;
				}
			}
		}
		printf("Case #%d: %d\n",cases,ans);
	}
	return 0;
}