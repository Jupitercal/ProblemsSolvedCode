/*
ID: Rec
PROG: test
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
char s[200];
int tree[600][2];
bool tr[600],B;
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	memset(tree,0,sizeof(tree));
	memset(tr,0,sizeof(tr));
	int dd=0;
	int cases=0;
	while (scanf("%s\n",s)!=EOF){
		if (s[0]=='9'){
			++cases;
			if (!B)printf("Set %d is immediately decodable\n",cases);
			else printf("Set %d is not immediately decodable\n",cases);
			B=0;
			memset(tree,0,sizeof(tree));
			memset(tr,0,sizeof(tr));
		}else{
			int len=strlen(s);
			int p=0;
			for (int i=0;i<len;i++){
				if (!tree[p][s[i]-'0'])tree[p][s[i]-'0']=++dd;
				p=tree[p][s[i]-'0'];
				if (tr[p])B=1;
			}
			tr[p]=1;
		}
	}
	return 0;
}
