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

string multiply(string s, int n){
	stack<char> st;
	string tmp = "";
	int l = s.length(), p, c = 0;
	for(int i=l-1;i >= 0;i--){
		p = ((s[i] - 48) * n) + c;
		st.push((p % 10) + 48);
		c = p / 10;
	}
	while(c){
		st.push((c % 10) + 48);
		c /= 10;
	}
	while(!st.empty()){
		tmp.append(1, st.top());
		st.pop();
	}
	return tmp;
}

string filter(string s){
	int i;
	string res = "";
	for(i=0;i < s.length() && s[i] == '0';i++);
	for(int j=i;j<s.length();j++)
		res.append(1, s[j]);
	if(res == "")
		return "0";
	return res;
}

string difference(string s, string t){
	string res = "";
	stack<char> st;
	int l = t.length() - 1, k = s.length() - 1;
	while(l >= 0){
		if(s[k] >= t[l])
			st.push(s[k] - t[l] + 48);
		else{
			int j = k-1;
			while(j >= 0 && s[j] == '0'){
				s[j] = '9';
				j--;
			}
			s[j]--;
			st.push(s[k] - t[l] + 58);
		}
		k--;
		l--;
	}
	while(k >= 0){
		st.push(s[k]);
		k--;
	}
	while(!st.empty()){
		res.append(1, st.top());
		st.pop();
	}
	return filter(res);
}

bool greater_than(string s, string t){
	if(s.length() < t.length())
		return false;
	if(s.length() > t.length())
		return true;
	int i=0;
	while(i < s.length() && s[i] == t[i])
		i++;
	if(i == s.length())
		return false;
	if(s[i] > t[i])
		return true;
	return false;
}

char solve(string &divisor, string &tmp){
	divisor.append(1, '0');
	string prod, prevprod = "0";
	int len = divisor.length();
	for(int i=1;i<10;i++){
		divisor[len - 1] = i + 48;
		string prod = multiply(divisor, i);
		if(greater_than(prod, tmp)){
			divisor[len - 1] = i + 47;
			tmp = difference(tmp, prevprod);
			return i + 47;
		}
		prevprod = prod;
	}
	tmp = difference(tmp, prevprod);
	return '9';
}

string addition(string s, char c){
	int l = s.length() - 1;
	stack<char> st;
	string res = "";
	int tot, carry = 0;
	tot = (s[l] - 48) + (c - 48);
	st.push((tot % 10) + 48);
	carry = tot / 10;
	l--;
	while(l >= 0){
		tot = (s[l] - 48) + carry;
		carry = tot/10;
		st.push((tot % 10) + 48);
		l--;
	}
	while(carry){
		st.push((carry % 10) + 48);
		carry /= 10;
	}
	while(!st.empty()){
		res.append(1, st.top());
		st.pop();
	}
	return filter(res);
}

string sqrroot(string s){
	
	string res = "", divisor = "", tmp = "";
	int i = 0;
	if(s.length() % 2 == 1){
		tmp.append(1, s[0]);
		char c = solve(divisor, tmp);
		divisor = addition(divisor, c);
		res.append(1, c);
		i=1;
	}	
	for(;i<s.length();i+=2){
		tmp.append(1, s[i]);
		tmp.append(1, s[i+1]);
		tmp = filter(tmp);
		char c = solve(divisor, tmp);
		divisor = addition(divisor, c);
		res.append(1, c);
	}
	return res;
}

int main(){
	
	string s;
	int t;
	scanf("%d", &t);
	while(t--){
		cin >> s;
		string res = sqrroot(s);
		printf("%s\n", res.data());
	}
    return 0;
}
