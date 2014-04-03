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
#include<vector>
#include<fstream>
#include<map>
#include<list>
#include<cmath>
#include<algorithm>
#define size 10000000

typedef long long int LLD;
using namespace std;
LLD arr[size] = {0}, f[size] = {0};

void find_factor(){
	for(LLD i=2;i<size;i++){
		if(f[i] == 0)
			for(LLD j=i;j<size;j+=i)
				if(f[j] == 0)
					f[j] = i;
	}
}

void solve(){
	arr[0] = arr[1] = 0;
	for(int i=2;i<size;i++)
		arr[i] = arr[i-1] + f[i];
}

void init(){
	for(int i=0;i<size;i++)
		f[i] = 0;
}

void display(){
	for(int i=2;i<size;i++){
		cout << i << " " << arr[i] << endl;
	}
}

int main(){
	
//	init();
	find_factor();
	solve();
//	display();
	
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%lld\n", arr[n]);
	}
    return 0;
}
