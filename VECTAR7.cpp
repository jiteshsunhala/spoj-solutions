#include <iostream>
#include <cstdio>
#define LLD long long int
#define MOD 1000000007

using namespace std;

LLD mulMod(LLD a, LLD b, LLD c){
	LLD res = 0;
	a %= c;
	while(b){
		if(b & 1)
			res = (res + a) % c;
		a = (a << 1) % c;
		b = b >> 1;
	}
	return (res % c);
}

LLD mod_power(LLD a, LLD n, LLD mod){

    // returns (a^n) % mod.
    // '%' represents modulus operation.

    LLD y = 1;
    while(n){
        if(n & 1)
            y = mulMod(y, a, mod);
        a = mulMod(a, a, mod);
        n >>= 1;
    }
    return y;
}

LLD inverse(LLD num){

    // returns the inverse of num w.r.t. (10^9 + 7).
    // uses the property a^(-1) mod p = a^(p-2) mod p.
    return mod_power(num, MOD - 2, MOD);
}

LLD findModNcR(LLD n, LLD r){

    // returns the value of nCr mod (10^9 + 7).

    r = min(r, n-r);
    if(n == 0 || n == 1 || r == 0)
        return 1;

    // find numerator mod (10^9 + 7).
    LLD num = 1;
    for(LLD i = n;i >= n-r+1;i--)
        num = (num * i) % MOD;

    // find denominator mod (10^9 + 7).
    LLD den = 1;
    for(LLD i=2;i<=r;i++)
        den = (den * i) % MOD;

    // find the inverse of obtained denominator w.r.t. (10^9 + 7).
    den = inverse(den);

    // multiply numerator and inverse of denominator and return the result.
    LLD res = (num * den) % MOD;
    return res;
}

LLD findNumberOfWays(LLD a, LLD b){
	if(b < 25)
		return 0;
	if(b == 25 && a >= 24)
		return 0;
	if(b > 25 && b - 2 != a)
		return 0;
	if(b == 25)
		return findModNcR(a + 24, a);
	return mulMod(findModNcR(48, 24), mod_power(2, a - 24, MOD), MOD);
}

int main(){
	int t;
	LLD a, b;
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", findNumberOfWays(min(a, b), max(a, b)));
	}
	return 0;
}