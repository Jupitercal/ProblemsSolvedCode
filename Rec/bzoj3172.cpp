#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#define N 15000
int pos[N+5],sum[N+5],n;
int son[N+5][26],nod,fail[N+5];
char s[N+5];
int q[N+5];
struct ac{
    void insert(){
        nod=0;
        for (int i=1;i<=n;i++){
            scanf("%s\n",s);
            int len=strlen(s);
            int p=0;
            for (int ii=0;ii<len;ii++){
                if (!son[p][s[ii]-'a'])son[p][s[ii]-'a']=++nod;
                p=son[p][s[ii]-'a'];
                sum[p]++;
            }
            pos[i]=p;
        }
    }
    void build(){
        int head=0;int tail=0;
        for (int i=0;i<26;i++)if (son[0][i])q[++tail]=son[0][i];
        while (head<tail){
            int u=q[++head];
            for (int i=0;i<26;i++){
                 int &v=son[u][i];
			     if (v){
				    fail[v]=son[fail[u]][i];
				    q[++tail]=v;
			    }
			    else v=son[fail[u]][i];
            }
        }
        for (int i=tail;i>=1;i--)sum[fail[q[i]]]+=sum[q[i]];
    }
}Ac;
int main(){
	freopen("bzoj3172.in","r",stdin);
	freopen("bzoj3172.out","w",stdout);
    scanf("%d\n",&n);
    Ac.insert();
    Ac.build();
    for (int i=1;i<=n;i++)printf("%d\n",sum[pos[i]]);
    return 0;
}
