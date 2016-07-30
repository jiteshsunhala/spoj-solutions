#include <iostream>
#include <cstdio>
#define LLU unsigned long long int

using namespace std;

LLU fibo[90];

LLU findResult(string s){
	int len = s.length();
	LLU result = 0;
	for(int i=0;i<s.length();i++){
		if(s[i] == '1')
			result += fibo[len - i - 1];
	}
	return result;
}

void preCalculate(){
	fibo[0] = 1;
	fibo[1] = 2;
	for(int i=2;i<90;i++){
		fibo[i] = fibo[i-1] + fibo[i-2];
		//printf("%llu\n", fibo[i]);
	}
}

int main(){

	preCalculate();
	int t, test = 1;
	string s;
	scanf("%d", &t);
	while(t--){
		cin >> s;
		printf("Case %d: %llu\n", test++, findResult(s));
	}
	return 0;
}