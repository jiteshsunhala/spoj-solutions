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
#define SIZE 10000

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

LLD arr[SIZE];

LLD findQuantity(LLD x, LLD n){
	LLD result = 0;
	for(int i=0;i<n;i++)
		result += (x / arr[i]);
	return result;
}

LLD binarySearch(LLD lo, LLD hi, LLD n, LLD m){
	while(hi > lo){
		LLD mi = (lo + hi) / 2;
		LLD quantity = findQuantity(mi, n);
		if(quantity >= m)
			hi = mi;
		else if(quantity < m)
			lo = mi + 1;
	}
	return hi;
}

int main(){
	
	LLD t, n, m, lo = 1, hi;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld%lld", &n, &m);
		hi = 0;
		for(int i=0;i<n;i++){
			scanf("%lld", &arr[i]);
			hi = max(hi, arr[i] * m);
		}
		printf("%lld\n", binarySearch(lo, hi, n, m));
	}
    return 0;
}
