#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#include<utility>
#include<string>
#include<cstring>
#include<set>
#include<cmath>
#include<vector>
#include<fstream>
#include<map>
#include<list>
#include<algorithm>
#define MOD 1000000007

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

LLD r[101];

LLD mod_power(LLD a, LLD n, LLD mod){
	LLD y = 1;
	while(n){
		if(n & 1)
			y = (y * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return y;
}

LLD inverse(LLD num){
	return mod_power(num, MOD - 2, MOD);
}

LLD find_ncr_mod(LLD n, LLD r){
	r = min(r, n-r);
	if(n == 0 || n == 1 || r == 0)
		return 1;
	LLD num = 1;
	for(LLD i = n;i >= n-r+1;i--)
		num = (num * i) % MOD;
	LLD den = 1;
	for(LLD i=2;i<=r;i++)
		den = (den * i) % MOD;
	den = inverse(den);
	LLD res = (num * den) % MOD;
	return res;
}

int main(){
	
	LLD n, w, t, r, res;
	scanf("%lld%lld%lld%lld", &n, &w, &t, &r);
	res = find_ncr_mod(n, w);
	n -= w;
	res = (find_ncr_mod(n, t) * res) % MOD;
	n -= t;
	res = (find_ncr_mod(n, r) * res) % MOD;
	printf("%lld\n", res);
    return 0;
}
