#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define size1 2001		//		to be optimized....
#define size2 2001			//		no. of items.......
#define LLD long long int

void display(LLD matrix[2][501], int idx, int n){
	for(int i=0;i<n;i++)
		cout << matrix[idx][i] << " ";
	cout << endl;
}

LLD matrix[2][size1], wm[2][size1];

int main(){
	
	int weight[size2], values[size2];
    int k, n, v, w;
    int t;
    scanf("%d", &t);
    while(t--){
	    scanf("%d%d", &k, &n);
	    for(int i=0;i<=k;i++){
			matrix[0][i] = matrix[1][i] = 0;
	//		wm[0][i] = wm[1][i] = 0;
	    }
	    
	    for(int i=0;i<n;i++){
	        scanf("%d%d", &w, &v);
	        values[i] = v;
	        weight[i] = w;
	    }
	    
	    int idx = 1, prev = 0;
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<=k;j++){
				if(weight[i] <= j){
					matrix[idx][j] = max(matrix[prev][j], values[i] + matrix[prev][j - weight[i]]);
			//                wm[idx][j] = max(wm[prev][j], weight[i] + wm[prev][j - weight[i]]);
				}
				else{
					matrix[idx][j] = matrix[prev][j];
			//                wm[idx][j] = wm[prev][j];
				}
			}
			/*display(wm, idx, k);
			display(matrix, idx, k);*/
			idx ^= 1;
			prev ^= 1;
	    }
	    idx ^= 1;
	    printf("Hey stupid robber, you can get %lld.\n", matrix[idx][k]);
    }
    return 0;
}

