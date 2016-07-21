#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX_TREE_SIZE 270000
#define SIZE 100000

using namespace std;

int arr[SIZE], segmentTree[MAX_TREE_SIZE];

int prepareTreeUtil(int x, int y, int index){
	if(x == y){
		segmentTree[index] = arr[x];
		//cout << x << " " << y << " " << index << " " << segmentTree[index] << endl;
		return segmentTree[index];
	}
	int m = (x + y) / 2;
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;
	int leftMin = prepareTreeUtil(x, m, leftChild);
	int rightMin = prepareTreeUtil(m + 1, y, rightChild);
	segmentTree[index] = min(leftMin, rightMin);
	//cout << x << " " << y << " " << index << " " << segmentTree[index] << endl;
	return segmentTree[index];
}

void prepareTree(int n){
	prepareTreeUtil(0, n-1, 0);
}

int queryTreeUtil(int x, int y, int left, int right, int index){
	if(x == left && y == right)
		return segmentTree[index];
	int mid = (left + right) / 2;
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;
	if(y <= mid)
		return queryTreeUtil(x, y, left, mid, leftChild);
	if(x > mid)
		return queryTreeUtil(x, y, mid + 1, right, rightChild);
	int leftMin = queryTreeUtil(x, mid, left, mid, leftChild);
	int rightMin = queryTreeUtil(mid + 1, y, mid + 1, right, rightChild);
	return min(leftMin, rightMin);
}

int queryTree(int x, int y, int n){
	return queryTreeUtil(x, y, 0, n-1, 0);
}

int main(){

	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	prepareTree(n);
	int q, x, y;
	scanf("%d", &q);
	while(q--){
		scanf("%d%d", &x, &y);
		if(x > y)
			swap(x, y);
		printf("%d\n", queryTree(x, y, n));
	}
	return 0;
}