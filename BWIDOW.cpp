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
#define INF 100000000

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int main(){
	
	int t, n, maxInner, maxInnerIdx;
	vector< vector<int> > v;
	cin >> t;
	while(t--){
		cin >> n;
		v.clear();
		v.resize(n);
		maxInner = -INF;
		maxInnerIdx = -1;
		for(int i=0;i<n;i++){
			v[i].resize(2);
			cin >> v[i][0] >> v[i][1];
			if(v[i][0] > maxInner){
				maxInner = v[i][0];
				maxInnerIdx = i;
			}
		}
		bool flag = true;
		for(int i=0;i<n;i++){
			if(i == maxInnerIdx)
				continue;
			if(maxInner < v[i][1]){
				flag = false;
				break;
			}
		}
		if(flag)
			cout << maxInnerIdx + 1 << endl;
		else
			cout << "-1\n";
	}
    return 0;
}
