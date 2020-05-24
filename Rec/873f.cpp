#include<bits/stdc++.h>
#define N 220000
#define INF 0x3f3f3f3f
typedef long long LL;
char s[N],t[N];
int Len;
int len[N<<1],fa[N<<1],son[N<<1][26],r[N<<1];
int size,last,root;
int a[N<<1],c[N<<1];
void Init(){root=size=last=1;}
void Extend(int c){
    int end=++size,tmp=last;
    len[end]=len[tmp]+1;
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
            len[np]=len[tmp]+1;
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
	scanf("%d",&Len);
	scanf("%s",s);
	scanf("%s",t);
	Init();
	for (int i=0;i<Len;i++)Extend(s[i]-'a'),r[last]='1'-t[i];
	Radixsort();
	int cnt=size;
	for (int i=cnt;i;i--){
		int p=a[i];
		r[fa[p]]+=r[p];
	}
	LL ans=0;
	for (int i=1;i<=cnt;i++)ans=std::max(ans,1LL*len[i]*r[i]);
	printf("%lld",ans);
	return 0;
}