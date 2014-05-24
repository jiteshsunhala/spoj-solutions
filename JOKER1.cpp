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
#define MOD 1000000007
typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int main(){
	
	int t, n, arr[70];
	LLD prod;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + n);
		prod = arr[0];
		for(int i=1;i<n;i++){
			if(arr[i] <= i)
				prod = 0;
			else
				prod = (prod * (arr[i] - i)) % MOD;
		}
		printf("%lld\n", prod);
	}
	printf("KILL BATMAN\n");
    return 0;
}
