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
#define SIZE 100000

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int main(){
	
	int seller, buyer, n, arr[SIZE];
	LLD res;
	while(true){
		scanf("%d", &n);
		if(n == 0)
			break;
		res = 0;
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		buyer = 0;
		while(buyer < n && arr[buyer] <= 0)
			buyer++;
		seller = 0;
		while(seller < n && arr[seller] >= 0)
			seller++;
		while(buyer < n && seller < n){
			arr[seller] *= -1;
			int items = min(arr[buyer], arr[seller]);
			res += ((items) * abs(buyer - seller));
			arr[buyer] -= items;
			arr[seller] -= items;
			arr[seller] *= -1;
			while(buyer < n && arr[buyer] <= 0)
				buyer++;
			while(seller < n && arr[seller] >= 0)
				seller++;
		}
		printf("%lld\n", res);
	}
    return 0;
}
