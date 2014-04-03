#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#include<utility>
#include<string>
#include<cstring>
#include<set>
#include<cmath>
#include<vector>
#include<fstream>
#include<map>
#include<list>
#include<algorithm>

#define VI vector<int>
#define VF vector<float>
#define VD vector<double>
#define VC vector<char>
#define VVI vector<VI>
#define VVF vector<VF>
#define VVD vector<VD>
#define VVC vector<VC>
#define SI set<int>
#define SF set<float>
#define SD set<double>
#define SC set<char>
#define SSI set<SI>
#define SSF set<SF>
#define SSD set<SD>
#define SSC set<SC>
#define STI stack<int>
#define STF stack<float>
#define STD stack<double>
#define STC stack<char>
#define STSTI stack<STI>
#define STSTF stack<STF>
#define STSTD stack<STD>
#define STSTC stack<STC>
#define MOD 10000007

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

LLD mod_power(LLD a, LLD n, LLD mod){
	LLD y = 1;
	while(n){
		if(n & 1)
			y = (y * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return y;
}

int main(){
	
	LLD res, n, k, v1, v2, v3, v4;
	while(true){
		scanf("%lld%lld", &n, &k);
		if(!n && !k)
			break;
		v1 = mod_power(n, k, MOD);
//		cout << v1 << endl;
		v2 = mod_power(n-1, k, MOD);
		v2 = (2 * v2) % MOD;
//		cout << v2 << endl;
		v3 = mod_power(n, n, MOD);
//		cout << v3 << endl;
		v4 = mod_power(n-1, n-1, MOD);
		v4 = (2 * v4) % MOD;
//		cout << v4 << endl;
		res = (((((v1 + v2) % MOD) + v3) % MOD) + v4) % MOD;
		printf("%lld\n", res);
	}
    return 0;
}
