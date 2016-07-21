#include <iostream>
#include <cstdio>
#include <cmath>
#define G 9.8

using namespace std;

int main(){
	double v, h;
	while(true){
		scanf("%lf%lf", &v, &h);
		if(v == -1 && h == -1)
			break;
		printf("%.6lf\n", (v / G) * sqrt(2 * G * h + v * v));
	}
	return 0;
}