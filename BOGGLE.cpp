#include<iostream>
#include<cstdio>
#include<vector>
#include<map>

using namespace std;

vector<string> tokenize(string s, char c){
    vector<string> res;
    string tmp = "";
    for(int i=0;i<s.length();i++){
        if(s[i] == c){
            res.push_back(tmp);
            tmp = "";
        }
        else
            tmp.append(1, s[i]);
    }
    res.push_back(tmp);
    return res;
}

long long int findSize(string word){
    if(word.length() <= 4)
        return 1;
    if(word.length() == 5)
        return 2;
    if(word.length() == 6)
        return 3;
    if(word.length() == 7)
        return 5;
    return 11;
}

int main(){

    int n;
    vector< vector<string> > words;
    map<string, int> mymap;
    long long int result = 0;
    string s;

    scanf("%d", &n);
    words.resize(n);
    getline(cin, s);
    for(int i=0;i<n;i++){
        getline(cin, s);
        words[i] = tokenize(s, ' ');
        for(int j=0;j<words[i].size();j++){
            mymap[words[i][j]]++;
        }
    }
    for(int i=0;i<words.size();i++){
        long long int tmpVal = 0;
        for(int j=0;j<words[i].size();j++){
            if(mymap[words[i][j]] == 1)
                tmpVal += findSize(words[i][j]);
        }
        result = max(tmpVal, result);
    }
    printf("%lld", result);
    return 0;
}
