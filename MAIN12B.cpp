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

#define VI vector<int>
#define VF vector<float>
#define VD vector<double>
#define VC vector<char>
#define VVI vector<VI>
#define VVF vector<VF>
#define VVD vector<VD>
#define VVC vector<VC>
#define SI set<int>
#define SF set<float>
#define SD set<double>
#define SC set<char>
#define SSI set<SI>
#define SSF set<SF>
#define SSD set<SD>
#define SSC set<SC>
#define STI stack<int>
#define STF stack<float>
#define STD stack<double>
#define STC stack<char>
#define STSTI stack<STI>
#define STSTF stack<STF>
#define STSTD stack<STD>
#define STSTC stack<STC>
#define SIZE 1000001

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

char primes[SIZE];
//set<LLD> myset;
map<LLD, int> myset;

int find_prime(){
    int i,j;
    primes[0]=primes[1]='0';
    for(i=2;i<SIZE;i++)
        primes[i]='1';
    for(i=4;i<SIZE;i+=2)
        primes[i]='0';
    for(i=3;i<=(int)sqrt(SIZE);i+=2)
        if(primes[i]=='1')
            for(j=i*3;j<SIZE;j+=(i*2))
                primes[j]='0';
    return 0;
}

void process(LLD val){
	
	LLD tmpval = val;
	bool div = false;
	
	while(tmpval % 2 == 0){
		div = true;
		tmpval >>= 1;
	}
	
	if(div)
//		myset.insert(2);
		myset[2] = 1;
	
	int root = (int)sqrt(val);
	
	for(LLD i=3;i<=root && tmpval > 1;i+=2){
		div = false;
		while(primes[i] == '1' && tmpval % i == 0){
			div = true;
			tmpval /= i;
		}
		if(div)
//			myset.insert(i);
			myset[i] = 1;
	}
	if(tmpval != 1)
//		myset.insert(tmpval);
		myset[tmpval] = 1;
}

int main(){
	
	find_prime();
	int test = 1, t, n;
	LLD val;
//	set<LLD>::iterator it;
	map<LLD, int>::iterator it;
	scanf("%d", &t);
	while(t--){
		myset.clear();
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%lld", &val);
			process(val);
		}
		int total = myset.size();
		printf("Case #%d: %d\n", test++, total);
		for(it = myset.begin();it != myset.end();it++)
			cout << it->first << "\n";
	}
	
    return 0;
}
