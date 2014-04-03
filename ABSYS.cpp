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

int substring(char *a,char *b)
{
    int i,j=0,k,temp=0;
    if(strlen(a)>strlen(b))
        return 0;
    else
    {
        for(i=0;b[i]!='\0';i++)
        {
            if(b[i]==a[0])
            {
                temp=1;
                for(k=i+1,j=1;a[j]!='\0'&&b[k]!='\0';k++,j++)
                    if(a[j]!=b[k])
                    {
                        temp=0;
                        break;
                    }
            }
            if(temp==1&&a[j]=='\0')
                return 1;
        }
    }
    return 0;
}


int main()
{
    int i,t,n[5],j;
    char a[20];
    scanf("%d",&t);
    while(t--)
    {
        n[0]=n[2]=n[4]=0;
        for(i=0;i<5;i++)
        {
            scanf("%s",a);
            if(strcmp(a,"=")!=0&&strcmp(a,"+")!=0)
            {
                if(!substring("machula",a))
                {
                    n[i]=0;
                    for(j=0;a[j]!='\0';j++)
                    {
                        n[i]*=10;
                        n[i]+=(a[j]-48);
                    }
                }
            }
        }
        if(n[4])
        {
            if(n[2])
                printf("%d + %d = %d\n",n[4]-n[2],n[2],n[4]);
            else
                printf("%d + %d = %d\n",n[0],n[4]-n[0],n[4]);
        }
        else
            printf("%d + %d = %d\n",n[0],n[2],n[0]+n[2]);
    }
    return 0;
}
