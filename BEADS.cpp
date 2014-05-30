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

int main(){
	
	string s, tmp;
	int t;
	scanf("%d", &t);
	while(t--){
		cin >> s;
		tmp = s;
		tmp.append(s);
		string mins = s;
		int mini = 0;
		for(int i=1;i<s.length();i++){
			string tmps = tmp.substr(i, s.length());
			if(tmps < mins){
				mins = tmps;
				mini = i;
			}
		}
		printf("%d\n", mini + 1);
	}
    return 0;
}
