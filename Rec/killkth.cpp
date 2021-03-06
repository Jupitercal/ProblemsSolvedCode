#include<bits/stdc++.h>
#define N 220000
#define INF 0x3f3f3f3f
typedef long long LL;
char s[N];
int Len,n;
int len[N<<1],fa[N<<1],son[N<<1][26];
int size,last,root,tree[N<<1][26],pos[N<<1];
int a[N<<1],c[N<<1],dfn[N<<1],sz;
LL sum[N<<1],siz[N<<1];
void Init(){root=size=last=1;}
void Extend(int c,int wz){
    int end=++size,tmp=last;
    len[end]=len[tmp]+1;siz[end]=1;pos[end]=wz;
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
            pos[np]=pos[ne];
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
void dfs(int x){
	dfn[++sz]=x;
	sum[sz]=1LL*siz[x]*(len[x]+len[fa[x]]+1)*(len[x]-len[fa[x]])/2;
	for (int i=0;i<26;i++)
		if (tree[x][i])dfs(tree[x][i]);
}
int query(LL k){
	int l=1;int r=sz;
	while (l<r){
		int mid=(l+r)/2;
		if (sum[mid]>=k)r=mid;
		else l=mid+1;
	}
	k-=sum[l-1];
	l=dfn[l];
//	printf("%d %lld %d %d\n",l,k,len[fa[l]],len[l]);
	int L=len[fa[l]]+1;int R=len[l];
	while (L<R){
		int mid=(L+R)/2;
		if (1LL*siz[l]*(mid+len[fa[l]]+1)*(mid-len[fa[l]])/2>=k)R=mid;
		else L=mid+1;
	}
	k-=1LL*siz[l]*(L+len[fa[l]])*(L-len[fa[l]]-1)/2;
	k=(k-1)%L+1;
	return s[pos[l]+k-1];
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	#endif
	scanf("%s",s+1);
	Len=strlen(s+1);
	Init();
	for (int i=Len;i>=1;i--)Extend(s[i]-'a',i);
	Radixsort();
	for (int i=size;i;i--){
		int p=a[i];
		siz[fa[p]]+=siz[p];
	}
	for (int i=1;i<=size;i++){
		tree[fa[i]][s[pos[i]+len[fa[i]]]-'a']=i;
	}
	dfs(1);
	for (int i=1;i<=sz;i++)sum[i]+=sum[i-1];
	scanf("%d",&n);
	LL count=0;
	for (int i=1;i<=n;i++){
		LL p,m;
		scanf("%lld%lld",&p,&m);
		int ans=query((p*count)%m+1);
		printf("%c\n",ans);
		count+=ans;
		//printf("%c\n",ans+'a');
	}
	return 0;
}