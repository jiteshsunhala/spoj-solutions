#include <iostream>
#include <cstdio>
#include <algorithm>
#define SIZE 100

using namespace std;

int main(){
	int t, n, k, arr[SIZE];
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i=0;i<n;i++){
			scanf("%d", &arr[i]);
			if(arr[i] < 0 && k > 0){
				arr[i] *= -1;
				k--;
			}
		}
		sort(arr, arr + n);
		if(k % 2 == 1){
			arr[0] *= -1;
		}
		int sum = 0;
		for(int i=0;i<n;i++)
			sum += arr[i];
		printf("%d\n", sum);
	}
	return 0;
}