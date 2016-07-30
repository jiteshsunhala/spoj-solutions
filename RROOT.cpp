#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int t;
	double s;
	scanf("%d", &t);
	while(t--){
		scanf("%lf", &s);
		printf("%.6lf\n", 1 - (1 / (3 * sqrt(s / 2.0))));
	}
	return 0;
}