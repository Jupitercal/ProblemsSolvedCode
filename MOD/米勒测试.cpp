bool Miller_test(int n,int a){
	int r = 0, s = n - 1, j;
	if(!(n%a)) return false;
	while(!(s&1)){ s >>= 1; r++; }
	LL k = pow_mod(a, s, n);
	if(k == 1) return true;
	for(j = 0; j < r; j++, k = k * k % n)
    if(k == n - 1) return true;
	return false;
}
if(!miller_rabin(n, 2)) return false;
if(!miller_rabin(n, 3)) return false;
if(!miller_rabin(n, 5)) return false;
if(!miller_rabin(n, 7)) return false;
return true;




