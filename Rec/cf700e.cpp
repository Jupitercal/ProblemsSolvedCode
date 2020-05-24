#include<bits/stdc++.h>
#define N 220000
int Len,n;
int len[N<<1],fa[N<<1],son[N<<1][26];
int size,last,root,pos[N<<1],rt[N*40],lc[N*40],rc[N*40];
int a[N<<1],c[N<<1],T,sum[N*40],ans[N<<1],ANS;
int f[N<<1];
char s[N];
void Init(){root=size=last=1;}
void Extend(int c,int wz){
    int end=++size,tmp=last;
    len[end]=len[tmp]+1;pos[end]=wz;
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
void insert(int &i, int l, int r, int x){
    if(r<l) return ;
    i = ++T;
    if(l == r) {
        sum[i]++ ;
        //num[i]=1LL*x;
        return ;
    }
    int mid = (l + r)/2 ;
    if(x<=mid) insert(lc[i], l, mid, x) ;
    if(x>mid) insert(rc[i], mid + 1, r, x) ;
    //clac(i);
    sum[i]=sum[lc[i]]+sum[rc[i]];
}
int merge(int x, int y) {
    if(!x) return y;
    if(!y) return x;
    //sum[x]+=sum[y];
    int i=++T;
    sum[i]=sum[x]+sum[y];
    lc[i] = merge(lc[x], lc[y]) ;
    rc[i] = merge(rc[x], rc[y]) ;
    //sum[x]=sum[lc[x]]+sum[rc[x]];
    return i;
}
bool query(int x,int l,int r,int ls,int rs){
	if (!x)return 0;
	if (ls<=l&&r<=rs)return sum[x]>0;
	int mid=(l+r)/2;
	if (ls<=mid){
		if (query(lc[x],l,mid,ls,rs))return 1;
	}
	if (mid<rs){
		if (query(rc[x],mid+1,r,ls,rs))return 1;
	}
	return 0;
	//return query(lc[x],l,mid,ls,rs)|query(rc[x],mid+1,r,ls,rs);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	#endif
	scanf("%d",&n);
	scanf("%s",s);
	Len=n;
	Init();
	for (int i=0;i<n;i++)Extend(s[i]-'a',i+1),insert(rt[last],1,n,i+1);
	Radixsort();
	//printf("%d\n",size);
	for (int i=size;i;i--){
		int p=a[i];
		rt[fa[p]]=merge(rt[fa[p]],rt[p]);
	}
	ANS=1;
	for (int i=2;i<=size;i++){
		int p=a[i];
		if (fa[p]==1){
			ans[p]=1;
			f[p]=p;
			continue;
		}
		//printf("%d %d %d\n",fa[p],p,i);
		bool flag=query(rt[f[fa[p]]],1,n,pos[p]-len[p]+len[f[fa[p]]],pos[p]-1);
		if (flag){
			ans[p]=ans[fa[p]]+1;
			f[p]=p;
		}else{
			ans[p]=ans[fa[p]];
			f[p]=f[fa[p]];
		}
		ANS=std::max(ANS,ans[p]);
	}
	printf("%d",ANS);
	return 0;
}