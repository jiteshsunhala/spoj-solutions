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
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

char mat[100][100];
int dis[100][100];

void init(int r, int c){
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			dis[i][j] = INF;
}

int bfs(int sx, int sy, int ex, int ey, int r, int c){
	queue<int> q;
	int a[] = {-1, 0, 1, 0}, b[] = {0, 1, 0, -1};
	q.push(sx);
	q.push(sy);
	dis[sx][sy] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == ex && y == ey)
			return dis[x][y];
		for(int i=0;i<4;i++){
			int tx = x + a[i];
			int ty = y + b[i];
			if(in_range(tx, ty, r, c) && mat[tx][ty] != '*' && dis[tx][ty] > dis[x][y] + 1){
				dis[tx][ty] = dis[x][y] + 1;
				q.push(tx);
				q.push(ty);
			}
		}
	}
	return -1;
}

int main(){
	
	int t, r, c, sx, sy, ex, ey;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &r, &c);
		init(r, c);
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin >> mat[i][j];
				if(mat[i][j] == '$'){
					sx = i;
					sy = j;
				}
				if(mat[i][j] == '#'){
					ex = i;
					ey = j;
				}
			}
		}
		printf("%d\n", bfs(sx, sy, ex, ey, r, c));
	}
    return 0;
}
