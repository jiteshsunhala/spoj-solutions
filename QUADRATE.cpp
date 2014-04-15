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

float find_a(string s){
	float val = 0;
	int i=0;
	while(s[i] >= 48 && s[i] <= 57){
		val *= 10;
		val += (float)(s[i] - 48);
		i++;
	}
	if(val == 0)
		return 1;
	return val;
}

float find_b(string s){
	int i=0;
	bool neg = false;
	while(i < s.length() && s[i] != '+' && s[i] != '-')
		i++;
	if(i == s.length())
		return 0;
	i++;
	int j = i;
	while(j < s.length() && s[j] != 'x')
		j++;
	if(j == s.length())
		return 0;
	float val = 0;
	if(s[i-1] == '-')
		neg = true;
	while(s[i] >= 48 && s[i] <= 57){
		val *= 10;
		val += (float)(s[i] - 48);
		i++;
	}
	if(neg)
		val *= (-1);
	return val;
}

float find_c(string s){
	bool neg = false;
	int i = s.length() - 1;
	while(i >= 0 && s[i] != '=')
		i--;
	int j = i-1;
	while(j >= 0 && s[j] == ' ')
		j--;
	if(s[j] == 'x')
		return 0;
	j = i-1;
	while(j >= 0 && s[j] != '+' && s[j] != '-')
		j--;
	if(s[j] == '-')
		neg = true;
	j++;
	float val = 0;
	while(s[j] >= 48 && s[j] <= 57){
		val *= 10;
		val += (float)(s[j] - 48);
		j++;
	}
	if(neg)
		val *= -1;
	return val;
}

int main(){
	
	int t;
	float a, b, c;
	string s;
	scanf("%d", &t);
	getline(cin, s);
	while(t--){
		getline(cin, s);
		a = find_a(s);
		//cout << a << endl;
		b = find_b(s);
		//cout << b << endl;
		c = find_c(s);
		//cout << c << endl;
		float d = b * b - 4 * a * c;
		if(d < 0)
			printf("Imaginary roots.\n");
		else if(d == 0)
			printf("Equal roots.\n");
		else
			printf("Distinct real roots.\n");
	}
    return 0;
}
