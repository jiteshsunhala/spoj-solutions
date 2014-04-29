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

#define VI vector<int>
#define VF vector<float>
#define VD vector<double>
#define VC vector<char>
#define VVI vector<VI>
#define VVF vector<VF>
#define VVD vector<VD>
#define VVC vector<VC>
#define SI set<int>
#define SF set<float>
#define SD set<double>
#define SC set<char>
#define SSI set<SI>
#define SSF set<SF>
#define SSD set<SD>
#define SSC set<SC>
#define STI stack<int>
#define STF stack<float>
#define STD stack<double>
#define STC stack<char>
#define STSTI stack<STI>
#define STSTF stack<STF>
#define STSTD stack<STD>
#define STSTC stack<STC>
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int mat[50][50];
bool visited[50][50];

void prepare_mat(int r, int c, string s){
	
	int k = 0;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			mat[i][j] = s[k++] - 48;
}

void init(int r, int c){
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			visited[i][j] = false;
}

void find_next(int &x, int &y, int &dx, int &dy, int r, int c){
	
	if(dx == 0 && dy == 1){
		dx = 1;
		dy = 0;
		x += dx;
		y += dy;
		return;
	}
	
	if(dx == 1 && dy == 0){
		dx = 0;
		dy = -1;
		x += dx;
		y += dy;
		return;
	}
	
	if(dx == 0 && dy == -1){
		dx = -1;
		dy = 0;
		x += dx;
		y += dy;
		return;
	}
	
	if(dx == -1 && dy == 0){
		dx = 0;
		dy = 1;
		x += dx;
		y += dy;
		return;
	}
	
}

string process(int r, int c){
	
	int x = 0, y = 0, val = 0, cnt = 0, dirx = 0, diry = 1;
	string res = "";
	
	init(r, c);
	
	for(int i=0;i<r * c;i++){
		visited[x][y] = true;
		val <<= 1;
		val |= mat[x][y];
		cnt++;
		if(cnt == 5){
			if(val == 0)
				res.append(1, ' ');
			else
				res.append(1, (char)(val + 64));
			val = 0;
			cnt = 0;
		}
		
		if(in_range(x+dirx, y+diry, r, c) && !visited[x+dirx][y+diry]){
			x += dirx;
			y += diry;
		}
		else
			find_next(x, y, dirx, diry, r, c);
		
	}
	
	return res;
}

int main(){
	
	int t, r, c, test = 1;
	string s;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &r, &c);
		cin >> s;
		prepare_mat(r, c, s);
		string res = process(r, c);
		printf("%d %s\n", test++, res.data());
	}	
	return 0;
}
