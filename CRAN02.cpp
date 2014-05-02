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
map<LLD, LLD> mymap;

int main(){
	
	int t, n;
	LLD cnt, sum = 0;
	scanf("%d", &t);
	while(t--){
		
		mymap.clear();
		
		cnt = 0;
		sum = 0;
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%lld", &arr[i]);
			arr[i] += sum;
			sum = arr[i];
			if(mymap[arr[i]] == 0)
				mymap[arr[i]] = 1;
			else
				mymap[arr[i]]++;
		}
		
		for(map<LLD, LLD>::iterator it = mymap.begin();it != mymap.end();it++){
			if(it->first == 0)
				cnt += (it->second + (((it->second) * (it->second - 1)) >> 1));
			else
				cnt += (((it->second) * (it->second - 1)) >> 1);
		}
		
		printf("%lld\n", cnt);
	}
    return 0;
}
