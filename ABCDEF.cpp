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

LLD n, a[1000000], b[1000000], val[100];
int l1, l2;

void prepare_a(){
	
	int idx = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				a[idx++] = val[i] * val[j] + val[k];
			}
		}
	}
	sort(a, a+idx);
	l1 = idx;
}

void prepare_b(){
	
	int idx = 0;
	for(int i=0;i<n;i++){
		if(val[i] != 0){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					b[idx++] = val[i] * (val[j] + val[k]);
				}
			}
		}
	}
	sort(b, b+idx);
	l2 = idx;
}

LLD count(){
	LLD cnt = 0;
	int i=0, j=0;
	while(i < l1 && j < l2){
		if(a[i] < b[j])
			i++;
		else if(a[i] > b[j])
			j++;
		else{
			int val = a[i];
			LLD tcnt = 0;
			while(a[i] == val){
				tcnt++;
				i++;
			}
			LLD tcnt2 = 0;
			while(b[j] == val){
				tcnt2++;
				j++;
			}
			cnt += (tcnt * tcnt2);
		}
	}
	return cnt;
}

int main(){
	
	scanf("%lld", &n);
	for(int i=0;i<n;i++)
		scanf("%lld", &val[i]);
	prepare_a();
	prepare_b();
	
	printf("%lld", count());
    return 0;
}
