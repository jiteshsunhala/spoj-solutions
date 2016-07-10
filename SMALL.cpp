#include <iostream>
#include <cstdio>
#include <cmath>
#define LLD long long int
#define SIZE 10001
#define MOD 1000000007

using namespace std;

LLD result[SIZE], numPower[SIZE], resultNum;

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

LLD modPower(LLD a, LLD n, LLD mod){
	LLD y = 1;
	while(n){
		if(n & 1)
			y = mulMod(y, a, mod);
		a = mulMod(a, a, mod);
		n >>= 1;
	}
	return y;
}

void updateNumPower(int n){
	int cnt = 0;
	while(n % 2 == 0){
		cnt++;
		n >>= 1;
	}
	
	if(cnt > numPower[2]){
		resultNum = mulMod(resultNum, modPower(2, cnt - numPower[2], MOD), MOD);
		numPower[2] = cnt;
	}

	for(int i=3;i<=sqrt(n);i+=2){
		int cnt = 0;
		while(n % i == 0){
			cnt++;
			n /= i;
		}
		if(cnt > numPower[i]){
			resultNum = mulMod(resultNum, modPower(i, cnt - numPower[i], MOD), MOD);
			numPower[i] = cnt;
		}
	}

	if(n != 1 && numPower[n] < 1){
		resultNum = mulMod(resultNum, n, MOD);
		numPower[n]++;
	}
}

void preCalculate(){
	fill(numPower, numPower + SIZE, 0);
	result[1] = 1;
	resultNum = 1;
	for(int i=2;i<SIZE;i++){
		updateNumPower(i);
		result[i] = resultNum;
	}
}

int main(){

	preCalculate();
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%lld\n", result[n]);
	}
	return 0;
}