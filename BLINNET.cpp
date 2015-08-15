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

vector< vector<int> > graph, nodes;
vector<bool> visited;

bool compare(vector<int> a, vector<int> b){
	return a[2] < b[2];
}

bool inCycle(int x, int y){
	fill(visited.begin(), visited.end(), false);
	visited[x] = true;
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int node = q.front();
		q.pop();
		if(node == y)
			return true;
		for(int i=0;i<graph[node].size();i++){
			int nextNode = graph[node][i];
			if(!visited[nextNode]){
				visited[nextNode] = true;
				q.push(nextNode);
			}
		}
	}
	return false;
}

int main(){
	
	int n, k, t, x, y;
	vector<int> tmp(3);
	char s[15];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		graph.clear();
		graph.resize(n);
		nodes.clear();
		visited.clear();
		visited.resize(n);
		for(int i=0;i<n;i++){
			scanf("%s%d", s, &k);
			while(k--){
				scanf("%d%d", &x, &y);
				if(x-1 > i){
					tmp[0] = i;
					tmp[1] = x-1;
					tmp[2] = y;
					nodes.push_back(tmp);
				}
			}
		}
		sort(nodes.begin(), nodes.end(), compare);
/*		for(int i=0;i<nodes.size();i++){
			for(int j=0;j<nodes[i].size();j++)
				cout << nodes[i][j] << " ";
			cout << endl;
		}*/
		int cost = 0, idx = 0, edges = 0;
		while(true){
			if(edges == n-1)
				break;
			if(!inCycle(nodes[idx][0], nodes[idx][1])){
				graph[nodes[idx][0]].push_back(nodes[idx][1]);
				graph[nodes[idx][1]].push_back(nodes[idx][0]);
				edges++;
				cost += nodes[idx][2];
			}
			idx++;
		}
		printf("%d\n", cost);
	}
    return 0;
}
