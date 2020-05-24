#include<bits/stdc++.h>
#define N 600005
using namespace std;
int n,a[N];
map<int,int>son[N<<1];
int len[N<<1],fa[N<<1];
int size,last,root;
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
            //memcpy(son[np],son[ne],sizeof(son[ne]));
            son[np]=son[ne];
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
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&n); 
	Init();
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),Extend(a[i]);
	for (int i=1;i<=n;i++)Extend(a[i]);
	int p=root;
	for (int i=1;i<=n;i++){
		printf("%d ",son[p].begin()->first);
		p=son[p].begin()->second;
	}
	return 0;
}