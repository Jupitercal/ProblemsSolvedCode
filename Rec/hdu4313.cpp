#include<bits/stdc++.h>
#define N 200005
typedef long long LL;
int T,n,k,fa[N];
LL ans,sum[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
struct aa{
	int x,y,len;
}line[N];
bool cmp(aa a,aa b){
	return a.len>b.len;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&k);
		ans=0;
		for (int i=1;i<=n;i++)sum[i]=0,fa[i]=i;
		for (int i=1;i<n;i++){
			scanf("%d%d%d",&line[i].x,&line[i].y,&line[i].len);
			++line[i].x;++line[i].y;
		}
		std::sort(line+1,line+n,cmp);
		for (int i=1;i<=k;i++){
			int x;
			scanf("%d",&x);
			++x;
			sum[x]=1;
		}
		for (int i=1;i<n;i++){
			int fx=find(line[i].x);
			int fy=find(line[i].y);
			if (sum[fx]&&sum[fy]){
				ans+=line[i].len;
			}
			else{
				fa[fy]=fx;
				sum[fx]+=sum[fy];
			}
			//if (cnt==k-1)break;
		}
		printf("%lld\n",ans);
	}
	return 0;
}