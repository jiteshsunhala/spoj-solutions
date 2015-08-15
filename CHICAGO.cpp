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
#define INF 1

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

vector< vector< pair<int, double> > > graph;
vector<double> dis;

double dijkstra(int s, int d){
	queue<int> q;
	fill(dis.begin(), dis.end(), -INF);
	dis[s] = 1;
	q.push(s);
	while(!q.empty()){
		int node = q.front();
		q.pop();
//		cout << "working on " << node << endl;
		for(int i=0;i<graph[node].size();i++){
			int nextNode = (graph[node][i]).first;
//			cout << "next node is " << nextNode << endl;
			if(dis[nextNode] < dis[node] * (graph[node][i]).second){
				q.push(nextNode);
				dis[nextNode] = dis[node] * (graph[node][i]).second;
			}
		}
	}
	return dis[d] * 100;
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
	int n, m, x, y;
	double cost;
	pair<int, int> tmpPair;
	while(true){
		scanf("%d", &n);
		if(n == 0)
			break;
		scanf("%d", &m);
		graph.clear();
		graph.resize(n);
		dis.clear();
		dis.resize(n);
		for(int i=0;i<m;i++){
			scanf("%d%d%lf", &x, &y, &cost);
			x--;
			y--;
			graph[y].push_back(make_pair(x, cost / 100));
			graph[x].push_back(make_pair(y, cost / 100));
		}
		//display();
		printf("%.6lf percent\n", dijkstra(0, n-1));
		/*if(distance == INF)
			printf("NONE\n");
		else
			printf("%d\n", distance);*/
	}
	return 0;
}
