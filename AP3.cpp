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
    double l,r,f,x,y,s,dis,n1,n2;
    int t;
    LLD a,d,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf",&x,&y,&s);
        dis=pow((2*s+7*x+5*y),2)-(4*(x+y)*12*s);
        dis=sqrt(dis);
        n1=(2*s+7*x+5*y)+dis;
        n2=(2*s+7*x+5*y)-dis;
        n1/=(2*(x+y));
        n2/=(2*(x+y));
        if(floor(n1)==n1&&n1>0)
            n=(LLD)n1;
        else
            n=(LLD)n2;
        d=(LLD)(y-x)/(n-6);
        a=(LLD)x-2*d;
        printf("%lld\n",n);
        while(n--)
        {
            printf("%lld ",a);
            a+=d;
        }
        printf("\n");
    }
    return 0;
}
