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

int main(){
	
	map< pair<int, int>, int > mymap;
	int n, arr[200][2];
	
	while(true){
		scanf("%d", &n);
		if(!n)
			break;
		mymap.clear();
		for(int i=0;i<n;i++)
			scanf("%d %d", &arr[i][0], &arr[i][1]);
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				int num = arr[i][1] - arr[j][1];
				int den = arr[i][0] - arr[j][0];
				
				int g = __gcd(num, den);
				num /= g;
				den /= g;
				
				if(den < 0){
					num *= -1;
					den *= -1;
				}
				mymap[make_pair(num, den)] = 1;
			}
		}
		printf("%d\n", mymap.size());
	}
    return 0;
}
