#include <iostream>
#include <cstdio>
#include <vector>
#define LLD long long int

using namespace std;

vector<LLD> findCoordinates(LLD n){
	vector<LLD> v;
	LLD x[] = {1, 1, -2, -2}, addX[] = {2, 2, -2, -2};
	LLD y[] = {0, 2, 2, -2}, addY[] = {-2, 2, 2, -2};
	v.push_back(x[n % 4] + (n / 4) * addX[n % 4]);
	v.push_back(y[n % 4] + (n / 4) * addY[n % 4]);
	return v;
}

int main(){
	int t;
	LLD n;
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		vector<LLD> result = findCoordinates(n-1);
		printf("%lld %lld\n", result[0], result[1]);
	}
}