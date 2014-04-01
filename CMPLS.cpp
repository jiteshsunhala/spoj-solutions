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

VVI table;
VI tmp;

void input(int n){
	int val;
	table.push_back(tmp);
	for(int i=0;i<n;i++){
		scanf("%d", &val);
		table[0].push_back(val);
	}
}

void display(){
	for(int i=0;i<table.size();i++){
		for(int j=0;j<table[i].size();j++)
			cout << table[i][j] << " ";
		cout << endl;
	}
}

bool constant(VI vec){
	int cnt = vec[0];
	for(int i=1;i<vec.size();i++)
		if(vec[i] != cnt)
			return false;
	return true;
}

void process_down(){
	int idx = 0;
	while(!constant(table[idx])){
		table.push_back(tmp);
		for(int i=1;i<table[idx].size();i++)
			table[idx+1].push_back(table[idx][i] - table[idx][i-1]);
		idx++;
	}
}

void process_up(int n, int nxt){
	int idx = table.size() - 1;
	int lsize = table[idx-1].size() - 1;
	for(int i=0;i<nxt+1;i++)
		table[idx].push_back(table[idx][0]);
	idx--;	
	while(idx != -1){
		for(int i=lsize;i < lsize + nxt;i++){
			table[idx].push_back(table[idx][i] + table[idx + 1][i]);
		}
		lsize = table[idx-1].size() - 1;
		idx--;
	}
}

int main(){
	
	int t, n, nxt;
	scanf("%d", &t);
	while(t--){
		table.clear();
		scanf("%d%d", &n, &nxt);
		input(n);
		process_down();
		process_up(n, nxt);
		
		for(int i=n;i<n + nxt;i++)
			printf("%d ", table[0][i]);
		printf("\n");
	}
	
    system("pause");
    return 0;
}
