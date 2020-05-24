/*
ID: Rec
PROG: test
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define MOD 20005
bool player;
int n,m,ans[3]; 
int has[MOD+3],a[MOD];
bool cmp(int x,int y){return x<y;}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	while (scanf("%d%d",&n,&m)!=EOF){
		player=0;ans[0]=ans[1]=0;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		std::sort(a+1,a+1+n,cmp);
		int k=1;
		for (int i=1;i<=m;i++){
			int p,q;
			scanf("%d",&p);
			int tar;
			while (has[a[k]])++k;
			tar=a[k];
			bool cur_down=0;bool tar_down=0;int ma=0;
			for (int j=1;j<=p;j++){
				int x;
				scanf("%d",&x);
				ma=std::max(ma,x);
				if (p==1&&x==tar)tar_down=1;
			}
			scanf("%d",&q);int sum=0;
			for (int j=1;j<=q;j++){
				int x;
				scanf("%d",&x);
				if (x==0)cur_down=1;
				if (x!=0)has[x]=1;
				sum+=x;
			}
			if (p==0){
				player^=1;
				ans[player]+=tar;continue;
			}else 
			if (!cur_down&&!tar_down){
				player^=1;
				ans[player]+=ma;
				ans[player]+=sum;
				continue;
			}else if (cur_down){
				player^=1;
				ans[player]+=ma;
				ans[player]+=sum;
			}else if (!has[a[k]]){
				player^=1;
				ans[player]+=sum;
			}else ans[player]+=sum;
		}
		for (int i=1;i<=n;i++)has[a[i]]=0;
		printf("%d : %d\n",ans[0],ans[1]);
	}
	return 0;
}
