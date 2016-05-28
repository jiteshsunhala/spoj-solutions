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
#include<vector>
#include<map>
#include<list>
#include<algorithm>
typedef long long int LLD;
#define mymin(x, y) ((x < y) ? (x) : (y))

using namespace std;

int main(){
	
	LLD t, n, r, g, b, cnt;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld%lld%lld%lld", &n, &r, &g, &b);
		cnt = 0;
		for(LLD i=0;i<=r;i++){
			for(LLD j=0;j<=g;j++){
				LLD total = i + j;
				if(total <= n)
//					printf("red candies: %lld, green candies: %lld, blue candies: %lld\n", i, j, (mymin(b, n-total) + 1));
					cnt += (mymin(b, n-total) + 1);
			}
		}
		printf("%lld\n", cnt);
	}
	
//    system("pause");
    return 0;
}

