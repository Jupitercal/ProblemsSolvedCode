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
#define N 10000
typedef long long LL;
struct aa{
	int pre,pos,u;
}poi[N];
int T,n,dd,top;
LL num[N];
char s[30];
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	while (T--){
	  scanf("%d",&n);
	  for (int i=1;i<=n;i++){
	  	printf("Operation #%d: ",i);
	  	scanf("%s",s);
	  	if (s[0]=='A'){
	  		int u=0;bool b=0;
	  		scanf("%d",&u);
	  		int x=poi[0].pos;
	  		int px=0;
	  		while (x){
	  			if (poi[x].u==u){
	  				b=1;
	  				break;
	  			}
	  			px=x,x=poi[x].pos;
	  		}
	  		if (b) printf("same priority");
			else {
			  poi[px].pos=++dd;
	  		  poi[dd].pre=px;
	  		  poi[dd].u=u;
	  		  printf("success");
	  		}
	  	}
	  	if (s[0]=='C'&&s[1]=='l'){
	  		int u=0;
	  		scanf("%d",&u);
	  		int x=poi[0].pos;
	  		int px=0;
	  		while (x){
	  			if (poi[x].u==u){
	  				poi[px].pos=poi[x].pos;
	  				poi[poi[x].pos].pre=px;
	  				break;
	  			}
	  			px=x;
	  			x=poi[x].pos;
	  		}
	  	  if (!x)printf("invalid priority");
	  	  else printf("close %d with %I64d",u,num[x]);
	  	  if (top==x)top=0;
	  	}
	  	if (s[0]=='C'&&s[1]=='h'&&s[2]=='a'){
	  		int c;
	  		scanf("%d",&c);
	  		int x;
	  		if (!top)x=poi[0].pos;
	  		else x=top;
	  		if (!x)printf("empty");
	  		else{
	  			num[x]+=c;
	  			printf("success");
	  		}
	  	}
	  	if (s[0]=='R'){
	  		int cul=0;
	  		scanf("%d",&cul);
	  		if (cul<1)printf("out of range");
	  		else{
	  		  int x=poi[0].pos;
	  		  int px=0;
	  		  while (x&&cul>1){
	  			  px=x;
	  			  x=poi[x].pos;
	  			  --cul;
	  		  }
	  	  	  if (!x)printf("out of range");
	  	  	  else {
	  	  	  	poi[px].pos=poi[x].pos;
	  	  	  	poi[poi[x].pos].pre=px;
	  	  	  	poi[poi[0].pos].pre=x;
	  	  	  	poi[x].pos=poi[0].pos;
				poi[0].pos=x;
				poi[x].pre=0;
	  	  	  	printf("success");
	  	  	  }
			}	
	  	}
	  	if (s[0]=='P'){
	  		int x=poi[0].pos;
	  		int ma=0;int max=0;int mpx=0;int px=0;
	  		while (x){
	  			if (poi[x].u>ma){
	  				mpx=px;
	  				ma=poi[x].u;
	  				max=x;
	  			}
	  			px=x;
	  			x=poi[x].pos;
	  		}
	  	    if (max==0)printf("empty");
	  	    else {
	  	    	poi[mpx].pos=poi[max].pos;
	  	  	  	poi[poi[max].pos].pre=mpx;
	  	  	  	poi[poi[0].pos].pre=max;
	  	  	  	poi[max].pos=poi[0].pos;
				poi[0].pos=max;
				poi[max].pre=0;
				printf("success");
	  	    }
	  	}
	  	if (s[0]=='C'&&s[2]=='o'&&s[1]=='h'){
	  		int u;
	  		scanf("%d",&u);
	  		int x=poi[0].pos;
	  		while (x){
	  			if (poi[x].u==u)break;
	  			x=poi[x].pos;
	  		}
	  		if (!x)printf("invalid priority");
	  		else {
	  		  int px=poi[x].pre;
	  		  poi[px].pos=poi[x].pos;
	  	  	  poi[poi[x].pos].pre=px;
	  	  	  poi[poi[0].pos].pre=x;
	  	  	  poi[x].pos=poi[0].pos;
			  poi[0].pos=x;
			  poi[x].pre=0;
	  	  	  printf("success");	
	  		}
	  	}
	  	if (s[0]=='T'){
	  		int u;
	  		scanf("%d",&u);
	  		int x=poi[0].pos;
	  		while (x){
	  			if (poi[x].u==u)break;
	  			x=poi[x].pos;
	  		}
	  		if (!x)printf("invalid priority");
	  		else {
	  			top=x;
	  			printf("success");
	  		}
	  	}
	  	if (s[0]=='U'){
	  		if (top){
	  			top=0;
	  			printf("success");
	  		}else printf("no such person");
	  	}
	  	printf(".\n");
	  }	
	  if (top&&num[top])printf("Bye %d: %I64d\n",poi[top].u,num[top]);
	  int x=poi[0].pos;
	  while (x){
	  	if (x!=top&&num[x])printf("Bye %d: %I64d\n",poi[x].u,num[x]);
	  	x=poi[x].pos;
	  }
	  top=0;dd=0;
	  for (int i=0;i<=7000;i++)poi[i].pos=poi[i].pre=poi[i].u=num[i]=0;
	}
	return 0;
}
