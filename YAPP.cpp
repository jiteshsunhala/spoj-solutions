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

int main(){
	
	LLD t, n;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld", &n);
		printf("%lld\n", mod_power(2, n-1, MOD));
	}
    return 0;
}
