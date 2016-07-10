#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	bool found[20001];
	int input[1000];
	int t, n;
	scanf("%d", &t);
	while(t--){
		fill(found, found + 20001, false);
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%d", &input[i]);
			found[input[i] + 10000] = true;
		}
		int cnt = 0;
		for(int i=0;i<n;i++){
			if(input[i] % 2 == 0){
				int half = input[i] / 2;
				cnt += (found[half + 10000] ? 1 : 0);
			}
		}
		printf("%d\n", cnt);
	}
}