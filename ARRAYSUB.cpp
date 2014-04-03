#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int root, idx[1010], a[1000000];

void preprocess(int n){
	
	root = (int)sqrt(n);
	int max_val;
	
	fill(idx, idx + root + 1, -1);
	
	for(int i=0;i<n;i++){
		if(i%root == 0)
			max_val = -1;
		if(max_val < a[i]){
			max_val = a[i];
			idx[i/root] = i;
		}
	}
	/*
	for(int i=0;i<root+1;i++)
		cout << idx[i] << " ";
	
	cout << endl;
	*/
}

int find_max(int x, int y){
	
	int max_val = -1;
	int first_range = x / root, last_range = y / root;
	
	for(int i=first_range + 1;i<last_range;i++){
//		cout << "Range: " << i << endl;
		if(max_val < a[idx[i]])
			max_val = a[idx[i]];
	}
	
	int first_start_idx = x, first_last_idx = min(y, ((first_range + 1) * root) - 1);
	int last_start_idx = max(x, last_range * root), last_last_idx = y;
	
//	cout <<	"Searching in first range: " << endl;
	for(int i=first_start_idx;i<=first_last_idx;i++){
//		cout << "Index: " << i << endl;
		if(max_val < a[i])
			max_val = a[i];
	}
	
//	cout <<	"Searching in last range: " << endl;
	for(int i=last_start_idx;i <= last_last_idx;i++){
//		cout << "Index: " << i << endl;
		if(max_val < a[i])
			max_val = a[i];
	}
	
//	system("pause");
	return max_val;
}

int main(){
	int i, j, n, k;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	preprocess(n);
	scanf("%d", &k);
	
	for(i=0;i<n-k;i++){
		j = i + k-1;
		cout << find_max(i, j) << " ";
	}
	
	cout << find_max(i, i+k-1);
	return 0;
}
