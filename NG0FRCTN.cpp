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

vector<LLD> find_value(LLD n){
	
	vector<LLD> res;
	res.resize(2);
	
	if(n == 1){
		res[0] = 1;
		res[1] = 1;
		return res;
	}
	
	res = find_value(n >> 1);
	
	//	check for left child
	if(n == ((n >> 1) << 1))
		res[1] += res[0];
	else
		res[0] += res[1];
	return res;
}

int main(){
	
	LLD n;
	vector<LLD> res;
	res.resize(2);
	while(true){
		scanf("%lld", &n);
		if(!n)
			break;
		res = find_value(n);
		printf("%lld/%lld\n", res[0], res[1]);
	}
    return 0;
}
