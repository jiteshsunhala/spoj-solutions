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
#define size 1000000


typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

LLD arr[size], f[size];

void init(){
	for(int i=0;i<size;i++)
		f[i] = 1;
}

void prepare(){
	init();
	arr[0] = arr[1] = 0;
	for(int i=2;i<=(size >> 1);i++){
		for(int j=2*i;j<size;j+=i)
			f[j] += i;
	}
	for(int i=2;i<size;i++)
		arr[i] = arr[i-1] + f[i];
}

int main(){
	
	int t, n;
	prepare();
	for(scanf("%d", &t);t;t--){
		scanf("%d", &n);
		printf("%lld\n", arr[n]);
	}
	
    system("pause");
    return 0;
}
