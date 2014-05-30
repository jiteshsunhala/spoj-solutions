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

int permut[13][100];

void init(){
	for(int i=0;i<13;i++)
		for(int j=0;j<100;j++)
			permut[i][j] = 0;
}

void prepare(){
	permut[1][0] = 1;
	for(int i = 1;i<12;i++){
		for(int j = 0;permut[i][j];j++){
			int val = permut[i][j];
			for(int k = j, cnt = 0;cnt < i+1;k++, cnt++)
				permut[i+1][k] += val;
		}
	}
}

int main(){
	
	init();
	prepare();
	int t, n, k;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		printf("%d\n", permut[n][k]);
	}
    return 0;
}
