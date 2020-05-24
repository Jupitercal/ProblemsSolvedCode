#include<bits/stdc++.h>
#define R register int
#define I inline void
#define G if(++ip==ie)if(fread(ip=buf,1,SZ,stdin))
#define lc c[x][0]
#define rc c[x][1]
using namespace std;
const int SZ=1<<19,N=2e5+9;
char buf[SZ],*ie=buf+SZ,*ip=ie-1;
int a[N];
inline int in(){
    G;while(*ip<'-')G;
    R x=*ip&15;G;
    while(*ip>'-'){x*=10;x+=*ip&15;G;}
    return x;
}
int f[N],c[N][2],v[N],s[N],st[N];
bool r[N];
inline bool nroot(R x){//判断节点是否为一个Splay的根（与普通Splay的区别1）
    return c[f[x]][0]==x||c[f[x]][1]==x;
}//原理很简单，如果连的是轻边，他的父亲的儿子里没有它
I pushup(R x){//上传信息
    s[x]=s[lc]+s[rc]+1;
}
I pushr(R x){R t=lc;lc=rc;rc=t;r[x]^=1;}//翻转操作
I pushdown(R x){//判断并释放懒标记
    if(r[x]){
        if(lc)pushr(lc);
        if(rc)pushr(rc);
        r[x]=0;
    }
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
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
    R n=in();
   	for (int i=1;i<=n;i++){
   		a[i]=in();
   		s[i]=1;
   		if (i+a[i]<=n)f[i]=i+a[i];
   	}
   	R m=in();
   	//printf("%d\n",m);
   	for (int i=1;i<=m;i++){
   		R x=in();
   		if (x==1){
   			R j=in();
   			//printf("%d %d\n",x,j);
   			j++;
   			access(j);splay(j);
   			printf("%d\n",s[j]);
   		}else {
   			R j=in(),k=in();
   			j++;
   			access(j);splay(j);
   			f[c[j][0]]=0;
   			c[j][0]=0;
   			if (j+k<=n)f[j]=j+k;
   			pushup(j);
   		}
   	}
    return 0;
}