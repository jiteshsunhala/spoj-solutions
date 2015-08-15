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
	
	int t, n;
	LLD *val;
	string s;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		val = new LLD[n];
		for(int i=0;i<n;i++){
			cin >> s;
			scanf("%lld", &val[i]);
		}
		sort(val, val + n);
		LLD badness = 0;
		for(int i=0;i<n;i++)
			badness += abs(i - (val[i] - 1));
		printf("%lld\n", badness);
		delete(val);
	}
    return 0;
}
