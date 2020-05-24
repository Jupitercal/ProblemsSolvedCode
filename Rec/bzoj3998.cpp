#include<bits/stdc++.h>
#define N 520000
#define INF 0x3f3f3f3f
typedef long long LL;
char s[N];
int mx[N*2],Len;
int len[N<<1],fa[N<<1],son[N<<1][26];
int size,last,root,anslen;
int a[N<<1],c[N<<1],cnt[N<<1],t,k,sum[N<<1];
LL F[N<<1];
char ans[N];
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
    cnt[last]=1;
}  
void Radixsort(){
    for(int i=1;i<=size;i++) c[len[i]]++;
    for(int i=1;i<=Len;i++) c[i]+=c[i-1];
    for(int i=size;i>=1;i--) a[c[len[i]]--]=i; 
}
void dfs(int x,int len){
	if (k<=0)return;
	for (int i=0;i<26;i++){
		if (!son[x][i])continue;
		if (sum[son[x][i]]>=k){
			ans[len]='a'+i;
			ans[len+1]='\0';
			k-=cnt[son[x][i]];
			//printf("%c %d %d\n",'a'+i,len,k);
			dfs(son[x][i],len+1);
			return ;
		}else k-=sum[son[x][i]];
	}
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%s",s);
	Len=strlen(s);
	scanf("%d%d",&t,&k);
	Init();
	for (int i=0;i<Len;i++)Extend(s[i]-'a');
	Radixsort();
	for (int i=size;i>=1;i--){
		if (t==1)cnt[fa[a[i]]]+=cnt[a[i]];
		else cnt[a[i]]=1;
	}
	cnt[1]=0;
	for (int i=size;i>=1;i--){
		int p=a[i];
		sum[p]=cnt[p];
		for (int j=0;j<26;j++)sum[p]+=sum[son[p][j]];
	}
	//printf("%d\n",sum[1]);
	if (sum[1]>=k){
		dfs(root,0);
		//printf("\n");
		printf("%s",ans);
	}
	else printf("-1");
	//if (cnt[1]>=k)printf("%s",ans);
	return 0;
}