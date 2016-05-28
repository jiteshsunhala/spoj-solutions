#include <iostream>
#include <cstdio>
#include <string>
#define inRange(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
using namespace std;

string arr[100], pattern = "ALLIZZWELL";
bool patternFound, visited[100][100];

void init(int r, int c){
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			visited[i][j] = false;
}

void findPattern(int x, int y, int r, int c, int idx){
	if(idx == 9){
		patternFound = true;
		return;
	}
	visited[x][y] = true;
	int a[] = {-1, -1, -1, 0, 0, 1, 1, 1}, b[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	for(int i=0;i<8 && !patternFound;i++){
		int nextX = x + a[i];
		int nextY = y + b[i];
		if(inRange(nextX, nextY, r, c) && !visited[nextX][nextY] && arr[nextX][nextY] == pattern[idx + 1])
			findPattern(nextX, nextY, r, c, idx + 1);
	}
	visited[x][y] = false;
}

int main() {
	int t, r, c;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &r, &c);
		for(int i=0;i<r;i++)
			cin >> arr[i];
		init(r, c);
		patternFound = false;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(arr[i][j] == 'A'){
					findPattern(i, j, r, c, 0);
					if(patternFound)
						break;
				}
			}
			if(patternFound)
				break;
		}
		printf("%s\n", (patternFound ? "YES" : "NO"));
	}
	return 0;
}
