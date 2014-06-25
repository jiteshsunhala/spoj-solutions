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

LLD arr[100001];

void prepare(){
	arr[1] = 2;
	LLD cnt = 4;
	LLD inc = 4;
	for(int i=2;i<=100000;i++){
		arr[i] = arr[i-1] + cnt;
		cnt += inc;
		inc = ((inc == 4) ? 2 : 4);
	}
}

int main(){
	
	int t;
	LLD n, num, den;
	prepare();
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		num = arr[n];
		den = 6 * n * n * n;
		LLD g = __gcd(num, den);
		printf("%lld/%lld\n", num / g, den / g);
	}
	
    return 0;
}
