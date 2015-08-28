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

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int arr[SIZE];

bool canPlaceCows(int n, int x, int c){
	int count = 1, last = arr[0];
	for(int i=1;i<n;i++){
		if(arr[i] - last >= x){
			count++;
			last = arr[i];
			if(count == c)
				return true;
		}
	}
	return false;
}

int binarySearch(int n, int c){
	int start = 0, end = arr[n-1];
	while(start < end){
		int mid = (start + end) >> 1;
		if(canPlaceCows(n, mid, c) == 1)
			start = mid + 1;
		else
			end = mid;
	}
	return start - 1;
}

int main(){
	
	int t, n, c;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &c);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + n);
		printf("%d\n", binarySearch(n, c));
	}
    return 0;
}
