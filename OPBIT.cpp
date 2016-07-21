#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int t, a, b;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &a, &b);
		int r1 = (int)sqrt(a);
		int r2 = (int)sqrt(b);
		int andValue = ~0, xorValue = 0;
		for(int i=r1;i<r2;i++){
			int diff = 2 * i + 1;
			andValue &= diff;
			xorValue ^= diff;
		}
		printf("%d\n", andValue & xorValue);
	}
	return 0;
}