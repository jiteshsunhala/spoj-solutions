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
#define square(x) (x * x)

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

struct point{
	double x, y;
};

double findDistance(point p1, point p2){
	return sqrt(square((p1.x - p2.x)) + square((p1.y - p2.y)));
}

string trim(string s){
	string res = "";
	int i = 0, j = s.length() - 1;
	while(i < s.length() && s[i] == ' ')
		i++;
	while(j >= 0 && s[j] == ' ')
		j--;
	while(i <= j){
		res.append(1, s[i]);
		i++;
	}
	return res;
}

double findCoordinate(string s){
	s = trim(s);
	return atof(s.c_str());
}

point findPoints(string s){
	int firstParen = s.find('(');
	int comma = s.find(',', firstParen + 1);
	int len = comma - firstParen - 1;
	point p;
	p.x = findCoordinate(s.substr(firstParen + 1, len));
	int lastParen = s.find(')', comma + 1);
	len = lastParen - comma - 1;
	p.y = findCoordinate(s.substr(comma + 1, len));
	return p;
}

int main(){
	
	string s;
	point p1, p2;
	double distance = 0;
	getline(cin, s);
	p1 = findPoints(s);
//	cout << "found point " << p1.x << " " << p1.y << endl;
	getline(cin, s);
	p2 = findPoints(s);
//	cout << "found point " << p2.x << " " << p2.y << endl;
	while(true){
		distance += findDistance(p1, p2);
		printf("The salesman has traveled a total of %.3lf kilometers.\n", distance);
		p1 = p2;
		getline(cin, s);
		if(cin.fail())
			break;
		p2 = findPoints(s);
	}
    return 0;
}
