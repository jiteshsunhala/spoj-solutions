#include <iostream>
#include <cstdio>
#include <cmath>
#define G 9.806

using namespace std;

int main(){
	int t, test = 1;
	double d, v;
	scanf("%d", &t);
	while(t--){
		scanf("%lf%lf", &d, &v);
		double angle = (45.0 * asin(d * G / (v * v))) / acos(0.0);
		printf("Scenario #%d: ", test++);
		if(isnan(angle))
			printf("-1\n");
		else printf("%.2lf\n", angle);
	}
	return 0;
}