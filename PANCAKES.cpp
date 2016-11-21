#include <iostream>
#include <cstdio>
#define INF 100000000

using namespace std;

int main(){
	int n, r, in[100], value;
	while(true){
		scanf("%d%d", &n, &r);
		if(n == 0 && r == 0)
			break;
		for(int i=0;i<n;i++){
			scanf("%d", &in[i]);
			in[i] *= 10;
		}
		int recipe = 1, maxCakes = 0;
		for(int i=0;i<r;i++){
			int minCakes = INF;
			for(int j=0;j<n;j++){
				scanf("%d", &value);
				if(value == 0)
					continue;
				minCakes = min(minCakes, in[j] / value);
			}
			if(maxCakes < minCakes){
				recipe = i + 1;
				maxCakes = minCakes;
			}
		}
		printf("%d %d\n", recipe, maxCakes);
	}
}