#include <iostream>
#include <cstdio>
#define LLD long long int

using namespace std;

int main(){
	LLD numOfOnes[51];
	numOfOnes[0] = 0;
	for(int i=1;i<51;i++){
		numOfOnes[i] = numOfOnes[i-1] << 1;
		numOfOnes[i] += ((LLD)1 << (i-1));
	}
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%lld %lld\n", (LLD)1 << (n-1), ((LLD)1 << (n-1)) + numOfOnes[n-1]);
	}
	return 0;
}