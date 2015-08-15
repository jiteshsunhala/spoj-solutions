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

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

map<string, int> msi;
map<int, string> mis;
stack<string> st;
vector< vector<int> > graph;
vector<bool> visited;

void init(int n){
	graph.clear();
	graph.resize(n);
	msi.clear();
	mis.clear();
	visited.clear();
	visited.resize(n);
	fill(visited.begin(), visited.end(), false);
}

void dfs(int begin){
	visited[begin] = true;
	for(int i=0;i<graph[begin].size();i++){
		int node = graph[begin][i];
		if(!visited[node])
			dfs(node);
	}
	st.push(mis[begin]);
}

void display(){
	for(int i=0;i<graph.size();i++){
		cout << i << ": ";
		for(int j=0;j<graph[i].size();j++){
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	
	string s, t;
	int n, te, idx, cas = 1;
	scanf("%d", &te);
	while(te--){
		scanf("%d", &n);
		init(n);
		idx = 1;
		for(int i=1;i<n;i++){
			cin >> s >> t;
			if(msi[s] == 0){
				msi[s] = idx;
				mis[idx - 1] = s;
				idx++;
			}
			if(msi[t] == 0){
				msi[t] = idx;
				mis[idx - 1] = t;
				idx++;
			}
			graph[msi[s] - 1].push_back(msi[t] - 1);
		}
		for(int i=0;i<n;i++)
			if(!visited[i])
				dfs(i);
		printf("Scenario #%d:\n", cas++);
		while(!st.empty()){
			cout << st.top() << endl;
			st.pop();
		}
		printf("\n");
	}
    return 0;
}
