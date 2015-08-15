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

int dis[100][100], mat[100][100];

void init(int r, int c){
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			dis[i][j] = INF;
	dis[0][0] = mat[0][0];
}

void display(int r, int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout << dis[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
}

void prepareDistance(int r, int c){
	init(r, c);
	queue<int> q;
	q.push(0);
	q.push(0);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int a[] = {-1, 0, 1, 0}, b[] = {0, 1, 0, -1};
		for(int i=0;i<4;i++){
			int tmpX = x + a[i];
			int tmpY = y + b[i];
			if(in_range(tmpX, tmpY, r, c) && dis[tmpX][tmpY] > dis[x][y] + mat[tmpX][tmpY]){
				dis[tmpX][tmpY] = dis[x][y] + mat[tmpX][tmpY];
				q.push(tmpX);
				q.push(tmpY);
			}
		}
	}
	//display(r, c);
}

int main(){
	
	int x, y, timer, t, r, c;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &r, &c);
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				scanf("%d", &mat[i][j]);
		prepareDistance(r, c);
		scanf("%d%d%d", &x, &y, &timer);
		if(dis[x-1][y-1] <= timer)
			printf("YES\n%d\n", timer - dis[x-1][y-1]);
		else
			printf("NO\n");
	}
    return 0;
}
