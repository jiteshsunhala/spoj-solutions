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

#define VI vector<int>
#define VF vector<float>
#define VD vector<double>
#define VC vector<char>
#define VVI vector<VI>
#define VVF vector<VF>
#define VVD vector<VD>
#define VVC vector<VC>
#define SI set<int>
#define SF set<float>
#define SD set<double>
#define SC set<char>
#define SSI set<SI>
#define SSF set<SF>
#define SSD set<SD>
#define SSC set<SC>
#define STI stack<int>
#define STF stack<float>
#define STD stack<double>
#define STC stack<char>
#define STSTI stack<STI>
#define STSTF stack<STF>
#define STSTD stack<STD>
#define STSTC stack<STC>

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

string elem;
int char_a[26], char_b[26];

void init(int vec[26]){
	for(int i=0;i<26;i++)
		vec[i] = 0;
}

bool is_caps(char c){
	return (c >= 65 && c <= 90);
}

bool is_lower(char c){
	return (c >= 97 && c <= 122);
}

void find_vec(string p, int a[26]){
	for(int i=0;i<p.length();i++){
		if(is_caps(p[i]))
			a[p[i] - 65]++;
		else if(is_lower(p[i]))
			a[p[i] - 97]++;
	}
}

void find_difference(){
	for(int i=0;i<26;i++)
		if(char_a[i] >= char_b[i])
			char_a[i] -= char_b[i];
		else
			char_a[i] = char_b[i] - char_a[i];
}

void display(int a[26]){
	for(int i=0;i<26;i++)
		cout << a[i] << " ";
	cout << endl;
}

bool is_anagram(string p, string q){
	init(char_a);
	init(char_b);
	find_vec(p, char_a);
	find_vec(q, char_b);
/*	display(char_a);
	display(char_b);*/
	find_difference();
//	display(char_a);
	for(int i=0;i<26;i++)
		if(char_a[i])
			return false;
	return true;
}

bool find_elements(){
	
	//		check if palindrome can be formed.....
	int odds = 0;
	for(int i=0;i<26;i++)
		if(char_a[i] % 2)
			odds++;
	if(odds > 1)
		return false;
	else if(odds == 1){
		//		prepare odd length palindrome.....
		int idx;
		elem = "";
		for(int i=0;i<26;i++){
			if(char_a[i] % 2 == 1)
				idx = i;
			for(int j=0;j<char_a[i] / 2;j++)
				elem.append(1, (char)(i + 97));
		}
		elem.append(1, (char)(idx + 97));
		for(int i=25;i>=0;i--){
			for(int j=0;j<char_a[i] / 2;j++)
				elem.append(1, (char)(i + 97));
		}
		return true;
	}
	else if(odds == 0){
		//		prepare odd length palindrome.....
		elem = "";
		for(int i=0;i<26;i++){
			for(int j=0;j<char_a[i] / 2;j++)
				elem.append(1, (char)(i + 97));
		}
		for(int i=25;i>=0;i--){
			for(int j=0;j<char_a[i] / 2;j++)
				elem.append(1, (char)(i + 97));
		}
		return true;
	}
}

int main(){
	
	string p, q;
	int t;
	scanf("%d", &t);
	getline(cin, p);
	while(t--){
		getline(cin, p);
		getline(cin, q);
		if(is_anagram(p, q))
			printf("YES");
		else{
			if(find_elements()){
				string tp, tq;
				tp = p;
				tq = q;
				tp.append(elem);
				tq.append(elem);
				if(is_anagram(tp, q) || is_anagram(tq, p))
					cout << elem;
				else
					printf("NO LUCK");
			}
			else
				printf("NO LUCK");
		}
		printf("\n");
	}
    system("pause");
    return 0;
}
