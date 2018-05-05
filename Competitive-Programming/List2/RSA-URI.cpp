#include <bits/stdc++.h>  

using namespace std;  

long long int prime1, prime2;
long long int xM1, yM1, xM2, yM2, rM1, rM2, x, y, r, q;

void getInv(long long int e, long long int mod){
	xM1 = 1, yM1 = 0;
	xM2 = 0, yM2 = 1;
	x = 0, y = 0;
	rM2 = mod, rM1 = e, r = 1, q = 1;

	while(r != 0){
		q = rM2/rM1;
		r = rM2-rM1*q;
		x = xM2-q*xM1, y = yM2-q*yM1;

		xM2 = xM1, yM2 = yM1;
		xM1 = x, yM1 = y;
		rM2 = rM1, rM1 = r;
	}
	x = xM2;
}

void fermat(long long int n){
	long long int a, lli_b;
	a = sqrt(n) + 1;


	if(a*a==n){
		prime1 = a, prime2 = a;
		return;
	}

	lli_b = sqrt(a*a-n);
	while(lli_b*lli_b != a*a-n){
		a++;
		lli_b = sqrt(a*a-n);
	}

	prime1 = a+lli_b, prime2 = a-lli_b;
}

long long int expMod(long long int c, long long int n){
	long long decripted = 1;
	while(x > 0){
		decripted *= (x%2)? c : 1;
		decripted %= n;
		c = (c*c) % n;
		x /= 2;
	}
	return decripted;
}


int main(){
	long long int n, e, c, d;
	cin >> n >> e >> c;
	x = y = 0;
	fermat(n);
	getInv(e, (prime1-1)*(prime2-1));

	if(x < 0)
		x += (prime1-1)*(prime2-1);

	printf("%lld\n", expMod(c, n));

	return 0;
}