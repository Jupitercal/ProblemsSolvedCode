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
#define N 100005
typedef long long LL;
struct node{
	int pos,val;
}q[N];
int n,a[N];
LL m,F[N];
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d%lld",&n,&m)!=EOF){
		bool b=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if (a[i]>m)b=1;
		}
		if (b){
			printf("-1\n");
			continue;
		}else{
			int head=1;int tail=1;int wb=1;LL sum=a[1];
			q[1].val=a[1];q[1].pos=1;F[1]=a[1];
			for (int i=2;i<=n;i++){
				sum+=a[i];
				while (sum>m&&wb<i)sum-=a[wb++];
				while (head<=tail&&q[tail].val<=a[i])tail--;
				q[++tail].val=a[i];q[tail].pos=i;
				while (head<=tail&&q[head].pos<wb)++head;
				F[i]=F[wb-1]+q[head].val;
				for (int j=head;j<tail;j++)F[i]=std::min(F[i],F[q[j].pos]+q[j+1].val);
			}
			printf("%lld\n",F[n]);
		}
	}
	return 0;
}
