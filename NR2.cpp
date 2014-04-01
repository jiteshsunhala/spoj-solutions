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

LLD arr[1000000];

int main(){
	
	LLD a, b, res=0;
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%lld", &arr[i]);
		res = res | arr[i];
	}
	LLD sum = 0;
	for(int i=0;i<n;i++){
		sum = sum | ((~arr[i]) & (res ^ arr[i]));
	}
	
	printf("%lld\n", sum);
	
    system("pause");
    return 0;
}
