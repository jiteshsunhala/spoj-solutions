#include <iostream>
#include <cstdio>

using namespace std;

bool visitedMap[2001][2001];

void set(int x, int y){
	visitedMap[x + 1000][y + 1000] = true;
}

bool isSet(int x, int y){
	return visitedMap[x + 1000][y + 1000];
}

int main(){

	string s;
	int cnt;
	while(true){
		cin >> s;
		if(s == "Q")
			break;
		cnt = 0;
		int currentPosition[2];
		for(int i=0;i<2001;i++)
			for(int j=0;j<2001;j++)
				visitedMap[i][j] = false;
		set(0, 0);
		fill(currentPosition, currentPosition + 2, 0);
		for(int i=0;i<s.length();i++){
			if(s[i] == 'U')
				currentPosition[1]--;
			if(s[i] == 'R')
				currentPosition[0]++;
			if(s[i] == 'D')
				currentPosition[1]++;
			if(s[i] == 'L')
				currentPosition[0]--;
			if(s[i] == 'Q')
				continue;
			if(isSet(currentPosition[0], currentPosition[1])){
				cnt++;
			}
			set(currentPosition[0], currentPosition[1]);
		}
		printf("%d\n", cnt);
	}
	return 0;
}