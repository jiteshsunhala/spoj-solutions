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
#define SIZE 524288

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int n;
LLD arr[SIZE];

void display(vector<LLD> v){
	for(int i=1;i<v.size();i++)
		cout << v[i] << " ";
	cout << endl;
	system("pause");
}

void update(int n, LLD val){
	for(int i=n;i>0;i-=(i&(-i))){
		arr[i] += val;
	}
}

LLD query(int idx){
	idx = n + 1 - idx;
	LLD total = 0;
	for(int i=idx;i<=n;i+=(i&(-i)))
		total += arr[i];
	return total;
}

int main(){
	LLD val;
	scanf("%d", &n);
//	fill(arr.begin(), arr.end(), 0);
	for(int i=n;i>0;i--){
		scanf("%lld", &val);
		update(i, val);
	}
	int q, option, x, y;
	scanf("%d", &q);
	while(q--){
		scanf("%d", &option);
		if(option == 1){
			scanf("%d%d", &x, &y);
			printf("%lld\n", query(y) - query(x-1));
			continue;
		}
		scanf("%lld", &val);
		n++;
		update(n, val);
		continue;
	}
	//system("pause");
    return 0;
}
