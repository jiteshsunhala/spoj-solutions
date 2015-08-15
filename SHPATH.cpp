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

vector< vector< pair<int, LLD> > > graph;
vector<LLD> dis;
map<string, int> mymap;

LLD dijkstra(int s, int d){
	set<int> q;
	set<int>::iterator it;
	fill(dis.begin(), dis.end(), INF);
	dis[s] = 0;
	q.insert(s);
	while(!q.empty()){
		it = q.begin();
		int node = *it;
		q.erase(it);
//		cout << "working on " << node << endl;
		for(int i=0;i<graph[node].size();i++){
			int nextNode = (graph[node][i]).first;
//			cout << "next node is " << nextNode << endl;
//			cout << "dis[nextNode] = " << dis[nextNode] << endl;
			if(dis[nextNode] > dis[node] + (graph[node][i]).second){
				q.insert(nextNode);
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
	int q, t, n, m, x;
	LLD y;
	string cityName, c1, c2;
	double cost;
	pair<int, int> tmpPair;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		graph.clear();
		graph.resize(n + 1);
		dis.clear();
		dis.resize(n + 1);
		for(int i=1;i<=n;i++){
			cin >> cityName;
			mymap[cityName] = i;
			scanf("%d", &m);
			while(m--){
				scanf("%d%lld", &x, &y);
				graph[i].push_back(make_pair(x, y));
			}
		}
//		display();
		scanf("%d", &q);
		while(q--){
			cin >> c1 >> c2;
			printf("%lld\n", dijkstra(mymap[c1], mymap[c2]));
		}
	}
	return 0;
}
