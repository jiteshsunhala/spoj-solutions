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
	
	int r[1235], c[5679], x, y, tmp;
	char ch;
	
	for(int i=1;i<1235;i++)
		r[i] = (i-1) * 5678 + 1;
	
	for(int i=1;i<5679;i++)
		c[i] = i;
	
	while(scanf("%c", &ch) != EOF){
		if(ch == 'R'){
			scanf("%d%d%c", &x, &y, &ch);
			tmp = r[x];
			r[x] = r[y];
			r[y] = tmp;
		}
		else if(ch == 'C'){
			scanf("%d%d%c", &x, &y, &ch);
			tmp = c[x];
			c[x] = c[y];
			c[y] = tmp;
		}
		else if(ch == 'Q'){
			scanf("%d%d%c", &x, &y, &ch);
			printf("%d\n", r[x] + c[y] - 1);
		}
		else if(ch == 'W'){
			scanf("%d%c", &x, &ch);
			int i=1, start_row = ((x-1) / 5678) * 5678 + 1;
			while(r[i++] != start_row);
			printf("%d ", i-1);
			int start_col = x - start_row + 1;
			i=1;
			while(c[i++]!= start_col);
			printf("%d\n", i-1);
		}
	}
    system("pause");
    return 0;
}
