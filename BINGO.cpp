#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#define validCharacter(c) ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
#define isUpper(c) (c >= 65 && c <= 90)

using namespace std;

string trimString(string s){
	int i, j;
	for(i=0;i<s.length() && !validCharacter(s[i]);i++);
	for(j=s.length() - 1;j >= 0 && !validCharacter(s[j]);j--);
	string res = "";
	while(i<=j){
		res.append(1, s[i]);
		i++;
	}
	return res;
}

vector<string> getListOfWords(string line){
	vector<string> v;
	string word = "";
	for(int i=0;i<line.length();i++){
		if(!validCharacter(line[i])){
			if(word.length() > 0)
				v.push_back(word);
			word = "";
		} else {
			word.append(1, line[i]);
		}
	}
	if(word.length() > 0)
		v.push_back(word);
	return v;
}

string toLower(string s){
	for(int i=0;i<s.length();i++)
		if(isUpper(s[i]))
			s[i] = s[i] + 32;
	return s;
}

int main(){
	string line;
	int games = 0, words = 0, totalWords = 0;
	map<string, bool> available;
	while(true){
		getline(cin, line);
		//cout << line << endl;
		if(cin.eof())
			break;
		line = trimString(line);
		//cout << "line: " << line << endl;
		vector<string> wordList = getListOfWords(line);
		string word;
		for(int i=0;i<wordList.size();i++){
			word = wordList[i];
			//cout << "processing: " << word << endl;
			if(word == "BULLSHIT"){
				games++;
				totalWords += words;
				words = 0;
				available.clear();
			} else {
				word = toLower(word);
				if(!available[word]){
					words++;
					available[word] = true;
				}
			}
		}
	}
	int g = __gcd(totalWords, games);
	printf("%d / %d\n", totalWords / g, games / g);
	return 0;
}