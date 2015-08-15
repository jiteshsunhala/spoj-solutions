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

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int matrix[1000][1000];

int findDifference(int arr[1000], int start, int end, int sum){
	for(int i=start;i<=end;i++)
		matrix[i][i] = arr[i];
	for(int i=start;i<=end-1;i++)
		matrix[i][i+1] = max(arr[i], arr[i+1]);
	for(int len = 3;start + len - 1 <= end;len++){
		for(int i=start;true;i++){
			int j = i + len - 1;
			if(j > end)
				break;
			//	select ith element.
			int total1 = arr[i] + ((arr[i+1] >= arr[j]) ? matrix[i+2][j] : matrix[i+1][j-1]);
			//	select jth element.
			int total2 = arr[j] + ((arr[i] >= arr[j-1]) ? matrix[i+1][j-1]: matrix[i][j-2]);
			matrix[i][j] = max(total1, total2);
		}
	}
	int firstScore = matrix[start][end], secondScore = sum - firstScore;	//((start == 1) ? (sum - arr[0] - firstScore) : (sum - firstScore));
	return firstScore - secondScore;
}

int main(){

	int game = 1, n, val, arr[1000], sum;
	while(true){
		scanf("%d", &n);
		if(n == 0)
			break;
		sum = 0;
		for(int i=0;i<n;i++){
			scanf("%d", &val);
			arr[i] = val;
			sum += val;
		}
		int difference = findDifference(arr, 0, n-1, sum);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", game++, difference);
	}
    return 0;
}
