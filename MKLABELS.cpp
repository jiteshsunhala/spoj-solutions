#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int myPower(int b, int e){
	int prod = 1;
	for(int i=0;i<e;i++)
		prod *= b;
	return prod;
}

int main(){
	int n, test = 1;
	while(true){
		scanf("%d", &n);
		if(n == 0)
			break;
		printf("Case %d, N = %d, # of different labelings = %d\n", test++, n, myPower(n, max(n-2, 0)));
	}
	return 0;
}