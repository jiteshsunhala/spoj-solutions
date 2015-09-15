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
#define SIZE 50

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

LLD arr[SIZE];

LLD power2(int n){
	LLD res = 1ll << n;
	return res;
}

void preComputation(){
	arr[0] = 0;
	for(int i=1;i<SIZE;i++)
		arr[i] = (((arr[i-1] << 1) % MOD) + (power2(i-1)) % MOD) % MOD;
}

void display(){
	for(int i=0;i<SIZE;i++)
		cout << i << " " << arr[i] << endl;
	system("pause");
}

int myLog2(LLD n){
	int cnt = 0;
	while(n){
		cnt++;
		n >>= 1;
	}
	return cnt - 1;
}

LLD findTotalOnes(LLD n){
	if(n == 0)
		return 0;
	int lg2 = myLog2(n);
	LLD cnt = arr[lg2];
	LLD power2log = power2(lg2) - 1;
	LLD remaining = n & power2log;
	cnt = (cnt + ((remaining + 1) % MOD)) % MOD;
	n = remaining;
	return (cnt + findTotalOnes(n)) % MOD;
}

int main(){
	
	preComputation();
	int t;
	LLD n;
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		printf("%lld\n", findTotalOnes(n));
	}
    return 0;
}
