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

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int main(){
	
	LLD n;
	int t, case_no = 1;
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		LLD root = (LLD)sqrt(n);
		printf("Case %d: ", case_no++);
		if(root * root == n)
			printf("Yes\n");
		else
			printf("No\n");
	}
    return 0;
}
