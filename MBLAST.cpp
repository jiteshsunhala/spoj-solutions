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
#define size 2002

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int dis[size + 1][size + 1];

int main(){
	
	char a[size + 1], b[size + 1];
	int k;
	scanf("%s%s%d", a, b, &k);
	int l1 = strlen(a);
	int l2 = strlen(b);
	for(int i=1;i<=l1;i++)
		dis[i][0] = k * i;
	for(int j=1;j<=l2;j++)
		dis[0][j] = k * j;
	for(int i=1;i<=l1;i++)
		for(int j=1;j<=l2;j++)
			dis[i][j] = min(k + dis[i-1][j], min(k + dis[i][j-1], dis[i-1][j-1] + abs(a[i-1] - b[j-1])));
	printf("%d", dis[l1][l2]);
    return 0;
}
