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

char mat[1000][1000];
int dis[1000][1000];

void init(int r, int c){
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			dis[i][j] = INF;
}

void bfs(int startX, int startY, int r, int c){
	dis[startX][startY] = 0;
	deque< pair<int, int> > q;
	pair<int, int> p;
	q.push_front(make_pair(startX, startY));
	while(!q.empty()){
		p = q.front();
		q.pop_front();
		int x = p.first;
		int y = p.second;
		int a[] = {0, -1, 0, 1}, b[] = {-1, 0, 1, 0};
		for(int i=0;i<4;i++){
			int tmpX = x + a[i];
			int tmpY = y + b[i];
			if(in_range(tmpX, tmpY, r, c)){
				if(mat[tmpX][tmpY] == mat[x][y] && dis[tmpX][tmpY] > dis[x][y]){
                    q.push_front(make_pair(tmpX, tmpY));
					dis[tmpX][tmpY] = dis[x][y];
				}
				else if(mat[tmpX][tmpY] != mat[x][y]){
					if(dis[tmpX][tmpY] > dis[x][y] + 1){
					    q.push_back(make_pair(tmpX, tmpY));
						dis[tmpX][tmpY] = dis[x][y] + 1;
					}
				}
			}
		}
	}
}

void display(int r, int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout << dis[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){

	int t, r, c;
	char ch;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &r, &c);
		scanf("%c", &ch);
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				scanf("%c", &mat[i][j]);
            scanf("%c", &ch);
		}
		init(r, c);
		bfs(0, 0, r, c);
		cout << dis[r-1][c-1] << endl;
	}
    return 0;
}
