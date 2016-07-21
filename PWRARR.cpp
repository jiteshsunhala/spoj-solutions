#include <iostream>
#include <cstdio>
#define SIZE 50001
#define LLD long long int

using namespace std;

int main(){
	int num, t, n, arr[SIZE];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		fill(arr, arr + SIZE, 0);
		for(int i=0;i<n;i++){
			scanf("%d", &num);
			arr[num]++;
		}
		LLD total = 0, sum = 0;
		for(int i=1;i<SIZE;i++){
			sum += arr[i];
			total += (sum * arr[i]);
		}
		printf("%lld\n", total);
	}
	return 0;
}