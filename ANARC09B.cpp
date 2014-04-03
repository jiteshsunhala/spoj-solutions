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

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

LLD gcd(LLD a, LLD b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}

LLD mylcm(LLD a, LLD b){
	return (a * b) / gcd(a, b);
}

int main(){
	
	LLD lcm, a, b, res;
	while(true){
		scanf("%lld%lld", &a, &b);
		if(!a && !b)
			break;
		if(a%b == 0)
			printf("%lld\n", a/b);
		else if(b%a == 0)
			printf("%lld\n", b/a);
		else
			printf("%lld\n", mylcm(a, b));
	}
    return 0;
}
