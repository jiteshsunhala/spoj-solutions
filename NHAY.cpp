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

vector<int> prepareLPSArray(string pattern){
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
	}
	/*
	for(int i=0;i<pattern.length();i++)
		cout << lsp[i] << " ";
	cout << endl;*/
	return lsp;
}

bool kmp(string pattern){
	vector<int> lsp = prepareLPSArray(pattern);
	char c;
	int j = 0, len = pattern.length(), idx = 0;
	bool found = false;
	scanf("%c", &c);
	while(true){
		if(pattern[j] == c){
			j++;
			idx++;
			scanf("%c", &c);
			if(c == '\n')
				break;
		}
		else{
			if(j == 0){
				idx++;
				scanf("%c", &c);
				if(c == '\n')
					break;
			}
			else
				j = lsp[j-1];
		}
		if(j == len){
			j = lsp[j-1];
			cout << idx - len << endl;
			found = true;
		}
	}
	if(j == len){
		j = lsp[j-1];
		cout << idx - len << endl;
		found = true;
	}
	return found;
}

int main(){
	
	int n;
	char c;
	string pattern, text;
	while(scanf("%d", &n) != EOF){
		pattern = "";
		scanf("%c", &c);
		while(true){
			scanf("%c", &c);
			if(c == '\n')
				break;
			pattern.append(1, c);
		}
		if(!kmp(pattern))
			cout << endl;
	}
    return 0;
}
