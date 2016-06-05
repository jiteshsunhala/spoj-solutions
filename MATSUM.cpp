#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define LLD long long int
#define SIZE 1025

using namespace std;

int sumMatrix[SIZE][SIZE], matrix[SIZE][SIZE];

void initialise(int n){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			sumMatrix[i][j] = 0;
			matrix[i][j] = 0;
		}
	}
}

void update(int x, int y, int val, int n){
	int previousValue = matrix[x][y];
	matrix[x][y] = val;
	int y1;
	while(x <= n){
		y1 = y;
		while(y1 <= n){
			sumMatrix[x][y1] += (val - previousValue);
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}


int query(int x, int y, int n){
	LLD sum = 0;
	int y1;
	while(x > 0){
		y1 = y;
		while(y1 > 0){
			sum += sumMatrix[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return sum;
}

int main(){
	int t, n, a, b, c, d, val;
	char command[5];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		initialise(n);
		while(true){
			scanf("%s", command);
			if(command[1] == 'N')
				break;
			else if(command[1] == 'E'){
				scanf("%d%d%d", &a, &b, &val);
				a++;b++;
				update(a, b, val, n);
			} else {
				scanf("%d%d%d%d", &a, &b, &c, &d);
				a++;b++;c++;d++;
				printf("%d\n", query(c, d, n) + query(a-1, b-1, n) - query(c, b-1, n) - query(a-1, d, n));
			}
		}
	}
	return 0;
}