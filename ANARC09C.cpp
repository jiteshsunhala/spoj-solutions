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
#define size 1000001
typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

char primes[size];
int dis, ord;

int find_prime()
{
    int i,j;
    primes[0]=primes[1]='0';
    for(i=2;i<size;i++)
        primes[i]='1';
    for(i=4;i<size;i+=2)
        primes[i]='0';
    for(i=3;i<=sqrt(size);i+=2)
        if(primes[i]=='1')
            for(j=i*3;j<size;j+=(i*2))
                primes[j]='0';
    return 0;
}

void find_factors(int a, int b){
	
	int cnt1 = 0, cnt2 = 0;
	while(a % 2 == 0){
		cnt1++;
		a >>= 1;
	}
	
	while(b % 2 == 0){
		cnt2++;
		b >>= 1;
	}
	
	if(cnt1 || cnt2){
		ord++;
		dis += (abs(cnt1 - cnt2));
	}
	
	for(int i=3;true;i+=2){
		if(a == 1 && b==1)
			break;
		if(primes[i] == '1'){
			cnt1 = cnt2 = 0;
			while(a % i == 0){
				cnt1++;
				a /= i;
			}
			
			while(b % i == 0){
				cnt2++;
				b /= i;
			}
			
			if(cnt1 || cnt2){
				ord++;
				dis += (abs(cnt1 - cnt2));
			}
		}
	}
}

void display(int f[10000], int l){
	for(int i=0;i<l;i++)
		cout << f[i] << " ";
	cout << endl;
}

int main(){
	
	int l1, l2, a, b, c=1;
	find_prime();
	while(true){
		scanf("%d%d", &a, &b);
		if(a == 0)
			break;
			
		dis = ord = 0;
		find_factors(a, b);
		//display(f1, l1);
		//display(f2, l2);
		
		printf("%d. %d:%d\n", c++, ord, dis);
	}
	
    system("pause");
    return 0;
}
