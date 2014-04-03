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
#define size 6101

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;
int mat[size+1][size+1];

int lcs(string a, string b, int l1, int l2){
	for(int i=0;i<=l1;i++)
		mat[i][0] = 0;
	for(int j=0;j<=l2;j++)
		mat[0][j] = 0;
	
	for(int i=1;i<=l1;i++){
		for(int j=1;j<=l2;j++){
			if(a[i-1] == b[j-1])
				mat[i][j] = mat[i-1][j-1] + 1;
			else
				mat[i][j] = max(mat[i][j-1], mat[i-1][j]);
		}
	}
	return mat[l1][l2];
}

int main(){
	
	string s, t;
	int c;
	cin >> c;
	while(c--){
		cin >> s;
		t = string(s.rbegin(), s.rend());
		int cnt = lcs(s, t, s.length(), t.length());
		printf("%d\n", s.length() - cnt);
	}
    return 0;
}
