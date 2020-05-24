#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define N 15000
int n,nod,fail[N/10],son[N/10][5],c[N/10],ans;
int F[502][N],tj[5],len,goa['Z'],hash[41][41][41][41];
char ss[60];
struct Ac_auto{
	char s[100];
	void insert(){
		memset(son,0,sizeof(son));
		memset(fail,0,sizeof(fail));
		memset(c,0,sizeof(c));
		for (int i=1;i<=n;i++){
			scanf("%s",s);
			int len=strlen(s);
			int p=0;
			for (int j=0;j<len;j++){
				int x=goa[s[j]];
				if (!son[p][x])son[p][x]=++nod;
				p=son[p][x];
			}
			c[p]++;
		}
	}
	std::queue<int>q;
	void build(){
		for (int i=1;i<=4;i++){
			int x=i;
			if (son[0][x])q.push(son[0][x]);
		}
		while (!q.empty()){
			int u=q.front();q.pop();
			for (int i=1;i<=4;i++){
			    int x=i;
			    if (!son[u][x])son[u][x]=son[fail[u]][x];
				else{
					fail[son[u][x]]=son[fail[u]][x];
					c[son[u][x]]+=c[fail[son[u][x]]];
					q.push(son[u][x]);
				}
		    }
		}
	}
}AC;
void Dp(){
	F[0][0]=0;
			for (int a1=0;a1<=tj[1];a1++)
				for (int a2=0;a2<=tj[2];a2++)
					for (int a3=0;a3<=tj[3];a3++)
						for (int a4=0;a4<=tj[4];a4++)
							for (int j=0;j<=nod;j++)
							if (a1+a2+a3+a4){
							  int st1=hash[a1][a2][a3][a4];
			                  if (a1&&F[j][hash[a1-1][a2][a3][a4]]!=-1)
								  F[son[j][1]][st1]=std::max(F[son[j][1]][st1],F[j][hash[a1-1][a2][a3][a4]]+c[son[j][1]]);
							  if (a2&&F[j][hash[a1][a2-1][a3][a4]]!=-1)
								  F[son[j][2]][st1]=std::max(F[son[j][2]][st1],F[j][hash[a1][a2-1][a3][a4]]+c[son[j][2]]);
			                  if (a3&&F[j][hash[a1][a2][a3-1][a4]]!=-1)
				                  F[son[j][3]][st1]=std::max(F[son[j][3]][st1],F[j][hash[a1][a2][a3-1][a4]]+c[son[j][3]]);
							  if (a4&&F[j][hash[a1][a2][a3][a4-1]]!=-1)
				                  F[son[j][4]][st1]=std::max(F[son[j][4]][st1],F[j][hash[a1][a2][a3][a4-1]]+c[son[j][4]]);
							  ans=std::max(ans,F[son[j][1]][st1]);
							  ans=std::max(ans,F[son[j][2]][st1]);
							  ans=std::max(ans,F[son[j][3]][st1]);
							  ans=std::max(ans,F[son[j][4]][st1]);
						    }
}
int main(){
	freopen("hdu3341.in","r",stdin);
	freopen("hdu3341.out","w",stdout);
	int cs=0;
	goa['A']=1;goa['C']=2;goa['T']=3;goa['G']=4;
	while (1){
		scanf("%d",&n);
		if (!n)break;
		ans=0;
		nod=0;
		AC.insert();
		AC.build();
		scanf("%s",ss);
		len=strlen(ss);
		memset(F,-1,sizeof(F));
		tj[1]=tj[2]=tj[3]=tj[4]=0;
		for (int i=1;i<=len;i++)++tj[goa[ss[i-1]]];
		int num=0;
		for (int t1=0;t1<=tj[1];t1++)
			for (int t2=0;t2<=tj[2];t2++)
				for (int t3=0;t3<=tj[3];t3++)
					for (int t4=0;t4<=tj[4];t4++)
						hash[t1][t2][t3][t4]=num++;                                                 
		Dp();
		++cs;
		printf("Case %d: %d\n",cs,ans);
	}
	return 0;
}