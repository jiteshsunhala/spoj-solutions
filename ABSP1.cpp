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
	
	LLD t, n, arr[10000], res;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld", &n);
		res = 0;
		for(int i=0;i<n;i++)
			scanf("%lld", &arr[i]);
		for(int i=0, j=n-1;i < (n >> 1); i++, j--)
			res += ((j - i) * (arr[j] - arr[i]));
		printf("%lld\n", res);
	}
    return 0;
}
