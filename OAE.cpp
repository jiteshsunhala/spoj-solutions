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
#define MOD 314159
typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int even[1000001], odd[1000001];

int main(){
	
	odd[1] = 1;
	even[1] = 9;
	
	for(int i=2;i<1000001;i++){
		odd[i] = (((9 * odd[i-1]) % MOD) + even[i-1]) % MOD;
		even[i] = (((9 * even[i-1]) % MOD) + odd[i-1]) % MOD;
	}
	
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", even[n]);
	}
    return 0;
}
