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

queue< pair<LLD, int> > q;
pair<LLD, int> p;

LLD bfs(int n){
	bool visited[20000];
	fill(visited, visited + n, false);
	LLD res;
	q.push(make_pair(1, 1));
	
	while(!q.empty()){
		p = q.front();
		q.pop();
		visited[p.second] = true;
		if((p.second % n) == 0){
			res = p.first;
			break;
		}
		else{
			LLD tmp1 = p.first;
			tmp1 <<= 1;
			int modulo = (p.second * 10) % n;
			if(!visited[modulo])
				q.push(make_pair(tmp1, modulo));
			LLD tmp2 = p.first;
			tmp2 <<= 1;
			tmp2 |= 1;
			modulo = (p.second * 10 + 1) % n;
			if(!visited[modulo])
				q.push(make_pair(tmp2, modulo));
		}
	}
	
	while(!q.empty())
		q.pop();
	
	return res;
}

void display(LLD n){
	stack<int> s;
	while(n){
		s.push(n % 2);
		n >>= 1;
	}
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
	cout << endl;
}

int main(){
	int t, n;
	
	/*vector<string> res;
	int maxlen = 0;
	for(int i=1;i<=20000;i++){
		if(i == 9999 || i == 19998){
			res.push_back("");
			continue;
		}
		LLD tmp = bfs(i);
		cout << i << " ";
		display(tmp);
		
	}*/
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		LLD result = bfs(n);
		display(result);
	}
	return 0;
}
