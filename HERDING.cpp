#include <iostream>
#include <cstdio>
#include <algorithm>
#define INF 10000000
#define inRange(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

string graph[1000];
int dis[1000][1000], maxHerds = 0;

void initialize(int r, int c){
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			dis[i][j] = INF;
		}
}

int dfs(int x, int y, int r, int c, int herdNo){
	dis[x][y] = herdNo;
	if(graph[x][y] == 'S' && inRange(x + 1, y, r, c)){
		if(dis[x + 1][y] > herdNo){
			dis[x][y] = min(dis[x][y], dfs(x + 1, y, r, c, herdNo));
			return dis[x][y];
		} else {
			dis[x][y] = dis[x + 1][y];
			return dis[x][y];
		}
	}

	if(graph[x][y] == 'N' && inRange(x - 1, y, r, c)){
		if(dis[x - 1][y] > herdNo){
			dis[x][y] = min(dis[x][y], dfs(x - 1, y, r, c, herdNo));
			return dis[x][y];
		} else {
			dis[x][y] = dis[x - 1][y];
			return dis[x][y];
		}
	}

	if(graph[x][y] == 'W' && inRange(x, y - 1, r, c)){
		if(dis[x][y - 1] > herdNo){
			dis[x][y] = min(dis[x][y], dfs(x, y - 1, r, c, herdNo));
			return dis[x][y];
		} else {
			dis[x][y] = dis[x][y - 1];
			return dis[x][y];
		}
	}

	if(graph[x][y] == 'E' && inRange(x, y + 1, r, c)){
		if(dis[x][y + 1] > herdNo){
			dis[x][y] = min(dis[x][y], dfs(x, y + 1, r, c, herdNo));
			return dis[x][y];
		} else {
			dis[x][y] = dis[x][y + 1];
			return dis[x][y];
		}
	}
	return dis[x][y];
}

int main(){

	int r, c;
	scanf("%d%d", &r, &c);
	for(int i=0;i<r;i++)
		cin >> graph[i];
	initialize(r, c);
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(dis[i][j] == INF){
				int herdNo = dfs(i, j, r, c, maxHerds + 1);
				maxHerds = max(maxHerds, herdNo);
			}
		}
	}
/*
	for(int i=0;i<r;i++){
		cout << graph[i] << endl;
	}

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout << dis[i][j] << " ";
		}
		cout << endl;
	}
*/
	printf("%d", maxHerds);
	return 0;
}