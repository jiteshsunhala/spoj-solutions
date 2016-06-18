#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#define LLD long long int
#define SIZE 100001

using namespace std;

vector< vector<LLD> > v;

int findFactors(int n){
	int cnt = 0, factors = 1;
	while(n % 2 == 0){
		cnt++;
		n >>= 1;
	}
	factors *= ((cnt << 1) + 1);
	if(factors >= 10000)
		return -1;
	for(int i=3;i<=(int)sqrt(n);i+=2){
		int cnt = 0;
		while(n % i == 0){
			cnt++;
			n /= i;
		}
		factors *= ((cnt << 1) + 1);
		if(factors >= 10000)
			return -1;
	}
	if(n != 1)
		factors *= 3;
	if(factors >= 10000)
		return -1;
	return factors;
}

void preCalculation(){
	v.resize(10000);
	for(int i=1;i<SIZE;i++){
		int factors = findFactors(i);
		if(factors != -1)
			v[factors].push_back((LLD)i*(LLD)i);
	}
}

int main(){
	int t, k;
	LLD a, b;
	preCalculation();
	scanf("%d", &t);
	while(t--){
		scanf("%d%lld%lld", &k, &a, &b);
		int startPosition = lower_bound(v[k].begin(), v[k].end(), a) - v[k].begin();
		if(startPosition == v[k].size()){
			printf("0\n");
			continue;
		}
		int endPosition = upper_bound(v[k].begin(), v[k].end(), b) - v[k].begin();
		if(endPosition == 0){
			printf("0\n");
			continue;
		}
		endPosition--;
		if(endPosition < startPosition){
			printf("0\n");
			continue;
		}
		printf("%d\n", endPosition - startPosition + 1);
	}
	return 0;
}
