#include <iostream>
#include <cstdio>
#define LLD long long int

using namespace std;

LLD findNC2(LLD n){
	LLD m = n - 1;
	if(n & 1)
		m >>= 1;
	else
		n >>= 1;
	return m * n;
}

LLD findTriangleSum(LLD n){
	return findNC2(n + 1);
}

LLD findEvenSum(LLD n){
	return findTriangleSum(n / 2) << 1;
}

LLD findOddSum(LLD n){
	LLD term = (n >> 1) + 1;
	return term * term;
}

LLD findNumerator(LLD k){
	if(k % 2 == 0)
		return findEvenSum(k);
	return findOddSum(k);
}

int main(){
	LLD n, k;
	while(true){
		scanf("%lld%lld", &n, &k);
		if(n == -1 && k == -1)
			break;
		LLD numerator = findNumerator(k - 2);
		if(numerator == 0){
			printf("0\n");
			continue;
		}
		LLD denominator = findNC2(n);
		LLD gcd = __gcd(numerator, denominator);
		printf("%lld/%lld\n", numerator/gcd, denominator/gcd);
	}
	return 0;
}