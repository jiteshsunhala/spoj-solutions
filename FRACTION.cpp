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
#define SIZE 7600460

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int fnum[SIZE], fden[SIZE], idx;

void build(int x, int y, int p, int q, int maxden){
	int a = x + p;
	int b = y + q;
	
	if(b > maxden)
		return;
	
	build(x, y, a, b, maxden);
	
	fnum[idx] = a;
	fden[idx] = b;
	idx++;
	
	build(a, b, p, q, maxden);
}

int main(){
	
	int t, n, m, x;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		idx = 2;
		fnum[1] = 0;
		fden[1] = 1;
		build(0, 1, 1, 1, n);
		fnum[idx] = 1;
		fden[idx] = 1;
		scanf("%d", &m);
		while(m--){
			scanf("%d", &x);
			printf("%d/%d\n", fnum[x], fden[x]);
		}
	}
	
    return 0;
}
