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

LLD mat[31];

void solve(){
	mat[1] = 3;
	mat[2] = 9;
	for(int j=3;j<31;j++)
		mat[j] = mat[j-2] + 2 * mat[j-1];
}

int main(){
	
	int t, n;
	solve();
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%lld\n", mat[n]);
	}
    return 0;
}
