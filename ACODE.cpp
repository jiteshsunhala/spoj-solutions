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
    
    int a[500001], n, num;
    char str[500001];
    while(1){
        scanf("%s", str);
        if(strcmp(str, "0") == 0)
            break;
        a[0] = a[1] = 1;
        n = strlen(str);
        for(int i=1;i<n;i++){
            a[i+1] = 0;
            if(str[i] == '0'){
                num = (str[i-1] - 48) * 10 + (str[i] - 48);
                if(num == 10 || num == 20)
                    a[i+1] = a[i-1];
                else
                    a[i+1] = 0;
            }
            else{
                a[i+1] = a[i];
                num = (str[i-1] - 48) * 10 + (str[i] - 48);
                if(num > 9 && num < 27){
                    a[i+1] += a[i-1];
                }
            }
        }
        printf("%d\n", a[n]);
    }
    return 0;
}
