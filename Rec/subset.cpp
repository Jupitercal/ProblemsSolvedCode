/*
  ID: Rec
  LANG: C++
  TASK: subset
*/
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

long long d[1000];

int main(){
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    int n,sumv,i,j;
    while(cin>>n)
    {
        sumv=(n+1)*n/2;
        if(sumv%2==1)
        {
            printf("0\n");
            continue;
        }
        sumv=sumv/2;
        memset(d,0,sizeof(d));
        d[0]=1;
        for(i=1;i<=n;i++)
        {
            for(j=sumv;j>=i;j--)
            {
                d[j]+=d[j-i];
            }
        }
        cout<<d[sumv]/2<<endl;
    }
    return 0;
}
