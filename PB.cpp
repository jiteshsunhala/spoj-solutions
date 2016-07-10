#include <iostream>
#include <cstdio>
#define MOD 10007
#define LLD int

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
	LLD y = 1;
	while(n){
		if(n & 1)
			y = mulMod(y, a, mod);
		a = mulMod(a, a, mod);
		n >>= 1;
	}
	return y;
}

int main(){
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d\n", &n);
		printf("%d\n", mod_power(n+1, n-1, MOD));
	}
	return 0;
}