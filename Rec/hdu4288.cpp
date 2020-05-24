/*
ID: Rec
PROG: test
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define N 100005
typedef long long LL;
int n;
LL a[N],b[N];
char q[N];
struct node{
	LL sum[10];
	int cnt;
}tree[N*10];
void build(int x,int l,int r){
	if (l>r)return;
	memset(tree[x].sum,0,sizeof(tree[x].sum));
	tree[x].cnt=0;
	if (l==r)return ;
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
}
void pushup(int x,int l,int r){
	int lson=x*2;int rson=x*2+1;
	tree[x].cnt=tree[lson].cnt+tree[rson].cnt;
	for (int i=0;i<5;i++)
		tree[x].sum[i]=tree[lson].sum[i]+tree[rson].sum[((i-tree[lson].cnt)%5+5)%5];
}
void insert(int x,int l,int r,int pos,int f){
	if (l>r)return;
	if (l==r){
		tree[x].sum[1]+=f*b[pos-1];
		tree[x].cnt+=f;
		return ;
	}
	int mid=(l+r)/2;
	if (pos<=mid)insert(x*2,l,mid,pos,f);
	else insert(x*2+1,mid+1,r,pos,f);
	pushup(x,l,r);
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d",&n)!=EOF){
		int tot=0;
		for (int i=0;i<n;i++){
			char s[10];
			scanf("%s",s);
			q[i]=s[0];
			if (s[0]!='s')scanf("%I64d",&a[tot++]);
		}
		q[n]='\0';
		for (int i=0;i<tot;i++)b[i]=a[i];
		std::sort(b,b+tot);
		int nn=std::unique(b,b+tot)-b;
		build(1,1,nn);
		for (int i=0,j=0;i<n;i++){
			if (q[i]=='s'){
				printf("%I64d\n",tree[1].sum[3]);
				continue;
			}
			int pos=std::lower_bound(b,b+nn,a[j++])-b+1;
			if (q[i]=='a')insert(1,1,nn,pos,1);
			else insert(1,1,nn,pos,-1);
		}
	}
	return 0;
}

