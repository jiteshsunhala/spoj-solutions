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
#define size 1000001

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int find_highest_power(int n){
	int cnt = 0, maxpower = 0;
	while(n % 2 == 0){
		cnt++;
		n >>= 1;
	}
	maxpower = max(cnt, maxpower);
	
	int sqrroot = (int)sqrt((double)n);
	
	for(int i=3;i <= sqrroot && n != 1; i+=2){
		cnt = 0;
		while(n % i == 0){
			cnt++;
			n /= i;
		}
		maxpower = max(cnt, maxpower);
	}
	
	if(n > 1)
		maxpower = max(1, maxpower);
	
	return maxpower;
}

int main(){
	
	int q, n, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", find_highest_power(n));
	}
    return 0;
}
