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
	
	string t1, t2;
	int g1, g2, t;
	map<string, int> mymap;
	map<string, int>::iterator it;
	scanf("%d", &t);
	while(t--){
		mymap.clear();
		for(int i=0;i<16;i++){
			cin >> t1 >> t2 >> g1 >> g2;
			if(g1 > g2){
				if(mymap[t1] == 0)
					mymap[t1] = 1;
				else
					mymap[t1]++;
				if(mymap[t2] == 0)
					mymap[t2] = 0;
			}
			else{
				if(mymap[t2] == 0)
					mymap[t2] = 1;
				else
					mymap[t2]++;
				if(mymap[t1] == 0)
					mymap[t1] = 0;
			}
		}
		string res = "";
		int high = 0;
		for(it = mymap.begin();it != mymap.end();it++){
			if(it->second > high){
				res = it->first;
				high = it->second;
			}
		}
		cout << res << endl;
	}
	
    return 0;
}
