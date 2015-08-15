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

string removeLeadingZeros(string s){
	string res = "";
	int i;
	for(i=0;i<s.length() && s[i] == '0';i++);
	while(i<s.length()){
		res.append(1, s[i]);
		i++;
	}
	if(res == "")
		res = "0";
	return res;
}

string subtract(string a, string b){
	stack<int> st;
	string res = "";
	int i = a.length() - 1, j = b.length() - 1;
	while(i >= 0 && j >= 0){
		if(a[i] >= b[j])
			st.push(a[i] - b[j]);
		else{
			int k = i-1;
			while(k >= 0 && a[k] == '0'){
				a[k] = '9';
				k--;
			}
			a[k]--;
			st.push(10 + a[i] - b[j]);
		}
		i--;
		j--;
	}
	while(i >= 0){
		st.push(a[i] - 48);
		i--;
	}
	while(!st.empty()){
		res.append(1, st.top() + 48);
		st.pop();
	}
	return removeLeadingZeros(res);
}

string add(string a, string b){
	stack<int> st;
	string res = "";
	int i = a.length() - 1, j = b.length() - 1, carry = 0, sum;
	while(i >= 0 && j >= 0){
		sum = (a[i] - 48) + (b[j] - 48) + carry;
		st.push(sum % 10);
		carry = sum / 10;
		i--;j--;
	}
	while(i >= 0){
		sum = (a[i] - 48) + carry;
		st.push(sum % 10);
		carry = sum / 10;
		i--;
	}
	while(j >= 0){
		sum = (b[j] - 48) + carry;
		st.push(sum % 10);
		carry = sum / 10;
		j--;
	}
	while(carry){
		st.push(carry % 10);
		carry /= 10;
	}
	while(!st.empty()){
		res.append(1, st.top() + 48);
		st.pop();
	}
	return res;
}

string multiply(string a, int b){
	stack<int> st;
	string res = "";
	int i = a.length() - 1, carry = 0, sum;
	while(i >= 0){
		sum = (b * (a[i] - 48)) + carry;
		carry = sum / 10;
		st.push(sum % 10);
		i--;
	}
	while(carry){
		st.push(carry % 10);
		carry /= 10;
	}
	while(!st.empty()){
		res.append(1, st.top() + 48);
		st.pop();
	}
	return res;
}

int main(){
	
	string b, c, d;
	int t;
	scanf("%d", &t);
	while(t--){
		cin >> b >> c >> d;
		cout << subtract(multiply(c, 2), add(b, d)) << endl;
	}
    return 0;
}
