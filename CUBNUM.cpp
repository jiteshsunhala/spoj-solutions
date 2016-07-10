#include <iostream>
#include <cstdio>
#include <cmath>
#define SIZE 100001
#define INF 1000000

using namespace std;

int cubeSum[SIZE], cubeNumber[46];

void findCubeNumbers(){
	for(int i=0;i<46;i++)
		cubeNumber[i] = (i + 1) * (i + 1) * (i + 1);
}

void preCompute(){
	findCubeNumbers();
	cubeSum[0] = 0;
	for(int i=1;i<SIZE;i++){
		cubeSum[i] = INF;
		for(int j=45;j>=0;j--){
			if(cubeNumber[j] > i)
				continue;
			cubeSum[i] = min(cubeSum[i], 1 + cubeSum[i - cubeNumber[j]]);
		}
	}
}

int main(){
	preCompute();
	int n, cas = 1;
	while(scanf("%d", &n) != EOF){
		printf("Case #%d: %d\n", cas++, cubeSum[n]);
	}
	return 0;
}