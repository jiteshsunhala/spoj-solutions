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

int find_min(int x, int y)
{
    if(x<=y)
        return x;
    else
        return y;
}

int main()
{
    int i,t=0,min,a[100000][3],n;
    while(1)
    {
        scanf("%d",&n);
        if(!n)
            break;
        t++;
        scanf("%d%d%d",&a[0][0],&a[0][1],&a[0][2]);
        a[0][2]+=a[0][1];
        scanf("%d%d%d",&a[1][0],&a[1][1],&a[1][2]);
        a[1][0]+=a[0][1];
        min=find_min(find_min(a[0][1],a[0][2]),a[1][0]);
        a[1][1]+=min;
        min=find_min(find_min(a[0][1],a[0][2]),a[1][1]);
        a[1][2]+=min;
        for(i=2;i<n;i++)
        {
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
            min=find_min(a[i-1][0],a[i-1][1]);
            a[i][0]+=min;
            min=find_min(find_min(find_min(a[i][0],a[i-1][0]),a[i-1][1]),a[i-1][2]);
            a[i][1]+=min;
            min=find_min(find_min(a[i][1],a[i-1][1]),a[i-1][2]);
            a[i][2]+=min;
        }
        printf("%d. %d\n",t,a[n-1][1]);
    }
    return 0;
}
