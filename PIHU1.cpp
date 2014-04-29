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

bool process(LLD arr[1000], LLD p, int n){
	for(int i=0;i<n;i++){
		for(int j=0, k=n-1;j<k;){
			if(i == j){
				j++;
				continue;
			}
			if(i == k){
				k--;
				continue;
			}
			LLD rem = p - arr[i];
			LLD rest = arr[j] + arr[k];
			if(rem == rest)
				return true;
			if(rest < rem)
				j++;
			if(rest > rem)
				k--;
		}
	}
	return false;
}

int main(){
	
	int t, n;
	LLD arr[1000], p;
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%lld", &arr[i]);
		scanf("%lld", &p);
		sort(arr, arr+n);
		printf("%s\n", (process(arr, p, n) ? ("YES") : ("NO")));
	}
	
    return 0;
}
