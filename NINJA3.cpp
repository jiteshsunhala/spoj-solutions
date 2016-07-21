#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#define LLU unsigned long long int

using namespace std;

int main(){
	LLU s, a, b;
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%llu%llu%llu", &s, &a, &b);
		LLU gcd = __gcd(a, b);
		for(int i=0;i<gcd;i++)
			printf("%llu", s);
		printf("\n");
	}
	return 0;
}