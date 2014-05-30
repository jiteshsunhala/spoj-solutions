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
#define INF 10000000
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int mat[20][20], x, y, r, c, dis[20][20];

void init(){
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			dis[i][j] = INF;
}

void bfs(){
	init();
	int val = mat[x][y];
	dis[x][y] = 0;
	
	queue<int> q;
	q.push(x);
	q.push(y);
	
	while(!q.empty()){
		int tx = q.front();
		q.pop();
		int ty = q.front();
		q.pop();
		
		//	down
		if(in_range(tx + 1, ty, r, c) && dis[tx + 1][ty] > dis[tx][ty] + mat[tx + 1][ty]){
			dis[tx + 1][ty] = dis[tx][ty] + mat[tx + 1][ty];
			q.push(tx + 1);
			q.push(ty);
		}
		
		//	right
		if(in_range(tx, ty + 1, r, c) && dis[tx][ty + 1] > dis[tx][ty] + mat[tx][ty + 1]){
			dis[tx][ty + 1] = dis[tx][ty] + mat[tx][ty + 1];
			q.push(tx);
			q.push(ty + 1);
		}
		
	}
}

int main(){
	
	scanf("%d%d%d%d", &r, &c, &x, &y);
	x--;
	y--;
	
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			scanf("%d", &mat[i][j]);
			
	bfs();
	
	if(mat[x][y] - dis[r-1][c-1] >= 0)
		printf("Y %d", mat[x][y] - dis[r-1][c-1]);
	else
		printf("N");
	
    return 0;
}
