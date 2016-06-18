#include<iostream>
#include<cstdio>
#include<queue>
#define INF 100000000
#define inRange(x, y) (x >= 1 && x < 1001 && y >= 1 && y < 1001)

using namespace std;

int moves[1001][1001];

void init(){
	for(int i=0;i<1001;i++)
		for(int j=0;j<1001;j++)
			moves[i][j] = INF;
}

void numOfMoves(int x, int y){
	init();
	queue<int> q;
	q.push(x);
	q.push(y);
	moves[x][y] = 0;
	while(!q.empty()){
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		int a[] = {-1, -2, -2, -1, 1, 2, 2, 1}, b[] = {-2, -1, 1, 2, 2, 1, -1, -2};
		for(int i=0;i<8;i++){
			int tmpX = x + a[i];
			int tmpY = y + b[i];
			if(inRange(tmpX, tmpY) && moves[tmpX][tmpY] > moves[x][y] + 1){
				q.push(tmpX);
				q.push(tmpY);
				moves[tmpX][tmpY] = moves[x][y] + 1;
			}
		}
	}
}

int main(){
	int t, a, b;
	scanf("%d", &t);
	numOfMoves(1, 1);
	while(t--){
		scanf("%d %d", &a, &b);
		printf("%d\n", moves[a][b]);
	}
	return 0;
}
