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

string winner(string s, string t){
	if(s == t)
		return "hhb";
	return "lxh";
}

string find_winner(int n){
	string s, t, res;
	if(n == 1){
		cin >> s;
		return s;
	}
	
	cin >> s;
	cin >> t;
	res = winner(s, t);
	for(int i=2;i<n;i++){
		s = res;
		cin >> t;
		res = winner(s, t);
	}
	return res;
}

int main(){
	
	int n, t;
	string s;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		string res = find_winner(n);
		printf("%s\n", res.data());
	}
    return 0;
}
