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

int arr[100000];

int main(){
	
	int n;
	scanf("%d", &n);
	scanf("%d", &arr[0]);
	scanf("%d", &arr[1]);
	scanf("%d", &arr[2]);
	int d1 = arr[1] - arr[0];
	int d2 = arr[2] - arr[1];
	int g = __gcd(d1, d2);
	for(int i=3;i<n;i++){
		scanf("%d", &arr[i]);
		d1 = arr[i] - arr[i-1];
		g = __gcd(g, d1);
	}
	int cnt = 0;
	for(int i=1;i<n;i++)
		cnt += (((arr[i] - arr[i-1]) / g) - 1);
	printf("%d", cnt);
    return 0;
}
