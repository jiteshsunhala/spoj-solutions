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

int toll[50][50], timeMat[50][50], grid[50][1001];

void init(int n, int t){
	for(int i=0;i<n;i++){
		for(int j=0;j<=t;j++){
			if(i == 0)
				grid[i][j] = 0;
			else
				grid[i][j] = INF;
		}
	}
}

void findPath(int n, int t){
	init(n, t);
	int finalNode = n-1;
	queue<int> q;
	q.push(0);
	q.push(0);
	while(!q.empty()){
		int start = q.front();
		q.pop();
		int timer = q.front();
		q.pop();
		for(int end = 1;end < n;end++){
			if(start == end)
				continue;
			int newTime = timer + timeMat[start][end];
			if(newTime <= t){
				int newToll = grid[start][timer] + toll[start][end];
				if(grid[end][newTime] > newToll){
					grid[end][newTime] = newToll;
					if(end != finalNode){
						q.push(end);
						q.push(newTime);
					}
				}
			}
		}
	}
	int minTime = 0, minToll = grid[finalNode][0];
	for(int i=1;i<=t;i++){
		if(minToll > grid[finalNode][i]){
			minTime = i;
			minToll = grid[finalNode][i];
		}
	}
	printf("%d %d\n", minToll, minTime);
}

int main(){
	
	int n, t;
	while(true){
		scanf("%d%d", &n, &t);
		if(n == 0 && t == 0)
			break;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d", &timeMat[i][j]);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d", &toll[i][j]);
		findPath(n, t);
	}
    return 0;
}
