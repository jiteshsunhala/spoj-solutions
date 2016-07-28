#include <iostream>
#include <cstdio>
#define MOD 100000007
#define LLD long long int

using namespace std;

int a[1001], b[1025], result[1001][1024];

LLD mulMod(LLD a, LLD b, LLD c){
	LLD res = 0;
	a %= c;
	while(b){
		if(b & 1)
			res = (res + a) % c;
		a = (a << 1) % c;
		b = b >> 1;
	}
	return (res % c);
}

LLD modPower(LLD a, LLD n, LLD mod){
	LLD y = 1;
	while(n){
		if(n & 1)
			y = mulMod(y, a, mod);
		a = mulMod(a, a, mod);
		n >>= 1;
	}
	return y;
}

int findTotal(int n){
	LLD result = modPower((LLD)2, (LLD)n, MOD);
	return (int) result;
}

int main(){
	int t, n, m, val, test = 1;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i=1;i<=n;i++)
			scanf("%d", &a[i]);
		fill(b, b + 1025, false);
		for(int i=1;i<=m;i++){
			scanf("%d", &val);
			b[val] = true;
		}
		for(int i=1;i<1024;i++)
			result[0][i] = 0;
		result[0][0] = 1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<1024;j++)
				result[i][j] = (result[i-1][j] + (result[i-1][j ^ a[i]])) % MOD;
		}
		int cnt = findTotal(n);
		for(int i=0;i<1024;i++){
			if(result[n][i] && b[i]){
				cnt = (cnt - result[n][i]);
				if(cnt < 0)
					cnt += MOD;
				cnt %= MOD;
			}
		}
		printf("Case %d: %d\n", test++, cnt);
	}
	return 0;
}