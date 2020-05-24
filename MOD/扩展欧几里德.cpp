void exgcd(int a,int b){
	if (!b){
		x=1;y=0;
		return;
	}else exgcd(b,a%b);
	t=x;
	x=y;
	y=t-a/b*y;
}
