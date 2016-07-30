#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

string factorial[101];

string multiply(string s, int n){
	string res = "";
	stack<int> st;
	int total, carry = 0;
	for(int i=s.length() - 1;i>=0;i--){
		total = carry + (n * (s[i] - 48));
		st.push(total % 10);
		carry = total / 10;
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

void preCalculate(){
	factorial[1] = "1";
	for(int i=2;i<101;i++)
		factorial[i] = multiply(factorial[i-1], i);
}

int main(){

	preCalculate();
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		cout << factorial[n] << endl;
	}
	return 0;
}