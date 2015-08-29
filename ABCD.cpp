#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#include<string>
using namespace std;

char color[] = "ABCD";

string get_string(char a, char b){
	char small = min(a, b), large = max(a, b);
	if(small == 'A' && large == 'B')
		return "CD";
	if(small == 'A' && large == 'C')
		return "BD";
	if(small == 'A' && large == 'D')
		return "BC";
	if(small == 'B' && large == 'C')
		return "AD";
	if(small == 'B' && large == 'D')
		return "AC";
	if(small == 'C' && large == 'D')
		return "AB";
}

string process(string s){
	for(int i=1;i+1<s.length();i+=2){
		if(s[i] == s[i+1])
			swap(s[i+1], s[i+2]);
	}
	return s;
}

int main(){
	
	string first, second;
	int n;
	cin >> n >> first;
	for(int i=0;i < first.length();i+=2)
		second.append(get_string(first[i], first[i+1]));
	cout << process(second);
    return 0;
}
