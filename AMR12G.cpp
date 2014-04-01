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
    int pos,max,t,n,m,k,a[50],sum,i,j;
    char ch;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%c",&n,&m,&k,&ch);
        sum=0;
        for(i=0;i<n;i++)
        {
            a[i]=0;
            for(j=0;j<m;j++)
            {
                scanf("%c",&ch);
                if(ch=='.')
                    a[i]++;
            }
            scanf("%c",&ch);
        }
        
        for(i=0;i<k;i++)
        {
            max=0;
            for(j=0;j<n;j++)
                if(a[j]>max)
                {
                    pos=j;
                    max=a[j];
                }
                    
            if(max==0)
                a[0]=m;
            else
                a[pos]=m-max;
        }
        
        for(i=0;i<n;i++)
            sum+=(m-a[i]);
        printf("%d\n",sum);
    }
    return 0;
}
