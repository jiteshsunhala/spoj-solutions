#include<iostream>
#include<cstdio>
#define SIZE 1000000
#define MOD 1000000007

using namespace std;

typedef long long int LLD;

LLD nCkValues[SIZE];

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

void initialise(){
	LLD twoInverse = mod_power(2, MOD - 2, MOD);
	nCkValues[0] = 1;
	nCkValues[1] = 4;
	for(LLD i=2;i<SIZE;i++){
		nCkValues[i] = 0;
		LLD num = ((i+2) * (i+1)) % MOD;
		LLD den = twoInverse;
		nCkValues[i] = (num * den) % MOD;
		nCkValues[i] += nCkValues[i-1];
		nCkValues[i] %= MOD;
	}
}

LLD findNumberOfWays(int x, int y){
	x -= 3;
	y -= 3;
	if(x < 0 && y < 0)
		return 0;
	if(x < 0)
		x = 0;
	if(x == 0)
		return nCkValues[y];
	return (nCkValues[y] - nCkValues[x-1] + MOD) % MOD;
}

int main(){
	int t, x, y;
	initialise();
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &x, &y);
		printf("%lld\n", findNumberOfWays(x, y));
	}
	return 0;
}
