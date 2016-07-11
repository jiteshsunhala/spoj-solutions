#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int findLog(int n){
	int cnt = 0;
	while(n){
		cnt++;
		n >>= 1;
	}
	return cnt - 1;
}

int findLastCard(int n){
	if((n & (n-1)) == 0)
		return n;
	int logValue = findLog(n);
	int diff = n - (1 << logValue);
	return (diff << 1);
}

int main(){
	int n;
	while(true){
		scanf("%d", &n);
		if(n == 0)
			break;
		printf("%d\n", findLastCard(n));
	}
	return 0;
}