#include<bits/stdc++.h>
#define N 100005
#define INF 0x3f3f3f3f
char s[N];
int mx[N*2],mn[N*2],Len,right[N<<1],T;
int len[N<<1],fa[N<<1],son[N<<1][26],pos[N<<1];
int size,last,root,t;
int a[N<<1],c[N<<1];
void Init(){
	memset(pos,INF,sizeof(pos));
	memset(fa,0,sizeof(fa));
	memset(len,0,sizeof(len));
	memset(son,0,sizeof(son));
	root=size=last=1;
}
void Extend(int c,int v){
    int end=++size,tmp=last;
    len[end]=mn[end]=len[tmp]+1;
    right[end]=len[tmp]+1;
    pos[end]=std::min(pos[end],v);
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
            pos[np]=std::min(pos[np],pos[ne]);
            fa[end]=fa[ne]=np;
            right[np]=right[ne];
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
	scanf("%d",&T);	
	int cases=0;
	while (T--){
		scanf("%s",s);
		Len=strlen(s);
		Init();
		int start=0;
		++cases;
		printf("Case #%d:\n",cases);
		while (start!=Len){
			int p=root;
			int len=0;
			while (son[p][s[start]-'a']&&start<Len){
				p=son[p][s[start]-'a'];
				Extend(s[start]-'a',start);
				++len;
				++start;
			}
			if (len){
				printf("%d %d\n",len,pos[p]-len+1);
				//++start;
			}else {
				printf("-1 %d\n",(int)s[start]);
				Extend(s[start]-'a',start);
				++start;
			}
		}
	}
	return 0;
}