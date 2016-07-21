#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define INF 10000000
#define inRange(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)

using namespace std;

string graph[1000];
int dis[1000][1000];

void initialise(int r, int c){
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			dis[i][j] = INF;
}

vector<int> bfs(int x, int y, int r, int c){
	int a[] = {-1, 0, 1, 0}, b[] = {0, 1, 0, -1}, maxX = x, maxY = y, maxDis = 0;
	dis[x][y] = 0;
	queue<int> q;
	q.push(x);
	q.push(y);
	while(!q.empty()){
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int tmpX = x + a[i];
			int tmpY = y + b[i];
			if(inRange(tmpX, tmpY, r, c) && graph[tmpX][tmpY] == '.' && dis[tmpX][tmpY] > dis[x][y] + 1){
				dis[tmpX][tmpY] = dis[x][y] + 1;
				q.push(tmpX);
				q.push(tmpY);
				if(maxDis < dis[tmpX][tmpY]){
					maxDis = dis[tmpX][tmpY];
					maxX = tmpX;
					maxY = tmpY;
				}
			}
		}
	}
	vector<int> result;
	result.push_back(maxX);
	result.push_back(maxY);
	return result;
}

int main(){

	int t, r, c, maxDistance;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &c, &r);
		for(int i=0;i<r;i++)
			cin >> graph[i];
		maxDistance = 0;
		initialise(r, c);
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(graph[i][j] == '.' && dis[i][j] == INF){
					initialise(r, c);
					vector<int> v = bfs(i, j, r, c);
					initialise(r, c);
					v = bfs(v[0], v[1], r, c);
					maxDistance = max(maxDistance, dis[v[0]][v[1]]);
				}
			}
		}
		printf("Maximum rope length is %d.\n", maxDistance);
	}
	return 0;
}