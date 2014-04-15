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

int main(){
	
	int t, n, r, in[1000], out[1000], x, y, case_no = 0;
	scanf("%d", &t);
	bool flag;
	
	while(t--){
		scanf("%d%d", &n, &r);
		case_no++;
		flag = true;
		fill(in, in + n, 0);
		fill(out, out + n, 0);
		
		while(r--){
			scanf("%d%d", &x, &y);
			out[x]++;
			in[y]++;
		}
		
		for(int i=0;i<n;i++)
			if(out[i] && in[i]){
				flag = false;
				break;
			}
		printf("Scenario #%d: ", case_no);
		if(flag)
			printf("spying\n");
		else
			printf("spied\n");
	}
    return 0;
}
