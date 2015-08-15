#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define size1 10001			//		to be optimized....
#define size2 500			//		no. of items.......
#define LLD long long int
#define INF 100000000

void display(LLD matrix[2][size1], int idx, int n){
	for(int i=0;i<=n;i++)
		cout << matrix[idx][i] << " ";
	cout << endl;
}

LLD dp[size1];

int main(){
	
	int weight[size2], values[size2];
    int wb, wa, k, n, v, w, t;
    scanf("%d", &t);
    while(t--){
		scanf("%d%d", &wb, &wa);
		k = wa - wb;
	    scanf("%d", &n);
	    for(int i=0;i<n;i++){
	        scanf("%d%d", &v, &w);
	        values[i] = v;
	        weight[i] = w;
	    }
	    dp[0] = 0;
	    for(int i=1;i<=k;i++){
			dp[i] = -1;
			for(int j=0;j<n;j++){
				int remWeight = i - weight[j];
				if(remWeight < 0)
					continue;
				if(dp[remWeight] == -1)
					continue;
				if(dp[i] == -1 || dp[remWeight] + values[j] < dp[i])
					dp[i] = dp[remWeight] + values[j];
			}
		}
		if(dp[k] == -1)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", dp[k]);
	}
    return 0;
}
