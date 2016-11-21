#include <iostream>
#include <cstdio>
#define SIZE 10000
#define MAX_TREE_SIZE 400000
#define MAX_PRIME_SIZE 1000001

using namespace std;

struct node {
	int leftPrimeCnt, rightPrimeCnt, lazyValue, totalPrimeCnt;
} segmentTree[MAX_TREE_SIZE];

int isPrime[MAX_PRIME_SIZE], arr[SIZE];

/*	Helper methods	*/

void preparePrimes(){
	fill(isPrime, isPrime + MAX_PRIME_SIZE, 1);
	isPrime[0] = isPrime[1] = 0;
	for(int i=4;i<MAX_PRIME_SIZE;i+=2)
		isPrime[i] = 0;
	for(int i=3;i<=1000;i+=2){
		if(isPrime[i]){
			for(int j=i*2;j<=MAX_PRIME_SIZE;j+=i)
				isPrime[j] = 0;
		}
	}
}

bool hasLazyUpdates(int index){
	return (segmentTree[index].lazyValue >= 2);
}

bool isLeafNode(int x, int y){
	return (x == y);
}

/*	Node level methods	*/

node getNode(int position){
	node tempNode;
	tempNode.leftPrimeCnt = isPrime[arr[position]];
	tempNode.rightPrimeCnt = 0;
	tempNode.totalPrimeCnt = tempNode.leftPrimeCnt + tempNode.rightPrimeCnt;
	tempNode.lazyValue = 0;
	return tempNode;
}

node getNode(int leftChild, int rightChild){
	node tempNode;
	node leftNode = segmentTree[leftChild];
	node rightNode = segmentTree[rightChild];

	tempNode.leftPrimeCnt = leftNode.totalPrimeCnt;
	tempNode.rightPrimeCnt = rightNode.totalPrimeCnt;
	tempNode.totalPrimeCnt = tempNode.leftPrimeCnt + tempNode.rightPrimeCnt;
	tempNode.lazyValue = 0;

	return tempNode;
}

void makeLazyUpdateToChild(int childIndex, int value){
	segmentTree[childIndex].lazyValue = value;
}

void makeLazyUpdatesToChildren(int value, int index){
	int leftChild = (index << 1) + 1;
	int rightChild = (index + 1) << 1;
	makeLazyUpdateToChild(leftChild, value);
	makeLazyUpdateToChild(rightChild, value);
}

void makeLazyUpdatesToNode(int x, int y, int index){
	int nodeLazyValue = segmentTree[index].lazyValue;
	int value = isPrime[nodeLazyValue];
	if(!isLeafNode(x, y)){
		makeLazyUpdatesToChildren(nodeLazyValue, index);
	}
	int mid = (x + y) >> 1;
	int numberOfElementsInLeft = mid - x + 1;
	int numberOfElementsInRight = y - mid;

	segmentTree[index].lazyValue = 0;
	segmentTree[index].leftPrimeCnt = numberOfElementsInLeft * value;
	segmentTree[index].rightPrimeCnt = numberOfElementsInRight * value;
	segmentTree[index].totalPrimeCnt = segmentTree[index].leftPrimeCnt + segmentTree[index].rightPrimeCnt;
}

void displayNode(int x, int y, int index){
	cout 	<< "x: " << x
			<< "\ty: " << y
			<< "\tindex: " << index
			<< "\tleftPrimeCnt: " << segmentTree[index].leftPrimeCnt
			<< "\trightPrimeCnt: " << segmentTree[index].rightPrimeCnt
			<< "\ttotalPrimeCnt: " << segmentTree[index].totalPrimeCnt
			<< "\tlazyValue: " << segmentTree[index].lazyValue
			<< endl;
}

void updateNode(int x, int y, int value, int index){
	int valueToBeUsed = isPrime[value];
	int mid = (x + y) >> 1;
	int nodesInLeft = mid - x + 1;
	int nodesInRight = y - mid;
	
	segmentTree[index].leftPrimeCnt = nodesInLeft * valueToBeUsed;
	segmentTree[index].rightPrimeCnt = nodesInRight * valueToBeUsed;
	segmentTree[index].totalPrimeCnt = segmentTree[index].leftPrimeCnt + segmentTree[index].rightPrimeCnt;
	segmentTree[index].lazyValue = 0;
}

void updateNodeUsingLeft(int leftIndex, int index){
	segmentTree[index].leftPrimeCnt = segmentTree[leftIndex].totalPrimeCnt;
	segmentTree[index].totalPrimeCnt = segmentTree[index].leftPrimeCnt + segmentTree[index].rightPrimeCnt;
	segmentTree[index].lazyValue = 0;
}

void updateNodeUsingRight(int rightIndex, int index){
	segmentTree[index].rightPrimeCnt = segmentTree[rightIndex].totalPrimeCnt;
	segmentTree[index].totalPrimeCnt = segmentTree[index].leftPrimeCnt + segmentTree[index].rightPrimeCnt;
	segmentTree[index].lazyValue = 0;
}

/*	Utility methods	*/

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

int queryTreeUtil(int x, int y, int left, int right, int index){
	if(hasLazyUpdates(index)){
		makeLazyUpdatesToNode(left, right, index);
	}
	if(x == left && y == right)
		return segmentTree[index].totalPrimeCnt;
	int mid = (left + right) >> 1;
	int leftChild = (index << 1) + 1;
	int rightChild = (index + 1) << 1;
	if(y <= mid)
		return queryTreeUtil(x, y, left, mid, leftChild);
	if(x > mid)
		return queryTreeUtil(x, y, mid + 1, right, rightChild);
	return queryTreeUtil(x, mid, left, mid, leftChild) + queryTreeUtil(mid + 1, y, mid + 1, right, rightChild);
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

void updateTreeUtil(int x, int y, int left, int right, int value, int index){
	if(hasLazyUpdates(index)){
		makeLazyUpdatesToNode(left, right, index);
	}
	if(x == left && y == right){
		updateNode(x, y, value, index);
		makeLazyUpdatesToChildren(value, index);
		return;
	}
	int mid = (left + right) >> 1;
	int leftChild = (index << 1) + 1;
	int rightChild = (index + 1) << 1;
	if(y <= mid){
		updateTreeUtil(x, y, left, mid, value, leftChild);
		updateNodeUsingLeft(leftChild, index);
		return;
	}
	if(x > mid){
		updateTreeUtil(x, y, mid + 1, right, value, rightChild);
		updateNodeUsingRight(rightChild, index);
		return;
	}
	updateTreeUtil(x, mid, left, mid, value, leftChild);
	updateTreeUtil(mid + 1, y, mid + 1, right, value, rightChild);
	segmentTree[index] = getNode(leftChild, rightChild);
}

/*	Trigger methods	*/

void prepareTree(int n){
	prepareTreeUtil(0, n-1, 0);
}

int queryTree(int x, int y, int n){
	return queryTreeUtil(x, y, 0, n-1, 0);
}

void displayTree(int n){
	displayTreeUtil(0, n-1, 0);
}

void updateTree(int x, int y, int value, int n){
	updateTreeUtil(x, y, 0, n-1, value, 0);
}

int main(){
	int t, n, q, option, x, y, value, testCase = 1;
	preparePrimes();
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &q);
		for(int i=0;i<n;i++){
			scanf("%d", &arr[i]);
			//printf("%d: %d\n", i, arr[i]);
		}
		printf("Case %d:\n", testCase++);
		prepareTree(n);
		//displayTree(n);
		while(q--){
			scanf("%d%d%d", &option, &x, &y);
			//cout << "query: " << option << " " << x << " " << y << endl;
			if(option == 0){
				scanf("%d", &value);
				updateTree(x-1, y-1, value, n);
				//displayTree(n);
				continue;
			}
			printf("%d\n", queryTree(x-1, y-1, n));
			//displayTree(n);
		}
	}
	return 0;
}