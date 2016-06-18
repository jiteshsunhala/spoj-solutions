#include<iostream>
#include<cstdio>
#define SIZE 1000001
#define LLD long long int
#define MOD 1000000007

int main(){
	LLD arr[SIZE];
	arr[0] = arr[1] = 0;
	arr[2] = arr[3] = 1;
	for(int i=4;i<SIZE;i++){
		arr[i] = (arr[i-2] + arr[i-3]) % MOD;
	}
	int t, a;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &a);
		printf("%lld\n", arr[a]);
	}
	return 0;
}
