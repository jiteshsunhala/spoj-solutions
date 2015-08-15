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

bool factors(int n, int k){
	int cnt;
	if(n == 1 && k == 1)
		return true;
	if(n == 1 && k != 1)
		return false;
	//	check for 2 first.
	if(n % 2 == 0){
		while(n % 2 == 0){
			n /= 2;
			cnt++;
		}
		cnt++;
		if(k % cnt != 0)
			return false;
		else
			k /= cnt;
	}
	int root = (int)sqrt(n);
	for(int i=3;i<=root;i+=2){
		cnt = 0;
		if(n % i == 0){
			while(n % i == 0){
				n /= i;
				cnt++;
			}
			cnt++;
			if(k % cnt != 0)
				return false;
			else
				k /= cnt;
		}
	}
	if(n == 1)
		return true;
	return (k % 2 == 0);
}

int main(){
	
	int k, a, b, cnt = 0;
	cin >> a >> b >> k;
	for(int i=a;i<=b;i++){
		if(factors(i, k)){
			//cout << i << endl;
			cnt++;
		}
	}
	cout << cnt;
//	system("pause");
    return 0;
}
