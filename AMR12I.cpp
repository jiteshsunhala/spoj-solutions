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
    int rep[20000], sum, nxt, n, k, t, i, l, j;
    char col[20000], ch, s[20001];
    
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%s",&n,&k,s);
        l=0;
        col[l]=s[0];
        rep[l]=1;
        for(i=1;i<n;i++)
        {
            if(s[i]==col[l])
                rep[l]++;
            else
            {
                l++;
                col[l]=s[i];
                rep[l]=1;
            }
        }
        nxt=0;
        for(i=0;i<=l;i++)
            if(rep[i]>=k)
            {
                nxt=1;
                break;
            }
            
        if(nxt)
        {
            sum=0;
            for(i=0;i<=l;i++)
                sum+=(int)(ceil((float)rep[i]/(float)k));
            printf("%d\n",sum);
        }
        else
            printf("-1\n");
    }
    return 0;
}
