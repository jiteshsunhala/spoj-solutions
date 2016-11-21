#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){

	int t;
	double n;
	scanf("%d", &t);
	while(t--){
		scanf("%lf", &n);
		printf("%s\n", ((floor(sqrt(n)) == sqrt(n)) ? "YES" : "NO"));
	}
	return 0;
}