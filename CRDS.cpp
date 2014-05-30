#include<cstdio>
#define MOD 1000007

int main(){
	int t;
	long long int n, res;
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		res = (n * (3 * n + 1)) >> 1;
		res %= MOD;
		printf("%lld\n", res);
	}
	return 0;
}
