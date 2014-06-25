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

LLD mod_power(LLD a, LLD n, LLD mod){
	LLD y = 1;
	while(n){
		if(n & 1)
			y = (y * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return y;
}

void find_frac(int &frac, int &len, string s){
	unsigned pos = s.find(".");
	if(pos == string::npos){
		frac = 0;
		len = 1;
		return;
	}
	frac = 0;
	len = 0;
	for(int i=pos + 1;i < s.length();i++){
		frac *= 10;
		frac += (s[i] - 48);
		len++;
	}	
}

int main(){
	
	string s;
	int t, frac, len;
	scanf("%d", &t);
	while(t--){
		cin >> s;
		find_frac(frac, len, s);
		if(frac == 0){
			printf("1\n");
			continue;
		}
		int n = mod_power(10, len, 1000000), val = n, i = 2;
		while(val % frac != 0){
			val = n * i;
			i++;
		}
		printf("%d\n", val / frac);
	}
    return 0;
}
