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

int main()
{
	int n[]={2,4,9,16,25,
			64,289,729,1681,
			2401,3481,4096,
			5041,7921,10201,
			15625,17161,27889,
			28561,29929,65536,
			83521,85849,146689,
			262144,279841,458329,
			491401,531441,552049,
			579121,597529,683929,
			703921,707281,734449,
			829921},a,b,t,cnt,i;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		scanf("%d%d",&a,&b);
		for(i=0;i<37;i++)
		if(n[i]>=a&&n[i]<=b)
			cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}
