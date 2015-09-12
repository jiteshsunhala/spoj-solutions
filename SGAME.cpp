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
	
	int t, arr[301], x, y, start;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &start);
		fill(arr, arr + 301, 0);
		while(true){
			scanf("%d%d", &x, &y);
			if(x == -1 && y == -1)
				break;
			arr[x]++;
			arr[y]++;
		}
		bool yes = true;
		for(int i=1;i<301;i++)
			if(arr[i] % 2 == 1){
				yes = false;
				break;
			}
		printf("%s\n", (yes ? "YES" : "NO"));
	}
    return 0;
}
