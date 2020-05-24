/*
ID: Rec
PROG: pprime
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define N 20000 
int a,b,lx,rx,la,lb,ans[N];
int mm[20];
bool cmp(int x,int y){return x<y;}
bool clac(int x){
	int m=sqrt(x);
	if (x==1||x==0)return 0;
	for (int i=2;i<=m;i++)
	  if (x%i==0)return 0;
	return 1;
}
void dfs(int tot,int w){
	if (w==0){
		int h=0;
		if (tot%2==0){
			for (int i=tot/2;i;i--)h=h*10+mm[i];
			for (int i=1;i<=tot/2;i++)h=h*10+mm[i];
			if (clac(h)&&h>=a&&h<=b)ans[++ans[0]]=h;
		}else{
			for (int i=tot/2;i;i--)h=h*10+mm[i];
			int lh=h;
			for (int j=0;j<=9;j++){
				lh=h;lh=lh*10+j;
				for (int i=1;i<=tot/2;i++)lh=lh*10+mm[i];
			    if (clac(lh)&&lh>=a&&lh<=b)ans[++ans[0]]=lh;
			}
		}
		return ;
	}
	int wz=0;
	if (w==tot/2)wz=1;
	for (int i=wz;i<=9;i++){
		mm[w]=i;
		dfs(tot,w-1);
		mm[w]=0;
	}
}
int main(){
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	scanf("%d%d",&a,&b);
	la=a;lb=b;
	while (la)++lx,la/=10;
	while (lb)++rx,lb/=10;
	for (int i=lx;i<=rx;i++)dfs(i,i/2);
	std::sort(ans+1,ans+ans[0]+1,cmp);
	for (int i=1;i<=ans[0];i++)printf("%d\n",ans[i]);
	return 0;
}
