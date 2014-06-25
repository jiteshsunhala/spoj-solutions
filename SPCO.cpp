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

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

LLU nbitprime[65], ncr[65][65];
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};

void init(){
	for(int i=0;i<65;i++)
		for(int j=0;j<65;j++)
			ncr[i][j] = 0;
}

void prepare_ncr(){
	init();
	for(int i=0;i<65;i++){
		ncr[i][0] = ncr[i][i] = 1;
		for(int j=1;j<i;j++)
			ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
	}
}

int find_bits(LLU num){
	int res = 0;
	while(num){
		res++;
		num >>= 1;
	}
	return res;
}

int find_set_bits(LLU num){
	int res = 0;
	while(num){
		if(num & 1)
			res++;
		num >>= 1;
	}
	return res;
}

LLU find_prime_for(int bits, LLU num){
	
	int posn = 0, set = find_set_bits(num), j = set-1;
	LLU res = 0, tmp = num;
	while(j){
		if(tmp & 1){
			j--;
			set--;
			for(int k = 0;k < 18 && primes[k] <= bits;k++){
				int n = posn;
				int r = primes[k] - set;
				if(n >= 0 && r >= 0 && r <= n)
					res += ncr[n][r];
				else if(r > n)
					break;
			}
		}
		tmp >>= 1;
		posn++;
	}
	set = find_set_bits(num);
	for(int i=0;i<18;i++)
		if(set == primes[i]){
			res++;
			break;
		}
	return res;
}

bool isprime(int num){
	for(int i=0;i<18;i++)
		if(num == primes[i])
			return true;
	return false;
}

LLU find_primes(LLU a, LLU b){
	LLD res = 0;
	int bita = find_bits(a);
	int bitb = find_bits(b);
	for(int i=bita+1;i<bitb;i++)
		res += nbitprime[i];
	LLU resa = find_prime_for(bita, a);
	LLU resb = find_prime_for(bitb, b);
	if(bita != bitb)
		res += (nbitprime[bita] - resa + (isprime(find_set_bits(a)) ? 1 : 0) + resb);
	else
		res += (resb - resa + (isprime(find_set_bits(a)) ? 1 : 0));
	return res;
}

void prepare_nbit_primes(){
	for(int i=1;i<65;i++){
		nbitprime[i] = 0;
		int n = i-1;
		for(int j=0;j < 18 && i >= primes[j];j++){
			int r = primes[j] - 1;
			nbitprime[i] += ncr[n][r];
		}
	}
}

int main(){
	
	LLU a, b;
	int t;
	prepare_ncr();
	prepare_nbit_primes();
	scanf("%d", &t);
	while(t--){
		scanf("%llu%llu", &a, &b);
		printf("%llu\n", find_primes(a, b));
	}
	return 0;
}
