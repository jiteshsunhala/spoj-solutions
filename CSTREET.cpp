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

vector< vector<int> > graph, desc;
vector<bool> visited;

int total_weight;

void initialise(int n, int m){
	total_weight = 0;
	graph.clear();
	graph.resize(n + 1);
	desc.clear();
	desc.resize(m);
	visited.resize(n + 1);
	for(int i=0;i<m;i++)
		desc[i].resize(3);
}

bool compare(vector<int> a, vector<int> b){
	return a[2] < b[2];
}

void display(vector< vector<int> > v){
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
	system("pause");
}

void dfs(int begin){
	visited[begin] = true;
	for(int i=0;i<graph[begin].size();i++){
		int node = graph[begin][i];
		if(!visited[node])
			dfs(node);
	}
}

bool cycle(int idx){
	fill(visited.begin(), visited.end(), false);
	int begin = desc[idx][0];
	int end = desc[idx][1];
	dfs(begin);
	return visited[end];
}

void insert(int idx){
	int begin = desc[idx][0];
	int end = desc[idx][1];
	graph[begin].push_back(end);
	graph[end].push_back(begin);
	//display(graph);
}

void kruskal(int n){
	int edges = 0, idx = 0;
	while(edges < n - 1){
		if(!cycle(idx)){
			insert(idx);
			total_weight += desc[idx][2];
			edges++;
		}
		idx++;
	}
}

int main(){
	
	int t, p, n, m;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &p, &n, &m);
		initialise(n, m);
		for(int i=0;i<m;i++)
			scanf("%d%d%d", &desc[i][0], &desc[i][1], &desc[i][2]);
		sort(desc.begin(), desc.end(), compare);
		//display(desc);
		kruskal(n);
		cout << total_weight * p << endl;
	}
    return 0;
}
