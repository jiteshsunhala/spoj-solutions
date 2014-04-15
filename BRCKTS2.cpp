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

stack<LLD> height, sign, last;

void display(){
	if(!height.empty()){
		cout << "height: " << height.top() << endl;
		cout << "sign: " << sign.top() << endl;
		cout << "last: " << last.top() << endl;
		system("pause");
	}
	else
		cout << "stack empty" << endl;
}

LLD find_area(string s){
	
	LLD area = 0, prev_height, prev_sign, sin;
	
	for(LLD i=0;i<s.length();i++){
		
		//cout << "Executing " << i << " " << s[i] << endl;
		
		if(s[i] == '('){
			
			//	update height...
			
			height.push(1);
			
			//	update sign...
			
			if(!sign.empty())
				sin = sign.top();
			else
				sin = -1;
			sign.push(sin * -1);
			
			//	update last paren...
			last.push(i);
		}
		else{
			
			prev_height = height.top();
			height.pop();
			
			if(!height.empty()){
				LLD tmp_height = height.top();
				height.pop();
				height.push(max(tmp_height, prev_height + 1));
			}
			
			int lidx = last.top();
			last.pop();
			sin = sign.top();
			sign.pop();
			LLD width = i - lidx;
			area += (sin * prev_height * width);
			//cout << "square area: " << (sin * prev_height * width) << endl;
			//cout << "total area: " << area << endl;
			
		}
		
		//display();
		
	}
	
	return area;
	
}

int main(){
	
	int t;
	string s;
	
	scanf("%d", &t);
	while(t--){
		cin >> s;
		printf("%lld\n", find_area(s));
	}
	
    system("pause");
    return 0;
}
