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

vector< vector< pair<int, LLD> > > graph;
vector<LLD> dis;
vector<bool> visited;
LLD maxDistance;
int maxDisNode;

void dijkstra(int s){
	queue<int> q;
	fill(visited.begin(), visited.end(), false);
	dis[s] = 0;
	maxDistance = 0;
	maxDisNode = s;
	visited[s] = true;
	q.push(s);
	while(!q.empty()){
		int node = q.front();
		q.pop();
//		cout << "working on " << node << endl;
		for(int i=0;i<graph[node].size();i++){
			int nextNode = (graph[node][i]).first;
//			cout << "next node is " << nextNode << endl;
			if(!visited[nextNode]){
				q.push(nextNode);
				dis[nextNode] = dis[node] + (graph[node][i]).second;
				visited[nextNode] = true;
				if(dis[nextNode] > maxDistance){
					maxDistance = dis[nextNode];
					maxDisNode = nextNode;
				}
			}
		}
	}
}

void init(int n){
	graph.clear();
	graph.resize(n);
	dis.clear();
	dis.resize(n);
	visited.clear();
	visited.resize(n);
}

void display(){
	for(int i=0;i<dis.size();i++)
		cout << dis[i] << " ";
	cout << endl;
}

int main(){
	
	int t, n, x, y;
	LLD len;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		init(n);
		for(int i=0;i<n-1;i++){
			scanf("%d%d%lld", &x, &y, &len);
			x--;y--;
			graph[x].push_back(make_pair(y, len));
			graph[y].push_back(make_pair(x, len));
		}
		dijkstra(0);
//		display();
		dijkstra(maxDisNode);
//		display();
		cout << maxDistance << endl;
	}
    return 0;
}
