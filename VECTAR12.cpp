#include <iostream>
#include <cstdio>
#define inRange(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c && y <= x)
#define SIZE 7000
#define MOD 1000000007

using namespace std;

int arr[SIZE][SIZE];

void preCalculate(){
	arr[0][0] = 1;
	arr[1][0] = 1;
	arr[1][1] = 1;
	for(int i=2;i<SIZE;i++){
		for(int j=0;j<=i;j++){
			arr[i][j] = 0;
			if(inRange(i-1, j-1, SIZE, SIZE))
				arr[i][j] = (arr[i][j] + arr[i-1][j-1]) % MOD;
			if(inRange(i-1, j, SIZE, SIZE))
				arr[i][j] = (arr[i][j] + arr[i-1][j]) % MOD;
			if(inRange(i-1, j+1, SIZE, SIZE))
				arr[i][j] = (arr[i][j] + arr[i-1][j+1]) % MOD;
		}
	}
}

int main(){
	preCalculate();
	int t, n, k;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		printf("%d\n", arr[n][k]);
	}
	return 0;
}