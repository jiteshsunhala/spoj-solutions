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

int arr[1000];

int findMinimumTime(int n){
	int i = 0, j = n-1, total = 0;
	while(j - i > 2){
		//	i takes j to other side. i returns back and then takes back j-1 to other side and returns back.
		int value1 = arr[j] + arr[j-1] + 2 * arr[i];
		//	i takes i + 1 to other side. i returns back and then j-1 takes j to other side and i+1 returns back.
		int value2 = arr[j] + arr[i] + 2 * arr[i+1];
		total += min(value1, value2);
		j -= 2;
	}
	if(j - i <= 1)
		total += arr[j];
	else
		total += (arr[i] + arr[i+1] + arr[j]);
	return total;
}

int main(){
	
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		printf("%d\n", findMinimumTime(n));
	}
    return 0;
}
