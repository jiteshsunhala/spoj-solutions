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
#define SIZE 1411
#define in_range(n) (n >= 0 && n < SIZE)

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;
int arr[SIZE];

bool contiguous(int start, int end){
	for(int i=start;i<=end;i+=30){
		if(!in_range(i))
			return false;
		if(!arr[i])
			return false;
	}
	return true;
}

int update(int start, int end){
	int minVal = arr[start];
	for(int i=start;i<=end;i+=30)
		minVal = min(minVal, arr[i]);
	for(int i=start;i<=end;i+=30)
		arr[i] -= minVal;
	return minVal;
}

int main(){
	
	int val, n;
	fill(arr, arr + SIZE, 0);
	scanf("%d", &n);
	while(n--){
		scanf("%d", &val);
		arr[val]++;
	}
	int cnt = 0;
	for(int i=0;i<SIZE;i++)
		while(arr[i])
			for(int j=3;j>=0 && arr[i];j--)
				if(contiguous(i, i + j * 30))
					cnt += update(i, i + j * 30);
	printf("%d", cnt);
    return 0;
}
