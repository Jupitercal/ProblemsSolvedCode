#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
int T,son[450001][26],fail[450001],val[450001],ans,n,zl,p,len,u;
char zf[1000001];
std::queue <int>q;
void inse(){
    zl=1;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%s",zf);
        p=0;
        len=strlen(zf);
        for (int j=0;j<len;j++){
            if (son[p][zf[j]-'a']==0){
                ++zl;
                son[p][zf[j]-'a']=zl;
            }
            p=son[p][zf[j]-'a'];
        }
        ++val[p];
    }
}
void build(){
    for (int i=0;i<=25;i++)
      if (son[0][i]){
        fail[son[0][i]]=0;
        q.push(son[0][i]);
      }
    while (!q.empty()){
        u=q.front();q.pop();
        for (int i=0;i<26;i++){
            int &v=son[u][i];
            if (v){
                fail[v]=son[fail[u]][i];
                q.push(v);
            }
            else v=son[fail[u]][i];
        }
    }
}
void query(){
    len=strlen(zf);
    p=0;
    for (int i=0;i<len;i++){
        int v=zf[i]-'a';
        if (son[p][v]==0 && p!=0)p=fail[p];
        p=son[p][v];
        int temp=p;
        while (temp!=0 && val[temp]!=-1){
            ans+=val[temp];
            val[temp]=-1;
            temp=fail[temp];
        }
    }
}
int main(){
    scanf("%d",&T);
    for (int ii=1;ii<=T;++ii){
        memset(son,0,sizeof(son));
        memset(val,0,sizeof(val));
        memset(fail,0,sizeof(fail));
        inse();
        build();
        scanf("%s",zf);
        ans=0;
        query();
        printf("%d\n",ans);
    }
    return 0;
}
