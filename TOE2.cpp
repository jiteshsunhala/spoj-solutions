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

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

vector<string> board;

bool win(char c){
	
	//	check rows.
	
	for(int i=0;i<3;i++){
		int cnt = 0;
		for(int j=0;j<3;j++){
			if(board[i][j] == c)
				cnt++;
		}
		if(cnt == 3)
			return true;
	}
	
	//	check cols.
	
	for(int j=0;j<3;j++){
		int cnt = 0;
		for(int i=0;i<3;i++){
			if(board[i][j] == c)
				cnt++;
		}
		if(cnt == 3)
			return true;
	}
	
	//	check diagonals.
	
	if(board[0][0] == c && board[1][1] == c && board[2][2] == c)
		return true;
	
	if(board[0][2] == c && board[1][1] == c && board[2][0] == c)
		return true;
	return false;
}

void display(){
	for(int i=0;i<3;i++)
		cout << board[i] << endl;
}

int count(char c){
	int cnt=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(board[i][j] == c)
				cnt++;
	return cnt;
}

void process(string s){
	
	string tmp = "";
	for(int i=0;i<9;i++){
		
		tmp.append(1, s[i]);
		if(tmp.length() == 3){
			board.push_back(tmp);
			tmp = "";
		}
	}
	
}

int main(){
	
	int t;
	bool valid;
	string s;
	while(true){
		
		getline(cin, s);
		if(s == "end")
			break;
		board.clear();
		process(s);
		valid = true;
//		display();
		
		bool winx = win('X');
		bool wino = win('O');
		int cnto = count('O');
		int cntx = count('X');
		
		if(cntx != cnto && cntx != cnto + 1)
			valid = false;
		if(winx && wino)
			valid = false;
		if(winx && (cnto >= cntx))
			valid = false;
		if(wino && (cntx != cnto))
			valid = false;
		if(!wino && !winx && (cntx + cnto != 9))
			valid = false;

		if(valid)
			printf("valid\n");
		else
			printf("invalid\n");
	}
	
    return 0;
}
