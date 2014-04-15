#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#include<cmath>
#define size 31622780
typedef unsigned long long int LLU;
using namespace std;

int main(){
	
	LLU n, cnt, i;
//	find_prime();
	while(true){
		scanf("%llu", &n);
		if(!n)
			break;
		cnt = 0;
		while(n % 2 == 0){
			cnt++;
			n /= 2;
		}
		if(cnt > 0)
			printf("2^%llu ", cnt);
		i = 3;
		
		while(i*i <= n && n != 1){
			cnt = 0;
			while(n % i == 0){
				n /= i;
				cnt++;
			}
			if(cnt > 0)
				printf("%llu^%llu ", i, cnt);
			i += 2;
		}
		
		if(n > 1)
			printf("%llu^1", n);
		printf("\n");
	}
    return 0;
}
