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

float det[6][5], cr[6];

string get_token(string s, int &idx){
	while(s[idx] == ' ' && idx < s.length())
		idx++;
	string r = "";
	while(s[idx] != ' ' && idx < s.length()){
		r.append(1, s[idx]);
		idx++;
	}
	return r;
}

void display(){
	for(int i=0;i<6;i++){
		for(int j=0;j<5;j++)
			cout << det[i][j] << " ";
		cout << endl;
	}
	system("pause");
}

void input(){
	
	string s;
	getline(cin, s);
	for(int i=0;i<6;i++){
		int j = 0, idx = 0;
		getline(cin, s);
		//cout << "s: " << s << endl;
		while(idx < s.length()){
			//cout << "idx: " << idx << endl;
			string nxt_token = get_token(s, idx);
			//cout << "nt: " << nxt_token << endl;
			if(nxt_token == "ab")
				det[i][j] = 0;
			else
				det[i][j] = atof(nxt_token.data());
			//cout << "the value" << det[i][j] << endl;
			j++;
		}
		sort(det[i], det[i]+3);
	}
//	display();
}

float find_att_marks(float val){
	if(val < 51)
		return 5;
	if(val < 61)
		return 4;
	if(val < 71)
		return 3;
	if(val < 81)
		return 2;
	if(val < 91)
		return 1;
	return 0;
}

float find_points(float val){
	if(val >= 91)
		return 10;
	if(val >= 81)
		return 9;
	if(val >= 71)
		return 8;
	if(val >= 61)
		return 7;
	if(val > 50)
		return 6;
	if(val == 50)
		return 5;
	return 0;
}

void process(){
	
	float int_marks, ex_marks, tot_points = 0, att_marks, point, tot_marks, cr_sum = 0;
	bool fail = false;
	//		processing internal
	
	for(int i=0;i<6;i++){
		int_marks = (((det[i][1] + det[i][2]) / 40.0) * 45.0);
		ex_marks = det[i][3] / 2;
		att_marks = find_att_marks(det[i][4]);
		tot_marks = int_marks + ex_marks + att_marks;
		point = find_points(tot_marks);
//		cout << point << endl;
		tot_points += (point * cr[i]);
		if(point * cr[i] == 0)
			fail = true;
		cr_sum += cr[i];
	}
	
	if(fail)
		printf("FAILED, ");
	else
		printf("PASSED, ");
	tot_points /= cr_sum;
	printf("%.2f\n", tot_points);
}

int main(){
	
	int n;
	for(scanf("%d", &n);n--;){
		for(int i=0;i<6;i++)
			scanf("%f", &cr[i]);
		input();
		process();
	}
    return 0;
}
