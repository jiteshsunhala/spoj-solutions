#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool fingerPrint(string s, string t){
	if(t.length() < s.length())
		return false;
	for(int i=s.length() - 1, j = t.length() - 1;i >= 0;i--,j--)
		if(s[i] != t[j])
			return false;
	return true;
}

bool compare(string s, string t){
	for(int i=0,j=0;i<s.length() && j < t.length();i++, j++){
		if(s[i] < t[j])
			return true;
		if(s[i] > t[j])
			return false;
	}
	return (s.length() < t.length());
}

int main(){
	vector<string> v;
	string s, t;
	int test;
	getline(cin, s);
	scanf("%d", &test);
	getline(cin, t);
	while(test--){
		getline(cin, t);
		if(fingerPrint(s, t)){
			v.push_back(t);
		}
	}
	if(v.size() == 0){
		printf("Wrong fingerprints!");
		return 0;
	}
	sort(v.begin(), v.end(), compare);
	cout << v.size() << endl;
	for(int i=0;i<v.size();i++)
		cout << v[i] << endl;
	return 0;
}