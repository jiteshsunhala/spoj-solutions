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

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

char s[300];

void clock(int &x, int &y, char &dir){
	if(dir == 'r'){
		dir = 'd';
		y -= 10;
	}
	else if(dir == 'd'){
		x -= 10;
		dir = 'l';
	}
	else if(dir == 'l'){
		y += 10;
		dir = 'u';
	}
	else if(dir == 'u'){
		x += 10;
		dir = 'r';
	}
	
	printf("%d %d lineto\n", x, y);
}

void aclock(int &x, int &y, char &dir){
	if(dir == 'r'){
		dir = 'u';
		y += 10;
	}
	else if(dir == 'u'){
		x -= 10;
		dir = 'l';
	}
	else if(dir == 'l'){
		y -= 10;
		dir = 'd';
	}
	else if(dir == 'd'){
		x += 10;
		dir = 'r';
	}
	
	printf("%d %d lineto\n", x, y);
}

int main(){
	
	while(scanf("%s", s) != EOF){
		printf("300 420 moveto\n310 420 lineto\n");
		int x = 310, y = 420;
		char dir = 'r';
		for(int i=0;i<strlen(s);i++){
			if(s[i] == 'A')
				clock(x, y, dir);
			else
				aclock(x, y, dir);
		}
		printf("stroke\nshowpage\n");
	}
    return 0;
}
