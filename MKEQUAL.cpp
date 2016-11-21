#include <iostream>
#include <cstdio>
#define LLD long long int

using namespace std;

int main(){

	int t, n;
	LLD val, sum;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		sum = 0;
		for(int i=0;i<n;i++){
			scanf("%lld", &val);
			sum += val;
		}
		if(sum % n == 0)
			printf("%d\n", n);
		else
			printf("%d\n", n-1);
	}
	return 0;
}