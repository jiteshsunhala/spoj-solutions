#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#include<utility>
#include<string>
#include<cstring>
#include<set>
#include<cmath>
#include<vector>
#include<fstream>
#include<map>
#include<list>
#include<algorithm>
#define SIZE 100000
#define in_range(x, n) (x >= 0 && x < n)

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int arr[SIZE], sum[SIZE];

LLD getSum(int i, int n){
	if(in_range(i, n))
		return sum[i];
	return 0;
}

int main(){
	
	int n, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		sum[n-1] = arr[n-1];
		for(int i=n-2;in_range(i, n) && i >= n-3;i--)
			sum[i] = (arr[i] + sum[i+1]);
		for(int i=n-4;in_range(i, n);i--){
			LLD sum1 = arr[i] + getSum(i+2, n);
			LLD sum2 = arr[i] + arr[i+1] + getSum(i+4, n);
			LLD sum3 = arr[i] + arr[i+1] + arr[i+2] + getSum(i+6, n);
			sum[i] = max(sum1, max(sum2, sum3));
		}
		printf("%d\n", sum[0]);
	}
    return 0;
}
