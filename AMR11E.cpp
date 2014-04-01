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
        char pr[1001];
        int a[1000];
        int i,j,k,t,n,cnt;
        pr[2]=pr[3]='1';
        for(i=5;i<1001;i+=2)
                pr[i]='1';
        for(i=3;i<=sqrt(1001);i+=2)
                if(pr[i]=='1')
                        for(j=i*3;j<1001;j=j+(i*2))
                                pr[j]='0';
        a[0]=30;a[1]=42;k=2;
        for(i=43;i<=2664;i++)
        {
                cnt=0;
                if(i%2==0)
                        cnt++;
                for(j=3;j<=(i/2);j+=2)
                {
                        if(pr[j]=='1'&&i%j==0)
                                cnt++;
                        if(cnt==3)
                        {
                                a[k++]=i;
                                break;
                        }
                }
        }
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d",&n);
                printf("%d\n",a[n-1]);
        }
        return 0;
}
