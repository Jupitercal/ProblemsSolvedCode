#include<bits/stdc++.h>
int F[(1<<20)+5];
int sta,now;
char s[1000005];
std::map<char,int>mp;
int count(int x){
	int num=0;
	while (x){
		if(x%2)++num;
		x/=2;
	}
	return num;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	#endif
	int num=0;
	scanf("%s",s+1);
	int len=strlen(s+1);
	for (int i=1;i<=len;i++){
		int l=i;
		int now=0;
		while (l<=i+19&&l<=len){
			if (!mp[s[l]])mp[s[l]]=++num;
			int x=mp[s[l]];
			x=1<<(x-1);
			if (now&x)break;
			else {
				now^=x;
				F[now]=count(now);
			//	printf("%d\n",F[now]);
				l++;
			}
		}
	}
	int sta=1<<num;
	sta--;
	for (int i=1;i<=sta;i++){
		for (int j=1;j<=num;j++)
			if (i&(1<<(j-1)))F[i]=std::max(F[i],F[i^(1<<(j-1))]);
	}
	int ans=0;
	for (int i=1;i<=sta;i++){
		ans=std::max(ans,F[sta-i]+F[i]);
	}
	printf("%d\n",ans);
	return 0;
}