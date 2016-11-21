#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAX_TREE_SIZE 263000
#define SIZE 100000
#define LLD long long int

using namespace std;

struct node {
	LLD totalApples, minimumApples;
} segmentTree[MAX_TREE_SIZE];

LLD arr[SIZE];

node getNode(int position){
	node tempNode;
	tempNode.totalApples = arr[position];
	tempNode.minimumApples = arr[position];
	return tempNode;
}

node getNode(int leftChild, int rightChild){
	node tempNode;
	tempNode.totalApples = segmentTree[leftChild].totalApples + segmentTree[rightChild].totalApples;
	tempNode.minimumApples = min(segmentTree[leftChild].minimumApples, segmentTree[rightChild].minimumApples);
	return tempNode;
}

void displayNode(int x, int y, int index){
	cout 	<< "x: " << x
			<< "\ty: " << y
			<< "\tindex: " << index
			<< "\ttotalApples: " << segmentTree[index].totalApples
			<< "\tminimumApples: " << segmentTree[index].minimumApples
			<< endl;
}

void prepareTreeUtil(int x, int y, int index){
	if(x == y){
		segmentTree[index] = getNode(x);
		return;
	}
	int mid = (x + y) >> 1;
	int leftChild = (index << 1) + 1;
	int rightChild = (index + 1) << 1;
	prepareTreeUtil(x, mid, leftChild);
	prepareTreeUtil(mid + 1, y, rightChild);
	segmentTree[index] = getNode(leftChild, rightChild);
}

LLD querySum(int x, int y, int left, int right, int index){
	if(x == left && y == right)
		return segmentTree[index].totalApples;
	int mid = (left + right) >> 1;
	int leftChild = (index << 1) + 1;
	int rightChild = (index + 1) << 1;
	if(y <= mid)
		return querySum(x, y, left, mid, leftChild);
	if(x > mid)
		return querySum(x, y, mid + 1, right, rightChild);
	return querySum(x, mid, left, mid, leftChild) + querySum(mid + 1, y, mid + 1, right, rightChild);
}

LLD queryMinimum(int x, int y, int left, int right, int index){
	if(x == left && y == right)
		return segmentTree[index].minimumApples;
	int mid = (left + right) >> 1;
	int leftChild = (index << 1) + 1;
	int rightChild = (index + 1) << 1;
	if(y <= mid)
		return queryMinimum(x, y, left, mid, leftChild);
	if(x > mid)
		return queryMinimum(x, y, mid + 1, right, rightChild);
	return min(queryMinimum(x, mid, left, mid, leftChild), queryMinimum(mid + 1, y, mid + 1, right, rightChild));
}

void updateTreeUtil(int x, LLD value, int left, int right, int index){
	if(left == x && x == right){
		segmentTree[index].totalApples += value;
		segmentTree[index].minimumApples = segmentTree[index].totalApples;
		return;
	}
	int mid = (left + right) >> 1;
	int leftChild = (index << 1) + 1;
	int rightChild = (index + 1) << 1;
	if(x <= mid)
		updateTreeUtil(x, value, left, mid, leftChild);
	if(x > mid)
		updateTreeUtil(x, value, mid + 1, right, rightChild);
	segmentTree[index] = getNode(leftChild, rightChild);
}

void displayTreeUtil(int x, int y, int index){
	if(x == y){
		displayNode(x, y, index);
		return;
	}
	int mid = (x + y) >> 1;
	int leftChild = (index << 1) + 1;
	int rightChild = (index + 1) << 1;
	displayTreeUtil(x, mid, leftChild);
	displayTreeUtil(mid + 1, y, rightChild);
	displayNode(x, y, index);
}

void prepareTree(int n){
	prepareTreeUtil(0, n-1, 0);
}

LLD queryTree(int x, int y, int n){
	return querySum(x, y, 0, n-1, 0) - queryMinimum(x, y, 0, n-1, 0);
}

void updateTree(int x, LLD value, int n){
	updateTreeUtil(x, value, 0, n-1, 0);
}

void displayTree(int n){
	displayTreeUtil(0, n-1, 0);
}

int main(){

	int n, q, x, y;
	LLD value;
	string command;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%lld", &arr[i]);
	prepareTree(n);
	//displayTree(n);
	scanf("%d", &q);
	while(q--){
		cin >> command;
		if(command == "COUNT"){
			scanf("%d%d", &x, &y);
			printf("%lld\n", queryTree(x, y, n));
			continue;
		}
		scanf("%lld%d", &value, &x);
		if(command == "EAT")
			value *= -1;
		updateTree(x, value, n);
		//displayTree(n);
	}
	return 0;
}