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

int main(){
	
	LLD n;
	int t, cas = 1;
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		printf("Case %d: %lld\n", cas++, -1 + (LLD)(sqrt(n+1)));
	}
    return 0;
}
