#include <iostream>
#include <cstdio>
#define inRange(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)

using namespace std;

int main(){
	int t, r, c, distance[7][7];
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &r, &c);
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				distance[i][j] = 0;
		distance[0][0] = 1;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(inRange(i-1, j, r, c))
					distance[i][j] += distance[i-1][j];
				if(inRange(i, j-1, r, c))
					distance[i][j] += distance[i][j-1];
			}
		}
		printf("%d\n", distance[r-1][c-1]);
	}
	return 0;
}