#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int n, val, sum = 0;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &val);
		if(val < 0 || val >= n){
			printf("-1");
			return 0;
		}
		sum += val;
	}
	if(sum % (n - 1) != 0){
		printf("-1");
		return 0;
	}
	printf("%d", sum / (n-1));
	return 0;
}