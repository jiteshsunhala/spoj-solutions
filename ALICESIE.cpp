#include<cstdio>
using namespace std;

int main(){
	int t, n;
	scanf("%d\n", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", ((n - 1) / 2) + 1);
	}
    return 0;
}
