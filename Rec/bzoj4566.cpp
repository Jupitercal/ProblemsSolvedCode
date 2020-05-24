#include<bits/stdc++.h>
#define N 220000
#define INF 0x3f3f3f3f
typedef long long LL;
char s[N];
int mx[N*2],mn[N*2],Len;
int len[N<<1],fa[N<<1],son[N<<1][26];
int size,last,root;
int a[N<<1],c[N<<1],cnt[N<<1];
LL F[N<<1];
void Init(){root=size=last=1;}
void Extend(int c){
    int end=++size,tmp=last;
    len[end]=mn[end]=len[tmp]+1;
    while(tmp&&!son[tmp][c]){
        son[tmp][c]=end;
        tmp=fa[tmp];
    }
    if(!tmp) fa[end]=root;
    else{
        int ne=son[tmp][c];
        if(len[tmp]+1==len[ne]) fa[end]=ne;
        else{
            int np=++size;
            memcpy(son[np],son[ne],sizeof(son[ne]));
            len[np]=mn[np]=len[tmp]+1;
            fa[np]=fa[ne];
            fa[end]=fa[ne]=np;
            while(tmp&&son[tmp][c]==ne){
                son[tmp][c]=np;
                tmp=fa[tmp];
          	  }
       		}
		}
    	last=end;
    cnt[last]=1;
}  
void Radixsort(){
    for(int i=1;i<=size;i++) c[len[i]]++;
    for(int i=1;i<=Len;i++) c[i]+=c[i-1];
    for(int i=size;i>=1;i--) a[c[len[i]]--]=i; 
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%s",s);
	Len=strlen(s);
	Init();
	for (int i=0;i<Len;i++)Extend(s[i]-'a');
	Radixsort();
	for (int i=size;i>=1;i--)cnt[fa[a[i]]]+=cnt[a[i]];
	for (int i=1;i<=size;i++)F[a[i]]=F[fa[a[i]]]+1LL*cnt[a[i]]*(len[a[i]]-len[fa[a[i]]]);
	scanf("%s",s);
	int p=root;
	int l=strlen(s);
	LL ans=0;int anslen=0;
	for (int i=0;i<l;i++){
		if (son[p][s[i]-'a'])p=son[p][s[i]-'a'],++anslen;
		else {
			while (p &&!son[p][s[i]-'a'])p=fa[p];
			if (!p)anslen=0,p=root;
			else {
				anslen=len[p]+1;
				p=son[p][s[i]-'a'];
			}
		}
		ans+=F[fa[p]]+1LL*cnt[p]*(anslen-len[fa[p]]);
	}
	printf("%lld\n",ans);
	return 0;
}