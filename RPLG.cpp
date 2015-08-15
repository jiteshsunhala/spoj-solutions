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

bool label(string s){
	return (s[s.length() - 1] == ':');
}

bool gotoStatement(string s){
	if(s.length() < 4)
		return false;
	return (s.find("goto") == 0);
}

string getLabel(string s){
	int i = 4, j = s.length () - 2;
	while(i < s.length() && s[i] == ' ')
		i++;
	string res = "";
	while(i <= j){
		res.append(1, s[i]);
		i++;
	}
	return res;
}

string generateLabel(string s){
	string res = "";
	for(int i=0;i<s.length() - 1;i++)
		res.append(1, s[i]);
	return res;
}

int main(){
	
	map<string, int> mymap;
	int t, n, cnt, cas = 1;
	string s;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		mymap.clear();
		cnt = 0;
		getline(cin, s);
		for(int i=0;i<n;){
			getline(cin, s);
			if(s == "")
				continue;
			s = trim(s);
			if(label(s))
				mymap[generateLabel(s)] = i + 1;
			if(gotoStatement(s)){
				s = getLabel(s);
				cnt += (i - mymap[s]);
			}
			i++;
		}
		printf("Scenario #%d: %d\n", cas++, cnt);
	}
    return 0;
}
