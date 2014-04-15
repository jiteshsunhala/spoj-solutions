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

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

vector<int> find_dimensions(int tot, int r, int b){
	
	vector<int> dimensions;
	
	for(int i=2;i<=sqrt(tot);i++){
		if(tot % i == 0){
			int q = tot / i;
			if(((2 * q) + ((i - 2) * 2)) == r){
				dimensions.push_back(max(q, i));
				dimensions.push_back(min(q, i));
				return dimensions;
			}
		}
	}
	
	return dimensions;
}

int main(){
	
	int r, b;
	scanf("%d%d", &r, &b);
	
	vector<int> res = find_dimensions(r + b, r, b);
	printf("%d %d", res[0], res[1]);
    return 0;
}
