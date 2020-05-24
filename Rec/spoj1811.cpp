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
int main(){
  freopen("test.in","r",stdin);
  freopen("test.out","w",stdout);
  scanf("%s",s);
  Len=strlen(s);
  Init();
  for (int i=0;i<Len;i++)Extend(s[i]-'a');
  //Radixsort();
  scanf("%s",s);
  Len=strlen(s);
  int p=root;int lens=0;
  int ans=0;
  for (int i=0;i<Len;i++){
      int c=s[i]-'a';
      if (son[p][c])lens++,p=son[p][c];
      else {
          while (p && !son[p][c])p=fa[p];
          if (!p) lens=0,p=root;
          else {
              lens=len[p]+1;
              p=son[p][c];
          }
      }
      ans=std::max(ans,lens);
  }
  printf("%d",ans);
  return 0;
}