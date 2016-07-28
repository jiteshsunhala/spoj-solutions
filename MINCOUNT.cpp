#include <iostream>
#include <cstdio>
#define LLD long long int

using namespace std;

int main(){
	int t;
	LLD h;
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &h);
		printf("%lld\n", (h * (h + 1)) / 6);
	}
	return 0;
}