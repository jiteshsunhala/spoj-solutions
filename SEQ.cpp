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
#define SIZE 10
#define MOD 1000000000

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

LLD matrix[SIZE][SIZE], res[SIZE][SIZE], b[SIZE], c[SIZE], temp[SIZE][SIZE];

void prepareMatrix(int k){
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++)
			matrix[i][j] = 0;
	for(int j=0;j<k;j++)
		matrix[0][j] = c[j];
	for(int i=1;i<k;i++)
		matrix[i][i-1] = 1;
}

void displayResult(int k){
	cout << "res " << endl;
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
//	system("pause");
}

void displayMatrix(int k){
	cout << "matrix " << endl;
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
//	system("pause");
}


void multiply(int x, LLD m, int MAT_SIZE){
	if(x == 1){
		//displayResult(MAT_SIZE);
		for(int i=0;i<MAT_SIZE;i++){
			for(int j=0;j<MAT_SIZE;j++){
				temp[i][j] = 0;
				for(int k=0;k<MAT_SIZE;k++)
					temp[i][j] = (temp[i][j] + (res[i][k] * matrix[k][j])) % m;
			}
		}
		for(int i=0;i<MAT_SIZE;i++)
			for(int j=0;j<MAT_SIZE;j++)
				res[i][j] = temp[i][j];
		//displayResult(MAT_SIZE);
		return;
	}
	for(int i=0;i<MAT_SIZE;i++){
		for(int j=0;j<MAT_SIZE;j++){
			temp[i][j] = 0;
			for(int k=0;k<MAT_SIZE;k++){
				temp[i][j] = (temp[i][j] + matrix[i][k] * matrix[k][j]) % m;
			}
		}
	}
	for(int i=0;i<MAT_SIZE;i++)
		for(int j=0;j<MAT_SIZE;j++)
			matrix[i][j] = temp[i][j];
	//displayMatrix(MAT_SIZE);
}

void initRes(int MAT_SIZE){
	for(int i=0;i<MAT_SIZE;i++){
		for(int j=0;j<MAT_SIZE;j++){
			if(i == j)
				res[i][j] = 1;
			else
				res[i][j] = 0;
		}
	}
}

LLD solveMatrix(LLD n, int k, LLD m = MOD){
	initRes(k);
//	displayResult(k);
	while(n){
		if(n & 1)
			multiply(1, m, k);
		multiply(0, m, k);
		n >>= 1;
	}
	LLD total = 0;
	for(int i=0;i<k;i++)
		total = (total + (res[0][i] * b[k - i - 1]) % m) % m;
	return total;
}

int main(){
	
	int t, k;
	LLD n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &k);
		for(int i=0;i<k;i++)
			scanf("%lld", &b[i]);
		for(int i=0;i<k;i++)
			scanf("%lld", &c[i]);
		scanf("%lld", &n);
		prepareMatrix(k);
		//displayMatrix(k);
		if(n <= k)
			printf("%lld\n", b[n-1] % MOD);
		else
			printf("%lld\n", solveMatrix(n - k, k));
	}
    return 0;
}
