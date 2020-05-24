#include<bits/stdc++.h>
#define N 220000
#define INF 0x3f3f3f3f
char s[N];
int mx[N*2],mn[N*2],Len;
int len[N<<1],fa[N<<1],son[N<<1][26];
int size,last,root;
int a[N<<1],c[N<<1];
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
	int cnt=size;
	while (scanf("%s",s)!=EOF){
		int n=strlen(s);
		int p=root;
		int sz=0;
		for (int i=0;i<n;i++){
			int c=s[i]-'a';
			if (son[p][c])++sz,p=son[p][c];
			else {
				while (p && !son[p][c])p=fa[p];
				if (!p)sz=0,p=root;
				else {
					sz=len[p]+1;
					p=son[p][c];
				}
			}
			mx[p]=std::max(mx[p],sz);
		}
		for (int i=cnt;i>=1;i--){
			int p=a[i];
			mn[p]=std::min(mn[p],mx[p]);
			if (fa[p])mx[fa[p]]=std::max(mx[fa[p]],mx[p]);
			mx[p]=0;
		}
	}
	int ans=0;
	for (int i=1;i<=cnt;i++){
		ans=std::max(ans,mn[i]);
		//printf("%d\n",mn[i]);
	}
	printf("%d",ans);
	return 0;
}