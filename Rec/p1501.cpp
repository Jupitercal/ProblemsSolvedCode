#include<bits/stdc++.h>
#define R register int
#define I inline void
#define G if(++ip==ie)if(fread(ip=buf,1,SZ,stdin))
#define lc c[x][0]
#define rc c[x][1]
#define MOD 51061
using namespace std;
const int SZ=1<<19,N=1e5+9;
typedef long long LL;
char buf[SZ],*ie=buf+SZ,*ip=ie-1;
char ask[30];
inline int in(){
    G;while(*ip<'-')G;
    R x=*ip&15;G;
    while(*ip>'-'){x*=10;x+=*ip&15;G;}
    return x;
}
int f[N],c[N][2],v[N],st[N];
LL num[N],add[N],mul[N],com[N],s[N];
bool r[N];
inline bool nroot(R x){//判断节点是否为一个Splay的根（与普通Splay的区别1）
    return c[f[x]][0]==x||c[f[x]][1]==x;
}//原理很简单，如果连的是轻边，他的父亲的儿子里没有它
I pushup(R x){//上传信息
    s[x]=(s[lc]+s[rc]+num[x])%MOD;
    com[x]=(com[lc]+com[rc]+1)%MOD;
}
I pushr(R x){
    R t=lc;lc=rc;rc=t;r[x]^=1;
}//翻转操作
I pushdown(R x){//判断并释放懒标记
    if(r[x]){
        if(lc)pushr(lc);
        if(rc)pushr(rc);
        r[x]=0;
    }
    s[lc]=(s[lc]*mul[x]+add[x]*com[lc])%MOD;
    num[lc]=(num[lc]*mul[x]+add[x])%MOD;
    mul[lc]=(mul[lc]*mul[x])%MOD; 
    add[lc]=(add[lc]*mul[x]+add[x])%MOD;
    s[rc]=(s[rc]*mul[x]+add[x]*com[rc])%MOD;
    num[rc]=(num[rc]*mul[x]+add[x])%MOD;
    mul[rc]=(mul[rc]*mul[x])%MOD;
    add[rc]=(add[rc]*mul[x]+add[x])%MOD;
    mul[x]=1;add[x]=0;
}
I rotate(R x){//一次旋转
    R y=f[x],z=f[y],k=c[y][1]==x,w=c[x][!k];
    if(nroot(y))c[z][c[z][1]==y]=x;c[x][!k]=y;c[y][k]=w;//额外注意if(nroot(y))语句，此处不判断会引起致命错误（与普通Splay的区别2）
    if(w)f[w]=y;f[y]=x;f[x]=z;
    pushup(y);
}
I splay(R x){//只传了一个参数，因为所有操作的目标都是该Splay的根（与普通Splay的区别3）
    R y=x,z=0;
    st[++z]=y;//st为栈，暂存当前点到根的整条路径，pushdown时一定要从上往下放标记（与普通Splay的区别4）
    while(nroot(y))st[++z]=y=f[y];
    while(z)pushdown(st[z--]);
    while(nroot(x)){
        y=f[x];z=f[y];
        if(nroot(y))
            rotate((c[y][0]==x)^(c[z][0]==y)?x:y);
        rotate(x);
    }
    pushup(x);
}
/*当然了，其实利用函数堆栈也很方便，代替上面的手工栈，就像这样
I pushall(R x){
    if(nroot(x))pushall(f[x]);
    pushdown(x);
}*/
I access(R x){//访问
    for(R y=0;x;x=f[y=x])
        splay(x),rc=y,pushup(x);
}
I makeroot(R x){//换根
    access(x);splay(x);
    pushr(x);
}
int findroot(R x){//找根（在真实的树中的）
    access(x);splay(x);
    while(lc)pushdown(x),x=lc;
    splay(x);
    return x;
}
I split(R x,R y){//提取路径
    makeroot(x);
    //printf("%d %d\n",x,y);
    access(y);splay(y);
}
I link(R x,R y){//连边
    makeroot(x);
    if(findroot(y)!=x)f[x]=y;
}
I cut(R x,R y){//断边
    makeroot(x);
    if(findroot(y)==x&&f[y]==x&&!c[y][0]){
        f[y]=c[x][1]=0;
        pushup(x);
    }
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)mul[i]=1,num[i]=1,com[i]=1;
    for (int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        //f[x]=y;
        link(x,y);
    }
    while(q--){
    	scanf("%s",ask);
       // printf("%d\n",q);
        //printf("%s\n",ask);
        if (ask[0]=='+'){
        	int u,v;
            LL c;
            scanf("%d%d%lld",&u,&v,&c);
        	split(u,v);
        	add[v]=(add[v]+c)%MOD;
        	num[v]=(num[v]+c)%MOD;
        	s[v]=(s[v]+c*com[v])%MOD;
        }else if (ask[0]=='/'){
        	int u,v;
            scanf("%d%d",&u,&v);
        	split(u,v);
            //pushdown(v);
        	printf("%lld\n",s[v]%MOD);
        }else if (ask[0]=='-'){
        	int u1,v1,u2,v2;
            scanf("%d%d%d%d",&u1,&v1,&u2,&v2);
        	cut(u1,v1);
        	link(u2,v2);
        }else {
            int u,v;
            LL c;
            scanf("%d%d%lld",&u,&v,&c);
        	split(u,v);
        	mul[v]=(mul[v]*c)%MOD;
        	num[v]=(num[v]*c)%MOD;
        	s[v]=(s[v]*c)%MOD;
            //printf("%d\n",num[v]);
        }
    }
    return 0;
}