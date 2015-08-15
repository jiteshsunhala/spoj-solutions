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
#define INF 100000000

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

vector< vector< pair<int, int> > > graph;
vector<int> dis;

int dijkstra(int s, int d){
	queue<int> q;
	fill(dis.begin(), dis.end(), INF);
	dis[s] = 0;
	q.push(s);
	while(!q.empty()){
		int node = q.front();
		q.pop();
//		cout << "working on " << node << endl;
		for(int i=0;i<graph[node].size();i++){
			int nextNode = (graph[node][i]).first;
//			cout << "next node is " << nextNode << endl;
			if(dis[nextNode] > dis[node] + (graph[node][i]).second){
				q.push(nextNode);
				dis[nextNode] = dis[node] + (graph[node][i]).second;
			}
		}
	}
	return dis[d];
}

void display(){
	for(int i=0;i<graph.size();i++){
		cout << i << ": ";
		for(int j=0;j<graph[i].size();j++)
			cout << "(" << graph[i][j].first << ", " << graph[i][j].second << "), ";
		cout << endl;
	}
}

int main(){
	int n, m, t, x, y, cost, s, d;
	pair<int, int> tmpPair;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &n, &m, &s, &d);
		graph.clear();
		graph.resize(n);
		dis.clear();
		dis.resize(n);
		for(int i=0;i<m;i++){
			scanf("%d%d%d", &x, &y, &cost);
			x--;
			y--;
			graph[y].push_back(make_pair(x, cost));
			graph[x].push_back(make_pair(y, cost));
		}
		int distance = dijkstra(s-1, d-1);
		if(distance == INF)
			printf("NONE\n");
		else
			printf("%d\n", distance);
	}
	return 0;
}
