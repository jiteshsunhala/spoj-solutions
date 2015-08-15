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
	
	string s, t;
	while(true){
		cin >> s >> t;
		if(s == "*" && t == "*")
			break;
		int cnt = 0, n = s.length(), i=0;
		for(;true;){
			if(i >= n)
				break;
			while(i < n && s[i] == t[i])
				i++;
			if(i < n && s[i] != t[i]){
				cnt++;
				while(i < n && s[i] != t[i])
					i++;
			}
		}
		printf("%d\n", cnt);
	}
    return 0;
}
