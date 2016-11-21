#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define SIZE 1000000
#define MAX_SIZE 671

using namespace std;

bool prime[SIZE];
int validPrimes[MAX_SIZE], idx = 0;

void preparePrimes(){
	fill(prime, prime + SIZE, true);
	prime[1] = false;
	for(int i=3;i<=1000;i++){
		if(prime[i]){
			for(int j=i*i;j<SIZE;j+=(i<<1))
				prime[j] = false;
		}
	}
}

void findValidPrimes(){
	validPrimes[idx++] = 2;
	validPrimes[idx++] = 5;
	queue<int> q;
	q.push(3);q.push(1);
	q.push(7);q.push(1);
	int cnt = 2;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int len = q.front();
		q.pop();
		validPrimes[idx++] = x;
		if(len == 6)
			continue;
		for(int i=1;i<10;i++){
			int y = (int)(i *pow(10, len)) + x;
			if(prime[y]){
				q.push(y);q.push(len + 1);
			}
		}
	}
}

int main(){
	preparePrimes();
	findValidPrimes();
	sort(validPrimes, validPrimes + MAX_SIZE);
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int position = upper_bound(validPrimes, validPrimes + MAX_SIZE, n) - validPrimes;
		printf("%d\n", position);
	}
	return 0;
}