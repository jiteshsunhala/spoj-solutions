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

int find_depth(string s){
	stack<int> st, vis;
	st.push(0);
	vis.push(0);
	int depth = 0, curdepth;
	for(int i=1;i<s.length();i++){
		curdepth = st.top() + 1;
		int visited = vis.top();
		vis.pop();
		vis.push(visited + 1);
		if(vis.top() == 2){
			st.pop();
			vis.pop();
		}
		if(s[i] == 'n'){
			st.push(curdepth);
			vis.push(0);
		}
		depth = max(depth, curdepth);
	}
	return depth;
}

int main(){
	
	int t;
	string s;
	scanf("%d", &t);
	while(t--){
	cin >> s;
		printf("%d\n", find_depth(s));
	}
    return 0;
}
