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
#define INF 100000000

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

LLD minimum[100][100], maximum[100][100];

void init(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			minimum[i][j] = INF;
			maximum[i][j] = -INF;
		}
	}
}

int findMin(int start, int k, int end, char c){
	if(c == '*')
		return minimum[start][k] * minimum[k+2][end];
	return minimum[start][k] + minimum[k+2][end];
}

int findMax(int start, int k, int end, char c){
	if(c == '*')
		return maximum[start][k] * maximum[k+2][end];
	return maximum[start][k] + maximum[k+2][end];
}

void findMinAndMaxValues(string s){
	int n = s.length();
	init(n);
	for(int i=0;i<n;i+=2)
		minimum[i][i] = maximum[i][i] = s[i] - 48;
	for(int length = 2;length < n;length += 2){
		for(int start = 0;true;start += 2){
			int end = start + length;
			if(end >= n)
				break;
			for(int k=start;k<end;k+=2){
				int minValue = findMin(start, k, end, s[k+1]);
				if(minimum[start][end] > minValue)
					minimum[start][end] = minValue;
				int maxValue = findMax(start, k, end, s[k+1]);
				if(maximum[start][end] < maxValue)
					maximum[start][end] = maxValue;
			}
		}
	}
}

int main(){
	
	int t;
	string s;
	scanf("%d", &t);
	while(t--){
		cin >> s;
		findMinAndMaxValues(s);
		printf("%lld %lld\n", maximum[0][s.length() - 1], minimum[0][s.length() - 1]);
	}
    return 0;
}
