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
        unsigned long long int a,d,n,a3,al3,s;
        int t;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%llu%llu%llu",&a3,&al3,&s);
                n=(s*2)/(a3+al3);
                d=(al3-a3)/(n-5);
                a=a3-(2*d);
                printf("%llu\n",n);
                while(n--)
                {
                        printf("%llu ",a);
                        a+=d;
                }
        }
        return 0;
}
