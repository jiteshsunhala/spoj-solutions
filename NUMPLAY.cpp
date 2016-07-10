#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#define SIZE 10001

using namespace std;

struct Big{
	char value[1800];
} result[5][SIZE];

Big add(Big a, Big b){
	char sum[1800];
	Big res;
	int i = strlen(a.value) - 1, j = strlen(b.value) - 1, total, carry = 0, idx = 0;
	while(i >= 0 && j >= 0){
		total = carry + (a.value[i] - 48) + (b.value[j] - 48);
		carry = total / 10;
		sum[idx++] = (total % 10) + 48;
		i--;
		j--;
	}
	while(i >= 0){
		total = carry + (a.value[i] - 48);
		carry = total / 10;
		sum[idx++] = (total % 10) + 48;
		i--;
	}
	while(j >= 0){
		total = carry + (b.value[j] - 48);
		carry = total / 10;
		sum[idx++] = (total % 10) + 48;
		j--;
	}
	while(carry){
		sum[idx++] = (carry % 10) + 48;
		carry /= 10;
	}
	sum[idx++] = '\0';
	for(i=0, j=strlen(sum) - 1;j>=0;j--, i++)
		res.value[i] = sum[j];
	res.value[i] = 0;
	return res;
}

void preCompute(){
	strcpy(result[4][0].value, "0");
	strcpy(result[0][1].value, "1");
	strcpy(result[1][1].value, "1");
	strcpy(result[2][1].value, "1");
	strcpy(result[3][1].value, "1");
	strcpy(result[4][1].value, "4");

	for(int j=2;j<SIZE;j++){
		result[0][j] = result[1][j-1];
		result[1][j] = add(result[0][j-1], result[3][j-1]);
		result[2][j] = add(result[1][j-1], result[3][j-1]);
		result[3][j] = result[2][j-1];
		result[4][j] = add(result[4][j-1], result[2][j]);
	}
}

int main(){
	preCompute();
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%s\n", result[4][n].value);
	}
	return 0;
}