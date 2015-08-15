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

bool checkIfEmpty(string s){
	int n = s.length();
	stack<int> st;
	for(int i=0;i<n;i++){
		switch(s[i]){
			case '0':
				if(st.empty())
					return false;
				st.push(st.top() + 1);
				if(st.top() == 3){
					st.pop();
					st.pop();
					st.pop();
				}
				break;
			case '1':
				st.push(1);
				break;
		}
	}
	if(!st.empty())
		return false;
	return true;
}

int main(){
	
	int t, cas = 1;
	string s;
	scanf("%d", &t);
	while(t--){
		cin >> s;
		printf("Case %d: %s\n", cas++, (checkIfEmpty(s) ? "yes" : "no"));
	}
    return 0;
}
