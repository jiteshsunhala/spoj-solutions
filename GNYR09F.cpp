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

LLD mat[101][101][2];

void init(){
	
	for(int i=0;i<101;i++)
		for(int j=0;j<101;j++)
			for(int k=0;k<2;k++)
				mat[i][j][k] = 0;
	
	mat[1][0][0] = 1;
	mat[1][0][1] = 1;
	
	for(int i=2;i<101;i++){
		
		mat[i][0][0] = mat[i-1][0][0] + mat[i-1][0][1];
		mat[i][0][1] = mat[i-1][0][0];
		
		for(int j=1;j<i;j++){
			mat[i][j][0] = mat[i-1][j][0] + mat[i-1][j][1];
			mat[i][j][1] = mat[i-1][j][0] + mat[i-1][j-1][1];
		}
	}
	
}

int main(){
	
	init();
	int t, c, n, k;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &c, &n, &k);
		printf("%d %lld\n", c, mat[n][k][0] + mat[n][k][1]);
	}
    return 0;
}
