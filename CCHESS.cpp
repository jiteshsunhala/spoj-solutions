#include <iostream>
#include <cstdio>
#include <queue>
#define INF 1000000000
#define inRange(x, y) (x >= 0 && x < 8 && y >= 0 && y < 8)
#define calculateDistance(a, b, c, d) (a * c) + (b * d)

using namespace std;

int mat[8][8];

int findMinimumPath(int a, int b, int c, int d){
	queue<int> q;
	q.push(a);
	q.push(b);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int a[] = {-1, -2, -2, -1, 1, 2, 2, 1}, b[] = {-2, -1, 1, 2, 2, 1, -1, -2};
		for(int i=0;i<8;i++){
			int tmpX = x + a[i];
			int tmpY = y + b[i];
			if(inRange(tmpX, tmpY) && mat[tmpX][tmpY] > mat[x][y] + calculateDistance(x, y, tmpX, tmpY)){
				mat[tmpX][tmpY] = mat[x][y] + calculateDistance(x, y, tmpX, tmpY);
				q.push(tmpX);
				q.push(tmpY);
			}
		}
	}
	return ((mat[c][d] == -1) ? -1 : mat[c][d]);
}

void init(){
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			mat[i][j] = INF;
}

int main(){
	int a, b, c, d;
	while(scanf("%d%d%d%d", &a, &b, &c, &d) != EOF){
		init();
		mat[a][b] = 0;
		printf("%d\n", findMinimumPath(a, b, c, d));
	}
	return 0;
}
