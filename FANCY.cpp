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

char s[40];

int findPossibleValues(int start){
	if(start == strlen(s))
		return 1;
	LLD res = 0;
	for(int len=1;true;len++){
		int end = start + len - 1;
		if(end >= strlen(s))
			break;
		if(s[start] != s[end])
			break;
		res += findPossibleValues(end + 1);
	}
	return res;
}

int main(){
	
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		printf("%d\n", findPossibleValues(0));
	}
    return 0;
}
