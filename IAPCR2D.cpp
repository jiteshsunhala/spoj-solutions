#include<cmath>
#include<iostream>
#include<cstdio>
#include<map>
#define SIZE 111

using namespace std;

map<long long int, int> myMap;
long long int factorCount[SIZE];

void populateFactors(int n){
	while(!(n & 1)){
		factorCount[2]++;
		n >>= 1;
	}
	for(int i=3;i<=sqrt(n);i+=2){
		while(n % i == 0){
			factorCount[i]++;
			n /= i;
		}
	}
	if(n != 1)
		factorCount[n]++;
}
			

long long int findFactors(int n){
	populateFactors(n);
	long long int result = 1;
	for(int i=2;i<SIZE;i++)
		result *= (factorCount[i] + 1);
	return result;
}

void preCalculate(){
	fill(factorCount, factorCount + SIZE, 0);
	myMap[1] = 1;
	for(int i=2;i<110;i++){
		long long int factors = findFactors(i);
		myMap[factors] = i;
	}
}

int main(){
	int t;
	long long int n;
	preCalculate();
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		if(myMap[n] == 0)
			printf("nai\n");
		else
			printf("%d\n", myMap[n]);
	}
	return 0;
}
