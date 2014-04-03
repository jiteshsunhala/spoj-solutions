#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#define size 100001
#define mod 1000000007
using namespace std;

int main(){
	
	long long int next, prev, sum, n, l;
	while(true){
		scanf("%lld%lld", &n, &l);
		if(!n && !l)
			break;
		sum = 0;
		prev = (long long int)1;
		for(int i=1;i<=l;i++){
			next = (long long int)(((prev % mod) * (n % mod)) % mod);
			sum = ((sum % mod) + (next % mod)) % mod;
			prev = next;
		}
		printf("%lld\n", sum);
	}
    return 0;
}
