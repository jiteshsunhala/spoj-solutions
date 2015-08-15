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
#define in_range(x, y) (x >= 0 && x < 8 && y >= 0 && y < 8)

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int dis[8][8];

vector<int> coordinates(string s){
	vector<int> v(2);
	v[0] = '8' - s[1];
	v[1] = s[0] - 97;
	return v;
}

void init(vector<int> s){
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			dis[i][j] = INF;
	dis[s[0]][s[1]] = 0;
}

int findShortestPath(vector<int> s, vector<int> d){
	init(s);
	queue< vector<int> > q;
	vector<int> m, tmp(2);
	q.push(s);
	while(!q.empty()){
		m = q.front();
		q.pop();
		if(m[0] == d[0] && m[1] == d[1])
			return dis[d[0]][d[1]];
		int a[] = {-2, -1, 1, 2, 2, 1, -1, -2}, b[] = {1, 2, 2, 1, -1, -2, -2, -1};
		for(int i=0;i<8;i++){
			tmp[0] = m[0] + a[i];
			tmp[1] = m[1] + b[i];
			if(in_range(tmp[0], tmp[1]) &&( dis[tmp[0]][tmp[1]] > dis[m[0]][m[1]] + 1)){
				dis[tmp[0]][tmp[1]] = dis[m[0]][m[1]] + 1;
				q.push(tmp);
			}
		}
	}
}

int main(){
	
	int t;
	string s, d;
	scanf("%d", &t);
	while(t--){
		cin >> s >> d;
		printf("%d\n", findShortestPath(coordinates(s), coordinates(d)));
	}
    return 0;
}
