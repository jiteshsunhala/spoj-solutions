#include <iostream>
#include <cstdio>
#define LLD long long int
#define INF 1000
using namespace std;

int arr[101], t, n, result[101][100001], minVal, maxVal;

int main(){
	LLD totalSum;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		minVal = INF;
		maxVal = 0;
		for(int i=1;i<=n;i++){
			scanf("%d", &arr[i]);
			minVal = min(minVal, arr[i]);
			maxVal += arr[i];
		}
		for(int i=1;i<=maxVal;i++)
			result[0][i] = 0;
		for(int i=0;i<n;i++)
			result[i][0] = 1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=maxVal;j++){
				result[i][j] = result[i-1][j];
				if(arr[i] <= j)
					result[i][j] |= result[i-1][j-arr[i]];
			}
		}
		totalSum = 0;
		for(int i=1;i<=maxVal;i++)
			totalSum += (result[n][i]) ? i : 0;
		printf("%lld\n", totalSum);
	}
	return 0;
}