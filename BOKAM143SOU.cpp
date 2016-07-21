#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int cubes[51], cnt = 0;

void preCalculate(){
	for(int i=1;i<51;i++)
		cubes[i] = i * i * i;
}

void findNumberOfWays(int n, int startIdx, int nums){
	if(nums > 5)
		return;
	if(n == 0 && nums <= 5){
		cnt++;
		return;
	}
	for(int i=startIdx;i>=1;i--){
		if(n >= cubes[i])
			findNumberOfWays(n - cubes[i], i, nums + 1);
	}
}

int main(){
	int n;
	preCalculate();
	scanf("%d", &n);
	findNumberOfWays(n, cbrt(n), 0);
	printf("%d\n", cnt);
	return 0;
}