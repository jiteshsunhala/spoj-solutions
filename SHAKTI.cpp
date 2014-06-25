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
	
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%s\n", ((n % 2 == 0) ? "Thankyou Shaktiman" : "Sorry Shaktiman"));
	}
    return 0;
}
