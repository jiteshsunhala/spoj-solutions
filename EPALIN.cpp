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
#define SIZE 100005

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int prepareLPSArray(string pattern){
	//cout << pattern << endl;
	int len = pattern.length();
	vector<int> lsp(len);
	lsp[0] = 0;
	for(int j=0, i=1;i<len;i++){
		if(pattern[i] == pattern[j]){
			lsp[i] = j + 1;
			j++;
		}
		else{
			while(true){
				if(j == 0 || pattern[j] == pattern[i])
					break;
				j = lsp[j-1];
			}
			if(pattern[j] == pattern[i]){
				lsp[i] = j + 1;
				j++;
			}
			else
				lsp[i] = 0;
		}
	//	cout << i << " " << lsp[i] << endl;
	}
	return lsp[len - 1];
}

string findPalin(string s){
	string res = s;
	string revS = string(s.rbegin(), s.rend());
	int noOfChars = s.length() - prepareLPSArray(revS + s);
	for(int i=noOfChars - 1;i>=0;i--)
		res.append(1, s[i]);
	return res;
}

int main(){
	
	char str[SIZE];
	while(scanf("%s", str) != EOF){
		string s = str;
		cout << findPalin(s) << endl;
	}
    return 0;
}
