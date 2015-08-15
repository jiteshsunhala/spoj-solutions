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
	LLD val, total = 0;
	multiset<LLD> myMultiSet;
	multiset<LLD>::iterator it;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%lld", &val);
			myMultiSet.insert(val);
		}		
		it = myMultiSet.begin();
		int small = *it;
		myMultiSet.erase(it);
		it = (--myMultiSet.end());
		int large = *it;
		myMultiSet.erase(it);
//		cout << small << " " << large << endl;
		total += (large - small);
//		cout << total << endl;
	}
	printf("%lld", total);
    return 0;
}
