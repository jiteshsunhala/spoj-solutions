#include <iostream>
#include <cstdio>
#define inRange(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)

using namespace std;

int main(){
	string s[10];
	int r, c, a[] = {-1, 0, 1, 0}, b[] = {0, 1, 0, -1};
	scanf("%d%d", &r, &c);
	for(int i=0;i<r;i++)
		cin >> s[i];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(s[i][j] == 'X'){
				int cnt = 0;
				for(int k=0;k<4;k++){
					int tmpX = i + a[k];
					int tmpY = j + b[k];
					if(inRange(tmpX, tmpY, r, c)){
						if(s[tmpX][tmpY] == '.')
							cnt++;
					}
					else{
						cnt++;
					}
				}
				if(cnt >= 3)
					s[i][j] = 'w';
			}
		}
	}
/*
	for(int i=0;i<r;i++)
		cout << s[i] << endl;*/

	int startRow = 50, endRow = -1, startCol = 50, endCol = -1;

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(s[i][j] == 'X'){
				startRow = min(startRow, i);
				endRow = max(endRow, i);
				startCol = min(startCol, j);
				endCol = max(endCol, j);
			}
		}
	}

	//cout << startRow << " " << endRow << endl << startCol << " " << endCol << endl;

	for(int i=startRow;i<=endRow;i++){
		for(int j=startCol;j<=endCol;j++){
			if(s[i][j] == 'w')
				s[i][j] = '.';
			cout << s[i][j];
		}
		cout << endl;
	}

	return 0;
}