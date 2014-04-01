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

int stk[100], top=-1;

int rev(int r)
{
    while(r){
        top++;
        stk[top]=r%10;
        r/=10;
    }
    return 0;
}


int main()
{
    char a[10][4] = {"063","010","093","079","106","103","119","011","127","107"};
    char one[100],w[4];
    int f,s,i,j,r;
    while(1)
    {
        scanf("%s",one);
        if(strcmp(one, "BYE")==0)
            break;
        f=s=0;
        for(i=0;one[i]!='+';i+=3)
        {
            w[0]=one[i];
            w[1]=one[i+1];
            w[2]=one[i+2];
            w[3]='\0';
            f*=10;
            for(j=0;j<10;j++)
                if(strcmp(w,a[j])==0)
                {
                    f+=j;
                    break;
                }
        }
        i++;
        while(one[i]!='=')
        {
            w[0]=one[i];
            w[1]=one[i+1];
            w[2]=one[i+2];
            w[3]='\0';
            s*=10;
            for(j=0;j<10;j++)
                if(strcmp(w,a[j])==0)
                {
                    s+=j;
                    break;
                }
            i+=3;
        }
        r=f+s;
        rev(r);
        printf("%s",one);
        if(!r)
            printf("063");
        else{
            while(top != -1){
                printf("%s", a[stk[top]]);
                top--;
            }
        }
        printf("\n");
    }
    return 0;
}
