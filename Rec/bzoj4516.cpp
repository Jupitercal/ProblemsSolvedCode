#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define N 1000005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int Len;
int len[N<<1],fa[N<<1],n;
map<int,int>son[N<<1];
int size,last,root;
int a[N<<1],c[N<<1],cnt[N<<1];
LL ans;
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
    ans+=1LL*(len[last]-len[fa[last]]);
}  
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&n);
    ans=0;
    Init();
	for (int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        Extend(x);
        printf("%lld\n",ans);
    }
	return 0;
}