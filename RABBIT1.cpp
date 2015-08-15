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
LLD res[2][2], a[2][2];

void multiply(int n, int m){
	if(n == 1){
		LLD res00 = (((res[0][0] * a[0][0]) % m) + ((res[0][1] * a[1][0]) % m) % m);
		LLD res01 = (((res[0][0] * a[0][1]) % m) + ((res[0][1] * a[1][1]) % m) % m);
		LLD res10 = (((res[1][0] * a[0][0]) % m) + ((res[1][1] * a[1][0]) % m) % m);
		LLD res11 = (((res[1][0] * a[0][1]) % m) + ((res[1][1] * a[1][1]) % m) % m);
		res[0][0] = res00 % m, res[0][1] = res01 % m, res[1][0] = res10 % m, res[1][1] = res11 % m;
/*		cout << "res" << endl;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
		system("pause");*/
		return;
	}
	LLD a00 = (((a[0][0] * a[0][0]) % m) + ((a[0][1] * a[1][0]) % m) % m);
	LLD a01 = (((a[0][0] * a[0][1]) % m) + ((a[0][1] * a[1][1]) % m) % m);
	LLD a10 = (((a[1][0] * a[0][0]) % m) + ((a[1][1] * a[1][0]) % m) % m);
	LLD a11 = (((a[1][0] * a[0][1]) % m) + ((a[1][1] * a[1][1]) % m) % m);
	a[0][0] = a00 % m, a[0][1] = a01 % m, a[1][0] = a10 % m, a[1][1] = a11 % m;
	/*cout << "a" << endl;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
//	system("pause");*/
}

LLD findModPower(LLD n, LLD m){
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			res[i][j] = 1;
			a[i][j] = 1;
		}
	}
	//cout << m << endl;
	res[0][1] = res[1][0] = 0;
	a[0][0] = 0;
	while(n){
	/*	cout << (n&1) << endl;
		system("pause");*/
		if(n & 1)
			multiply(1, m);
		multiply(0, m);
		n >>= 1;
	}
	return res[1][1] % m;
}

int main(){
	
	int t;
	LLD n, m;
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld", &n, &m);
		printf("%lld\n", findModPower(n, 1<<m));
	}
    return 0;
}
