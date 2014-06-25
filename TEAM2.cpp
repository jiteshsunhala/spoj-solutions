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
	
	LLD a[4], c=1;
	while(scanf("%lld%lld%lld%lld", &a[0], &a[1], &a[2], &a[3])!=EOF){
		sort(a, a + 4);
		printf("Case %lld: %lld\n", c++, a[3] + a[2]);
	}
    return 0;
}
