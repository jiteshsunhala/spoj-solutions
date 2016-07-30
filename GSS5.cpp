#include <iostream>
#include <cstdio>
#define MAX_TREE_SIZE 33000
#define SIZE 10000

using namespace std;

struct node{
	int leftMaxSum, rightMaxSum, totalSum, maxSum;
} segment_tree[MAX_TREE_SIZE];

int arr[SIZE];

void displayNode(int left, int right, int index){
	cout << 
		"index: " << index << 
		", left: " << left << 
		", right: " << right << 
		", leftMaxSum: " << segment_tree[index].leftMaxSum << 
		", rightMaxSum: " << segment_tree[index].rightMaxSum <<
		", totalSum: " << segment_tree[index].totalSum << 
		", maxSum: " << segment_tree[index].maxSum << endl;
}

void displayNodeByNode(node treeNode){
	cout << "leftMaxSum: " << treeNode.leftMaxSum << 
			", rightMaxSum: " << treeNode.rightMaxSum <<
			", totalSum: " << treeNode.totalSum << 
			", maxSum: " << treeNode.maxSum << endl;	
}

void prepareLeafNode(int x, int index){
	segment_tree[index].leftMaxSum = arr[x];
	segment_tree[index].rightMaxSum = arr[x];
	segment_tree[index].totalSum = arr[x];
	segment_tree[index].maxSum = arr[x];
}

node getNode(node leftChild, node rightChild){
	node tempNode;
	tempNode.totalSum = leftChild.totalSum + rightChild.totalSum;
	tempNode.leftMaxSum = max(leftChild.leftMaxSum, leftChild.totalSum + rightChild.leftMaxSum);
	tempNode.rightMaxSum = max(leftChild.rightMaxSum + rightChild.totalSum, rightChild.rightMaxSum);
	tempNode.maxSum = 	max(leftChild.maxSum, max(
								rightChild.maxSum, max(
									leftChild.rightMaxSum + rightChild.leftMaxSum, max(
										leftChild.totalSum + rightChild.leftMaxSum, max(
											leftChild.rightMaxSum + rightChild.totalSum, leftChild.totalSum + rightChild.totalSum
										)
									)
								)
							)
						);
	return tempNode;
}

void prepareTreeUtil(int left, int right, int index){
	if(left == right){
		prepareLeafNode(left, index);
		return;
	}
	int mid = (left + right) >> 1;
	int leftChild = (index << 1) + 1;
	int rightChild = (index + 1) << 1;
	prepareTreeUtil(left, mid, leftChild);
	prepareTreeUtil(mid + 1, right, rightChild);
	segment_tree[index] = getNode(segment_tree[leftChild], segment_tree[rightChild]);
}

void displayTreeUtil(int left, int right, int index){
	if(left == right){
		displayNode(left, right, index);
		return;
	}
	int mid = (left + right) >> 1;
	int leftChild = (index << 1) + 1;
	int rightChild = (index + 1) << 1;
	displayTreeUtil(left, mid, leftChild);
	displayTreeUtil(mid + 1, right, rightChild);
	displayNode(left, right, index);
}

int getTotalSumUtil(int left, int right, int nodeLeft, int nodeRight, int index){
	if(left == nodeLeft && right == nodeRight)
		return segment_tree[index].totalSum;
	int mid = (nodeLeft + nodeRight) >> 1;
	int leftChild = (index << 1) + 1;
	int rightChild = (index + 1) << 1;
	if(right <= mid)
		return getTotalSumUtil(left, right, nodeLeft, mid, leftChild);
	if(left > mid)
		return getTotalSumUtil(left, right, mid + 1, nodeRight, rightChild);
	return getTotalSumUtil(left, mid, nodeLeft, mid, leftChild) + getTotalSumUtil(mid + 1, right, mid + 1, nodeRight, rightChild);
}

node getNodeValues(int left, int right, int nodeLeft, int nodeRight, int index){
	if(left == nodeLeft && right == nodeRight){
		return segment_tree[index];
	}
	int mid = (nodeLeft + nodeRight) >> 1;
	int leftChild = (index << 1) + 1;
	int rightChild = (index + 1) << 1;
	if(right <= mid)
		return getNodeValues(left, right, nodeLeft, mid, leftChild);
	if(left > mid)
		return getNodeValues(left, right, mid + 1, nodeRight, rightChild);
	node leftNode = getNodeValues(left, mid, nodeLeft, mid, leftChild);
	node rightNode = getNodeValues(mid + 1, right, mid + 1, nodeRight, rightChild);
	node tempNode = getNode(leftNode, rightNode);
	return tempNode;
}

void prepareTree(int n){
	prepareTreeUtil(0, n-1, 0);
}

void displayTree(int n){
	displayTreeUtil(0, n-1, 0);
}

bool areIntersecting(int x1, int y1, int x2, int y2){
	return (x2 <= y1);
}

int getTotalSum(int x, int y, int n){
	return getTotalSumUtil(x, y, 0, n-1, 0);
}

int getLeftMaximum(int x, int y, int n){
	node tempNode = getNodeValues(x, y, 0, n-1, 0);
	return tempNode.leftMaxSum;
}

int getRightMaximum(int x, int y, int n){
	node tempNode = getNodeValues(x, y, 0, n-1, 0);
	return tempNode.rightMaxSum;
}

node getNodeByIndex(int x, int y, int n){
	return getNodeValues(x, y, 0, n-1, 0);
}

int getMaximum(int x, int y, int n){
	node tempNode = getNodeValues(x, y, 0, n-1, n);
	return tempNode.maxSum;
}

int queryTree(int x1, int y1, int x2, int y2, int n){
	if(!areIntersecting(x1, y1, x2, y2)){
		int midTotalSum = 0;
		if(y1 + 1 <= x2 - 1)
			midTotalSum = getTotalSum(y1 + 1, x2 - 1, n);
		return getRightMaximum(x1, y1, n) + midTotalSum + getLeftMaximum(x2, y2, n);
	}
	node centerNode = getNodeByIndex(x2, y1, n);
	int rightSum = 0;
	if(x1 <= x2 - 1)
		rightSum = getRightMaximum(x1, x2 - 1, n);
	int leftSum = 0;
	if(y1 + 1 <= y2)
		leftSum = getLeftMaximum(y1 + 1, y2, n);
	return 	max(rightSum + centerNode.totalSum + leftSum, max(
					rightSum + centerNode.leftMaxSum, max(
						centerNode.rightMaxSum + leftSum, centerNode.maxSum
					)
				)
			);
}

int main(){

	int q, x1, y1, x2, y2, t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		prepareTree(n);
		//displayTree(n);
		scanf("%d", &q);
		while(q--){
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			printf("%d\n", queryTree(x1 - 1, y1 - 1, x2 - 1, y2 - 1, n));
		}
	}
	return 0;
}