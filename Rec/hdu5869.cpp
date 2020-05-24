#include<bits/stdc++.h>
#define N 100005
typedef long long LL;
int n,q,a[N],g[N][20],b[N*20],LOG[N];
LL ans[N],num[N];
struct aa{
	int l,r,id;
}poi[N];
void plus(int x,LL v){
	while (x<=n){
		num[x]+=v;
		x+=x&(-x);
	}
}
LL sum(int x){
	LL s=0;
	while (x){
		s+=num[x];
		x-=x&(-x);
	}
	return s;
}
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void RMQ_init(){
	for (int i=1;i<=n+1;i++)g[i][0]=a[i-1];
	for (int i=1;i<=20;i++){
		for (int j=1;j<=n+1;j++){
			if (j-(1<<i)<=0)continue;
			g[j][i]=gcd(g[j][i-1],g[j-((1<<(i-1)))][i-1]);
		}
	}
}
int GCD(int x,int y){
	y++;
	if (x>y)std::swap(x,y);
	//x++;
	int v=LOG[y-x];
	return gcd(g[y][v],g[x+(1<<v)][v]);
}
bool cmp(aa a,aa b){
	return a.r<b.r;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	#endif
	a[0]=1;
	LOG[1]=0;
	for (int i=2;i<=100000;i++)LOG[i]=LOG[i/2]+1;
	while (scanf("%d%d",&n,&q)!=EOF){
		memset(num,0,sizeof(num));
		memset(b,0,sizeof(b));
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		for (int i=1;i<=q;i++){
			scanf("%d%d",&poi[i].l,&poi[i].r),poi[i].id=i;
		}
		RMQ_init();
		std::sort(poi+1,poi+1+q,cmp);
		int L=1;
		for (int i=1;i<=n;i++){
			int R=i,now=0;
			while (now!=1&&R>=1){
				int l=1;int r=R;int nowp=0;
				while (l<=r){
					int mid=(l+r)/2;
					if (GCD(mid,i)!=now){
						nowp=mid;
						l=mid+1;
					}else r=mid-1;
				}
				if (nowp==0)break;
				now=GCD(nowp,i);
				//printf("%d: %d %d\n",i,nowp,now);
				if (b[now]&&b[now]<nowp){
					plus(b[now],-1);
					b[now]=nowp;
					plus(b[now],1);
					//printf("1 %d %d\n",now,nowp);
				}else if (!b[now])b[now]=nowp,plus(b[now],1);
				//printf("%lld A\n",sum(5));
				R=nowp-1;
			}
			while (i==poi[L].r&&L<=q){
				ans[poi[L].id]=sum(poi[L].r)-sum(poi[L].l-1);
				++L;
			}
		}
		//printf("%lld\n",sum(5));
		for (int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	}
	return 0;
}