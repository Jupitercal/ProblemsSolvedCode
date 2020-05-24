/*
ID: Rec
PROG: ttwo
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
struct aa{
	int x[2],y[2],direc[2];
	int time;
}h;
std::queue<aa>q;
bool B[20][20];
char s[20];
int X[4],Y[4],ans,X1,Y1,X2,Y2;
int main(){
	freopen("ttwo.in","r",stdin);
	freopen("ttwo.out","w",stdout);
	for (int i=1;i<=10;i++){
		scanf("%s",s);
		for (int j=1;j<=10;j++){
			if (s[j-1]=='F'){
				h.x[0]=i;
				h.y[0]=j;
				B[i][j]=1;
			}
			if (s[j-1]=='C'){
				h.x[1]=i;
				h.y[1]=j;
				B[i][j]=1;
			}
			if (s[j-1]=='.')B[i][j]=1;
			if (s[j-1]=='*')B[i][j]=0;
		}
	}
	X[0]=-1;Y[0]=0;X[1]=0;Y[1]=1;
	X[2]=1;Y[2]=0;X[3]=0;Y[3]=-1;
	int time=0;
	while (time<=1600001){
		if (h.x[0]==h.x[1]&&h.y[0]==h.y[1]){
			printf("%d\n",time);
			break;
		}
		X1=h.x[0]+X[h.direc[0]];Y1=h.y[0]+Y[h.direc[0]];
		X2=h.x[1]+X[h.direc[1]];Y2=h.y[1]+Y[h.direc[1]];
		if (B[X1][Y1]){
			h.x[0]=X1;
			h.y[0]=Y1;
		}else h.direc[0]=(h.direc[0]+1)%4;
		if (B[X2][Y2]){
			h.x[1]=X2;
			h.y[1]=Y2;
		}else h.direc[1]=(h.direc[1]+1)%4;
		time++;
	}
	if (time>1600001)printf("0\n");
	return 0;
}
