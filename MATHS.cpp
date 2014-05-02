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
#define size 1000001
typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

LLD phi[1000001];
int idx;
bool found;

void init_and_calculate_phi(){
	for(int i=1;i<size;i++)
		phi[i] = i-1;
	phi[1] = 1;
	for(int i=2;i<size/2;i++){
		if(phi[i] == i-1)
			for(int j=i*2;j<size;j+=i)
				phi[j] -= phi[j] / i;
	}
	phi[2] = 3;
	for(int i=3;i<size;i++)
		phi[i] += phi[i-1];
}
/*
void count_total_values(){
	cnt[1] = 2;
	for(int i=2;i<1000001;i++)
		cnt[i] += (cnt[i-1] + (LLD)phi(i));
}*/
/*
bool build(int x, int y, int p, int q, int maxden, int maxcnt){
	int a = x + p;
	int b = y + q;
	
	if(b > maxden)
		return false;
	
	if(!found)
		found = build(x, y, a, b, maxden, maxcnt);
	
	idx++;
	if(idx == maxcnt){
		printf("%d/%d ", a, b);
		return true;
	}
	
	if(idx + maxcnt == phi[maxden] + 1){
		printf("%d/%d ", b-a, b);
		return true;
	}
	
	/*
	if(!found)
		found = build(a, b, p, q, maxden, maxcnt);
	return false;
}*/

void find(int n, int m){
	int a = 0, b = 1, c = 1, d = n, k, tc, td;
	bool flag = false;
	if(m > (phi[n] + 1) >> 1){
		m = phi[n] + 1 - m;
		flag = true;
	}
	
	for(int i=3;i<=m;i++){
		k = int((n + b)/d);
		tc = c;
		td = d;
		c = k * c - a;
		d = k * d - b;
        a = tc;
		b = td;
	}
	if(flag)
		printf("%d/%d ", d - c, d);
	else
		printf("%d/%d ", c, d);
}

void find_term(int n, int m){
	if(m == 1){
		printf("0/1 ");
		return;
	}
	if(m == 2){
		printf("1/%d ", n);
		return;
	}
	if(phi[n] < 100000 && m == phi[n]){
		printf("1/1 ");
		return;
	}/*
	if(n >= 19996){
		printf("1/%d ", n - m + 2);
		return;
	}*/
//	idx = 1;
	found = false;
//	build(0, 1, 1, 1, n, m);
	find(n, m);
}

int main(){
	
	int n, m;
	
	init_and_calculate_phi();
	while(true){
		scanf("%d%d", &n, &m);
		if(!n && !m)
			break;
		find_term(n, m);
		printf("%lld\n", phi[n]);
	}
	
    return 0;
}
