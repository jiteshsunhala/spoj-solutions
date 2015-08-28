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

vector< vector<int> > graph;
vector<bool> visited;

void insert(int x, int y){
	graph[x].push_back(y);
	graph[y].push_back(x);
}

void dfsUtil(int begin){
	visited[begin] = true;
	for(int i=0;i<graph[begin].size();i++){
		int node = graph[begin][i];
		if(!visited[node])
			dfsUtil(node);
	}
}

bool isConnected(){
	int components = 0;
	fill(visited.begin(), visited.end(), false);
	for(int i=0;i<graph.size();i++){
		if(!visited[i]){
			dfsUtil(i);
			components++;
		}
	}
	return (components == 1);
}

bool isCyclicUtil(int x, int parent){
	visited[x] = true;
	for(int i=0;i<graph[x].size();i++){
		int node = graph[x][i];
		if(!visited[node]){
			if(isCyclicUtil(node, x))
				return true;
		}
		else if(node != parent)
			return true;
	}
	return false;
}

bool isCyclic(){
	fill(visited.begin(), visited.end(), false);
	for(int i=0;i<graph.size();i++)
		if(!visited[i])
			if(isCyclicUtil(i, -1))
				return true;
	return false;
}

int main(){
	
	int x, y, n, m;
	scanf("%d%d", &n, &m);
	graph.resize(n);
	visited.resize(n);
	for(int i=0;i<m;i++){
		scanf("%d%d", &x, &y);
		insert(x-1, y-1);
	}
	if(isConnected() && !isCyclic())
		printf("YES");
	else
		printf("NO");
    return 0;
}
