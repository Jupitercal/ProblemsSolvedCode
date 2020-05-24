/*
ID:sephiro5
LANG:C++
TASK:castle
*/
#include<stdio.h>
int colors;
int a[52*52];
bool wall[52][52][52][52];
int start[52*52][2];
int color[52][52];
int xx[5]={0,0,0,1,-1};
int yy[5]={0,1,-1,0,0};
int m,n;
int e[2],nn[2];
bool v[52][52];
bool w;
void init(){
     scanf("%d%d",&n,&m);
     for (int i=1;i<=m;++i)
         for (int j=1;j<=n;++j){
             int te;
             scanf("%d",&te);
             if (te>=8){
                       te-=8;
                       wall[i][j][i+1][j]=true;
                       wall[i+1][j][i][j]=true;
             }
             if (te>=4){
                       te-=4;
                       wall[i][j][i][j+1]=true;
                       wall[i][j+1][i][j]=true;
             }
             if (te>=2){
                       te-=2;
                       wall[i][j][i-1][j]=true;
                       wall[i-1][j][i][j]=true;
             }
             if (te>=1){
                       wall[i][j][i][j-1]=true;
                       wall[i][j-1][i][j]=true;
             }
         }
}
void fillcolor(int x,int y,int col){
     int tx,ty;
     for (int i=1;i<=4;++i){
         tx=x+xx[i];
         ty=y+yy[i];
         if (tx<1||tx>m||ty<1||ty>n) continue;
         if (wall[x][y][tx][ty]) continue;
         if (color[tx][ty]!=0) continue;
         color[tx][ty]=col;
         fillcolor(tx,ty,col);
     }
}
void findv(int x,int y,int col){
     int tx,ty;
     for (int i=1;i<=4;++i){
         tx=x+xx[i];
         ty=y+yy[i];
         if (tx<1||tx>m||ty<1||ty>n) continue;
         if (v[tx][ty]) continue;
         if (color[tx][ty]==col){
                                 ++a[col];
                                 v[tx][ty]=true;
                                 findv(tx,ty,col);
                                 }
     }
}
int main(){
    
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    init();
    for (int i=1;i<=m;++i)
        for (int j=1;j<=n;++j)
            if (color[i][j]==0){
                                ++colors;
                                color[i][j]=colors;
                                start[colors][0]=i;start[colors][1]=j;
                                fillcolor(i,j,colors);
            }
    printf("%d\n",colors);
    for (int i=1;i<=colors;++i){
        v[start[i][0]][start[i][1]]=true;
        findv(start[i][0],start[i][1],i);
    }
    int max=-1;
    for (int i=1;i<=colors;++i)
        if (a[i]>max) max=a[i];
    printf("%d\n",max+1);
    max=-1;
    int ans;
    w=true;
    for (int j=1;j<=n;++j)
        for (int i=m;i>=1;--i){
            int tx,ty;
            tx=i-1; ty=j;
            if (tx<1||tx>m||ty<1||ty>n) continue;
            if (color[tx][ty]==color[i][j]) continue;
            if (a[color[tx][ty]]+a[color[i][j]]>max){
                                                     max=a[color[tx][ty]]+a[color[i][j]];
                                                     nn[0]=i; nn[1]=j;
                                                     w=false;
            }
        }
    for (int i=m;i>=1;--i)
        for (int j=1;j<=n;++j){
            int tx,ty;
            tx=i; ty=j+1;
            if (tx<1||tx>m||ty<1||ty>n) continue;
            if (color[tx][ty]==color[i][j]) continue;
            if ((w)&&(a[color[tx][ty]]+a[color[i][j]]>max)){
                                                            max=a[color[tx][ty]]+a[color[i][j]];
                                                            e[0]=i; e[1]=j;
                                                            w=true;
            }
            if ((!w)&&(j<nn[1]||(j==nn[1]&&i>nn[0]))&&(a[color[tx][ty]]+a[color[i][j]]>=max)){
                                                                                  max=a[color[tx][ty]]+a[color[i][j]];
                                                            e[0]=i; e[1]=j;
                                                            w=true;
            }
                                                     
        }
    printf("%d\n",max+2);
    if (w)
       printf("%d %d %c\n",e[0],e[1],'E');       
    else 
         printf("%d %d %c\n",nn[0],nn[1],'N');
    return 0;
}
            
    

