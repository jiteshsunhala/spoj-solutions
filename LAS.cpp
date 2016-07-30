#include <iostream>
#include <cstdio>
#include <queue>
#define INF 10000000
#define NEG_INF -INF
#define MAX_DIMENSIONS 200
#define UP_DIRECTION '^'
#define RIGHT_DIRECTION '>'
#define DOWN_DIRECTION 'v'
#define LEFT_DIRECTION '<'
#define NO_DIRECTION '-'
#define FREE_CHARACTER '.'
#define BLOCKED_CHARACTER '#'
#define TERMINATE_CHARACTER 'C'
#define FORWARD_SLASH '/'
#define BACKWARD_SLASH '\\'
#define downDirection(c) (c == DOWN_DIRECTION)
#define upDirection(c) (c == UP_DIRECTION)
#define rightDirection(c) (c == RIGHT_DIRECTION)
#define leftDirection(c) (c == LEFT_DIRECTION)
#define directionCharacter(c) (rightDirection(c) || downDirection(c) || leftDirection(c) || upDirection(c))
#define freeCharacter(c) (c == FREE_CHARACTER)
#define blockedCharacter(c) (c == BLOCKED_CHARACTER)
#define terminateCharacter(c) (c == TERMINATE_CHARACTER)
#define noDirection(c) (c == NO_DIRECTION)
#define validCharacter(c) (directionCharacter(c) || freeCharacter(c) || blockedCharacter(c) || terminateCharacter(c))
#define inRange(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
#define directionChange(previousDirection, currentDirection) (noDirection(previousDirection) ? false : (previousDirection != currentDirection))

using namespace std;

char initialMap[MAX_DIMENSIONS][MAX_DIMENSIONS], directionMap[MAX_DIMENSIONS][MAX_DIMENSIONS], finalMap[MAX_DIMENSIONS][MAX_DIMENSIONS];
int distanceMap[MAX_DIMENSIONS][MAX_DIMENSIONS];

void findDistance(int x, int y, int r, int c){
	queue<int> q;
	int nx = x, ny = y, a[] = {-1, 0, 1, 0}, b[] = {0, 1, 0, -1};
	char direction[] = {UP_DIRECTION, RIGHT_DIRECTION, DOWN_DIRECTION, LEFT_DIRECTION};
	if(upDirection(initialMap[x][y]))
		nx--;
	if(rightDirection(initialMap[x][y]))
		ny++;
	if(downDirection(initialMap[x][y]))
		nx++;
	if(leftDirection(initialMap[x][y]))
		ny--;
	distanceMap[nx][ny] = 0;
	directionMap[nx][ny] = initialMap[x][y];
	q.push(nx);
	q.push(ny);
	while(!q.empty()){
		nx = q.front();
		q.pop();
		ny = q.front();
		q.pop();
		char previousDirection = directionMap[nx][ny];
		for(int i=0;i<4;i++){
			int tx = nx + a[i];
			int ty = ny + b[i];
			if(inRange(tx, ty, r, c)){
				char currentDirection = direction[i];
				int comparableDistance = distanceMap[nx][ny];
				if(directionChange(previousDirection, currentDirection))
					comparableDistance++;
				if(distanceMap[tx][ty] > comparableDistance){
					directionMap[tx][ty] = currentDirection;
					distanceMap[tx][ty] = comparableDistance;
					q.push(tx);
					q.push(ty);
				}
			}
		}
	}
}

void display(int r, int c){

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			printf("%c", finalMap[i][j]);
		printf("\n");
	}
}

char getMirror(char previousDirection, char currentDirection){
	switch(previousDirection){
		case UP_DIRECTION:
			switch(currentDirection){
				case RIGHT_DIRECTION:
					return FORWARD_SLASH;
				case LEFT_DIRECTION:
					return BACKWARD_SLASH;
			}
		case RIGHT_DIRECTION:
			switch(currentDirection){
				case UP_DIRECTION:
					return FORWARD_SLASH;
				case DOWN_DIRECTION:
					return BACKWARD_SLASH;
			}
		case DOWN_DIRECTION:
			switch(currentDirection){
				case RIGHT_DIRECTION:
					return BACKWARD_SLASH;
				case LEFT_DIRECTION:
					return FORWARD_SLASH;
			}
		case LEFT_DIRECTION:
			switch(currentDirection){
				case UP_DIRECTION:
					return BACKWARD_SLASH;
				case DOWN_DIRECTION:
					return FORWARD_SLASH;
			}
		default:
			return NO_DIRECTION;
	}
}

int getNextX(int x, char direction){
	if(direction == UP_DIRECTION)
		return x + 1;
	if(direction == DOWN_DIRECTION)
		return x - 1;
	return x;
}

int getNextY(int y, char direction){
	if(direction == LEFT_DIRECTION)
		return y + 1;
	if(direction == RIGHT_DIRECTION)
		return y - 1;
	return y;
}

void findMinimumMirrorConfiguration(int x, int y, int r, int c, int sx, int sy){
	queue<int> q;
	q.push(x);
	q.push(y);
	while(!q.empty()){
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		if(x == sx && y == sy)
			return;
		int nx = getNextX(x, directionMap[x][y]);
		int ny = getNextY(y, directionMap[x][y]);
		if(distanceMap[x][y] != distanceMap[nx][ny])
			finalMap[nx][ny] = getMirror(directionMap[nx][ny], directionMap[x][y]);
		q.push(nx);
		q.push(ny);
	}
}

int main(){

	int t, r, c, startX, startY, endX, endY;
	char ch;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &r, &c);
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				scanf("%c", &initialMap[i][j]);
				while(!validCharacter(initialMap[i][j]))
					scanf("%c", &initialMap[i][j]);
				finalMap[i][j] = initialMap[i][j];
				directionMap[i][j] = '-';
				if(directionCharacter(initialMap[i][j])){
					startX = i;
					startY = j;
					distanceMap[i][j] = 0;
					directionMap[i][j] = initialMap[i][j];
				} else if(terminateCharacter(initialMap[i][j])){
					endX = i;
					endY = j;
					distanceMap[i][j] = INF;
				} else if(blockedCharacter(initialMap[i][j])) {
					distanceMap[i][j] = NEG_INF;
				} else {
					distanceMap[i][j] = INF;
				}
			}
		}
		findDistance(startX, startY, r, c);
		findMinimumMirrorConfiguration(endX, endY, r, c, startX, startY);
		display(r, c);
		printf("\n");
	}
	return 0;
}