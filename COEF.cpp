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

int mat[14][14];

void prepare(){
	mat[0][0] = 1;
	for(int i=1;i<14;i++){
		mat[i][0] = mat[i][i] = 1;
		for(int j=1;j<i;j++)
			mat[i][j] = mat[i-1][j-1] + mat[i-1][j];
	}
}

int main(){
	
	int value, n, k;
	LLD res;
	prepare();
	while(scanf("%d%d", &n, &k) != EOF){
		res = 1;
		for(int i=0;i<k;i++){
			scanf("%d", &value);
			res *= (LLD)(mat[n][value]);
			n -= value;
		}
		printf("%d\n", res);
	}
    return 0;
}
