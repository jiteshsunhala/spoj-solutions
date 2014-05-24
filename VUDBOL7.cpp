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

vector<int> fibo;

void update(){
	fibo.resize(40);
	fibo[0] = 0;
	fibo[1] = 1;
	fibo[2] = 2;
	for(int i=3;i<40;i++)
		fibo[i] = fibo[i-1] + fibo[i-2];
}

int SCANF(){
	int n=0;
	char ch;
	while(true){
		ch = getc(stdin);
		if(ch >= 48 && ch <= 57)
			break;
	}
	n = ch-48;
	while(true){
		ch = getc(stdin);
		if(ch < 48 || ch > 57)
			break;
		n *= 10;
		n += (ch - 48);
	}
	return n;
}

int findval(int v){
	vector<int>::iterator pos = lower_bound(fibo.begin(), fibo.end(), v);
	int idx = pos - fibo.begin();
	if(abs(fibo[idx-1] - v) < abs(fibo[idx] - v))
		return fibo[idx-1];
	else
		return fibo[idx];
}

int main(){
	
	update();
	int n, a[100000];
	while(true){
		n = SCANF();
		if(n == 0)
			break;
		for(int i=0;i<n;i++){
			a[i] = SCANF();
			a[i] = findval(a[i]);
		}
		sort(a, a+n);
		for(int i=0;i<n;i++)
			printf("%d ", a[i]);
		printf("\n");
	}
		
    return 0;
}
