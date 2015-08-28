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

string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

bool leap(int y){
	if(y % 400 == 0)
		return true;
	if(y % 100 == 0)
		return false;
	return (y % 4 == 0);
}

int matchYear(int y){
	int increment = 0;
	for(int i=2012;i<y;i++){
		increment++;
		if(leap(i))
			increment++;
	}
	return increment;
}

int findNumOfDays(int m, int y){
	switch(m){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 3;
		case 4:
		case 6:
		case 9:
		case 11:
			return 2;
		default:
			return ((leap(y)) ? 1 : 0);
	}
}

int matchMonth(int m, int y){
	int increment = 0;
	for(int i=1;i<m;i++){
		increment += findNumOfDays(i, y);
	}
	return increment;
}

int matchDate(int d){
	return (d - 1);
}

string findDay(int d, int m, int y){
	int increment = matchYear(y);
	increment += matchMonth(m, y);
	increment += matchDate(d);
	increment %= 7;
	return days[increment];
}

int main(){
	
	int t, date, month, year;
	string day;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &date, &month, &year);
		day = findDay(date, month, year);
		printf("%s\n", day.c_str());
	}
    return 0;
}
