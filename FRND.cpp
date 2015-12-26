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
#define SIZE 1000000
#define NO_OF_BITS 20

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int main(){
	
	int n, val;
	LLU bits[NO_OF_BITS];
	fill(bits, bits + NO_OF_BITS, 0);
	scanf("%d", &n);
	if(n == 1){
		scanf("%d", &val);
		printf("%d", val);
		system("pause");
		return 0;
	}
	for(int i=0;i<n;i++){
		scanf("%d", &val);
		for(int i=0;i<NO_OF_BITS;i++){
			bits[i] += ((val & 1) ? 1 : 0);
			val >>= 1;
		}
	}
	LLU totalBits, result = 0, c = 0, s;
	stack<int> st;
	for(int i=0;i<NO_OF_BITS;i++){
		totalBits = bits[i] * (n - bits[i]);
		s = totalBits + c;
		st.push(s % 2);
		c = s >> 1;
	}
	while(c){
		st.push(c % 2);
		c >>= 1;
	}
	while(!st.empty()){
		result <<= 1;
		result |= st.top();
		st.pop();
	}
	printf("%llu", result);
	system("pause");
    return 0;
}
