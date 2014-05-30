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

int sx, sy, dx, dy, r, c, dis[25][25];
string arr[25];

void init(){
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			if(arr[i][j] == 'S'){
				sx = i;
				sy = j;
			}
			else if(arr[i][j] == 'D'){
				arr[i][j] = '0';
				dx = i;
				dy = j;
			}
			dis[i][j] = INF;
		}
	dis[sx][sy] = 0;
}

void bfs(){
	init();
	queue<int> q;
	q.push(sx);
	q.push(sy);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		
		int a[] = {-1, 0, 1, 0}, b[] = {0, 1, 0, -1};
		for(int i=0;i<4;i++){
			int tx = x + a[i];
			int ty = y + b[i];
			if(in_range(tx, ty, r, c) && arr[tx][ty] != 'X' && dis[tx][ty] > (dis[x][y] + arr[tx][ty] - 48)){
				q.push(tx);
				q.push(ty);
				dis[tx][ty] = (dis[x][y] + arr[tx][ty] - 48);
			}
		}
	}
}

int main(){
	
	while(true){
		scanf("%d%d", &c, &r);
		if(r == 0 && c == 0)
			break;
		for(int i=0;i<r;i++)
			cin >> arr[i];
		bfs();
		printf("%d\n", dis[dx][dy]);
	}
	
    return 0;
}
