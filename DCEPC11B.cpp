#include <iostream>
#include <cstdio>
#define LLD long long int

using namespace std;

LLD modPower(LLD a, LLD n, LLD mod){

    // returns (a^n) % mod.
    // '%' represents modulus operation.

    LLD y = 1;
    while(n){
        if(n & 1)
            y = (y * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return y;
}

LLD inverse(LLD n, LLD p){
	return modPower(n, p-2, p);
}

LLD findNFactorialModuloP(LLD n, LLD p){
	if(p <= n)
		return 0;
	LLD num = p - 1;
	LLD den = 1;
	for(LLD i=p-1;i>n;i--)
		den = (den * i) % p;
	den = inverse(den, p);
	return (num * den) % p;
}

int main(){

	int t;
	LLD n, p;
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld", &n, &p);
		printf("%lld\n", findNFactorialModuloP(n, p));
	}
	return 0;
}