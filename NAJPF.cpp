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

void kmp(string text, string pattern){
	vector<int> lsp = prepareLPSArray(pattern);
	vector<int> result(1);
	result[0] = 0;
	int idx, j = 0, len = pattern.length();
	for(idx=0;idx<text.length();){
		if(pattern[j] == text[idx]){
			j++;
			idx++;
		}
		else{
			if(j == 0){
				idx++;
			}
			else
				j = lsp[j-1];
		}
		if(j == len){
			j = lsp[j-1];
			//cout << idx - len << endl;
			result[0]++;
			result.push_back(idx - len + 1);
		}
	}
	if(j == len){
		j = lsp[j-1];
		//cout << idx - len << endl;
		result[0]++;
		result.push_back(idx - len + 1);
	}
	if(result[0] == 0){
		printf("Not Found\n");
		return;
	}
	printf("%d\n", result[0]);
	for(int i=1;i<result.size();i++)
		printf("%d ", result[i]);
	printf("\n");
}

int main(){
	
	int n, t;
	char c;
	string pattern, text;
	scanf("%d", &t);
	while(t--){
		cin >> text >> pattern;
		kmp(text, pattern);
		printf("\n");
	}
    return 0;
}
