#include <iostream>
#include <cstdio>
#define LLD long long int
#define LLU unsigned long long int
#define SIZE 100000
#define MAX_TREE_SIZE 263000

using namespace std;

struct node {
	LLD leftSquareSum, rightSquareSum, leftLinearSum, rightLinearSum, lazyUpdateValue, totalLinearSum, totalSquareSum;
	bool lazySet, lazyAdd;
} segmentTree[MAX_TREE_SIZE];

LLD arr[SIZE];

/*	Helper methods.	*/

bool hasLazyUpdates(int index){
	return (segmentTree[index].lazySet || segmentTree[index].lazyAdd);
}

bool isLeafNode(int x, int y){
	return (x == y);
}

/*	Node Level methods.	*/

node prepareNode(int x){
	node tempNode;

	tempNode.leftLinearSum = arr[x];
	tempNode.rightLinearSum = 0;
	tempNode.totalLinearSum = tempNode.leftLinearSum + tempNode.rightLinearSum;
	
	tempNode.leftSquareSum = arr[x] * arr[x];
	tempNode.rightSquareSum = 0;
	tempNode.totalSquareSum = tempNode.leftSquareSum + tempNode.rightSquareSum;
	
	tempNode.lazyUpdateValue = 0;
	
	tempNode.lazySet = false;
	tempNode.lazyAdd = false;
	
	return tempNode;
}

node prepareNode(int leftChild, int rightChild){
	node tempNode;
	node leftNode = segmentTree[leftChild];
	node rightNode = segmentTree[rightChild];
	
	tempNode.leftLinearSum = leftNode.totalLinearSum;
	tempNode.rightLinearSum = rightNode.totalLinearSum;
	tempNode.totalLinearSum = tempNode.leftLinearSum + tempNode.rightLinearSum;

	tempNode.leftSquareSum = leftNode.totalSquareSum;
	tempNode.rightSquareSum = rightNode.totalSquareSum;
	tempNode.totalSquareSum = tempNode.leftSquareSum + tempNode.rightSquareSum;

	tempNode.lazyUpdateValue = 0;

	tempNode.lazySet = false;
	tempNode.lazyAdd = false;

	return tempNode;
}

void displayNode(int x, int y, int index){
	cout 	<< "x: " << x 
			<< "\ty: " << y
			<< "\tidx: " << index
			<< "\tlls: " << segmentTree[index].leftLinearSum
			<< "\trls: " << segmentTree[index].rightLinearSum
			<< "\ttls: " << segmentTree[index].totalLinearSum
			<< "\tlss: " << segmentTree[index].leftSquareSum
			<< "\trss: " << segmentTree[index].rightSquareSum
			<< "\ttss: " << segmentTree[index].totalSquareSum
			<< "\tluv: " << segmentTree[index].lazyUpdateValue
			<< "\tlsf: " << segmentTree[index].lazySet
			<< "\tlaf: " << segmentTree[index].lazyAdd 
			<< endl;
}

void setValueInNode(int x, int y, LLD value, int index){
	segmentTree[index].lazyAdd = false;
	segmentTree[index].lazySet = false;
	segmentTree[index].lazyUpdateValue = 0;

	int mid = (x + y) >> 1;
	int nodesInLeftChild = mid - x + 1;
	int nodesInRightChild = y - mid;

	segmentTree[index].leftLinearSum = value * nodesInLeftChild;
	segmentTree[index].rightLinearSum = value * nodesInRightChild;
	segmentTree[index].totalLinearSum = segmentTree[index].leftLinearSum + segmentTree[index].rightLinearSum;

	segmentTree[index].leftSquareSum = value * value * nodesInLeftChild;
	segmentTree[index].rightSquareSum = value * value * nodesInRightChild;
	segmentTree[index].totalSquareSum = segmentTree[index].leftSquareSum + segmentTree[index].rightSquareSum;
}

void addValueToNode(int x, int y, LLD value, int index){
	segmentTree[index].lazyAdd = false;
	segmentTree[index].lazySet = false;
	segmentTree[index].lazyUpdateValue = 0;

	int mid = (x + y) >> 1;
	int nodesInLeftChild = mid - x + 1;
	int nodesInRightChild = y - mid;

	LLD previousLeftLinearSum = segmentTree[index].leftLinearSum;
	segmentTree[index].leftLinearSum += (value * nodesInLeftChild);
	LLD previousRightLinearSum = segmentTree[index].rightLinearSum;
	segmentTree[index].rightLinearSum += (value * nodesInRightChild);
	segmentTree[index].totalLinearSum = segmentTree[index].leftLinearSum + segmentTree[index].rightLinearSum;

	segmentTree[index].leftSquareSum += ((nodesInLeftChild * value * value) + (2 * value * previousLeftLinearSum));
	segmentTree[index].rightSquareSum += ((nodesInRightChild * value * value) + (2 * value * previousRightLinearSum));
	segmentTree[index].totalSquareSum = segmentTree[index].leftSquareSum + segmentTree[index].rightSquareSum;
}

void makeLazyUpdateToChild(int childIndex, int parentIndex){
	segmentTree[childIndex].lazyAdd = segmentTree[parentIndex].lazyAdd;
	segmentTree[childIndex].lazySet = segmentTree[parentIndex].lazySet;
	if(segmentTree[childIndex].lazySet){
		segmentTree[childIndex].lazyUpdateValue = segmentTree[parentIndex].lazyUpdateValue;
		return;
	}
	segmentTree[childIndex].lazyUpdateValue += segmentTree[parentIndex].lazyUpdateValue;
}

void makeLazyUpdatesToChildren(int index){
	int leftChild = (index << 1) + 1;
	int rightChild = (index + 1) << 1;
	makeLazyUpdateToChild(leftChild, index);
	makeLazyUpdateToChild(rightChild, index);
}

void makeLazyUpdatesToNode(int x, int y, int index){
	LLD value = segmentTree[index].lazyUpdateValue;
	if(!isLeafNode(x, y))
		makeLazyUpdatesToChildren(index);
	if(segmentTree[index].lazySet){
		setValueInNode(x, y, value, index);
		return;
	}
	addValueToNode(x, y, value, index);
}

void pushSetValueToNode(int index, LLD value){
	segmentTree[index].lazyAdd = false;
	segmentTree[index].lazySet = true;
	segmentTree[index].lazyUpdateValue = value;
}

void pushAddValueToNode(int index, LLD value){
	segmentTree[index].lazyUpdateValue += value;
	if(segmentTree[index].lazyAdd || segmentTree[index].lazySet)
		return;
	segmentTree[index].lazyAdd = true;
}

void pushLazyUpdatesToChildren(LLD value, int index, bool isSet){
	int leftChild = (index << 1) + 1;
	int rightChild = (index + 1) << 1;
	if(isSet){
		pushSetValueToNode(leftChild, value);
		pushSetValueToNode(rightChild, value);
		return;
	}
	pushAddValueToNode(leftChild, value);
	pushAddValueToNode(rightChild, value);
}

void updateNodeWithLeftNode(int leftChild, int index){
	node leftNode = segmentTree[leftChild];
	segmentTree[index].leftLinearSum = leftNode.totalLinearSum;
	segmentTree[index].leftSquareSum = leftNode.totalSquareSum;
	segmentTree[index].totalLinearSum = segmentTree[index].leftLinearSum + segmentTree[index].rightLinearSum;
	segmentTree[index].totalSquareSum = segmentTree[index].leftSquareSum + segmentTree[index].rightSquareSum;
}

void updateNodeWithRightNode(int rightChild, int index){
	node rightNode = segmentTree[rightChild];
	segmentTree[index].rightLinearSum = rightNode.totalLinearSum;
	segmentTree[index].rightSquareSum = rightNode.totalSquareSum;
	segmentTree[index].totalLinearSum = segmentTree[index].leftLinearSum + segmentTree[index].rightLinearSum;
	segmentTree[index].totalSquareSum = segmentTree[index].leftSquareSum + segmentTree[index].rightSquareSum;
}

/*	Util methods.	*/

void prepareTreeUtil(int x, int y, int index){
	if(x == y){
		segmentTree[index] = prepareNode(x);
		return;
	}
	int mid = (x + y) >> 1;
	int leftChild = (index << 1) + 1;
	int rightChild = (index + 1) << 1;
	prepareTreeUtil(x, mid, leftChild);
	prepareTreeUtil(mid + 1, y, rightChild);
	segmentTree[index] = prepareNode(leftChild, rightChild);
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

void setTreeUtil(int x, int y, int left, int right, LLD value, int index){
	if(hasLazyUpdates(index)){
		makeLazyUpdatesToNode(left, right, index);
	}
	if(x == left && y == right){
		setValueInNode(left, right, value, index);
		pushLazyUpdatesToChildren(value, index, true);
		return;
	}
	int mid = (left + right) >> 1;
	int leftChild = (index << 1) + 1;
	int rightChild = (index + 1) << 1;
	if(y <= mid){
		setTreeUtil(x, y, left, mid, value, leftChild);
		updateNodeWithLeftNode(leftChild, index);
		return;
	}
	if(x > mid){
		setTreeUtil(x, y, mid + 1, right, value, rightChild);
		updateNodeWithRightNode(rightChild, index);
		return;
	}
	setTreeUtil(x, mid, left, mid, value, leftChild);
	setTreeUtil(mid + 1, y, mid + 1, right, value, rightChild);
	segmentTree[index] = prepareNode(leftChild, rightChild);
}

void addTreeUtil(int x, int y, int left, int right, LLD value, int index){
	if(hasLazyUpdates(index)){
		makeLazyUpdatesToNode(left, right, index);
	}
	if(x == left && y == right){
		addValueToNode(left, right, value, index);
		pushLazyUpdatesToChildren(value, index, false);
		return;
	}
	int mid = (left + right) >> 1;
	int leftChild = (index << 1) + 1;
	int rightChild = (index + 1) << 1;
	if(y <= mid){
		addTreeUtil(x, y, left, mid, value, leftChild);
		updateNodeWithLeftNode(leftChild, index);
		return;
	}
	if(x > mid){
		addTreeUtil(x, y, mid + 1, right, value, rightChild);
		updateNodeWithRightNode(rightChild, index);
		return;
	}
	addTreeUtil(x, mid, left, mid, value, leftChild);
	addTreeUtil(mid + 1, y, mid + 1, right, value, rightChild);
	segmentTree[index] = prepareNode(leftChild, rightChild);
}

LLD queryTreeUtil(int x, int y, int left, int right, int index){
	if(hasLazyUpdates(index)){
		makeLazyUpdatesToNode(left, right, index);
	}
	if(x == left && y == right)
		return segmentTree[index].totalSquareSum;
	int mid = (left + right) >> 1;
	int leftChild = (index << 1) + 1;
	int rightChild = (index + 1) << 1;
	if(y <= mid)
		return queryTreeUtil(x, y, left, mid, leftChild);
	if(x > mid)
		return queryTreeUtil(x, y, mid + 1, right, rightChild);
	return queryTreeUtil(x, mid, left, mid, leftChild) + queryTreeUtil(mid + 1, y, mid + 1, right, rightChild);
}

/*	Trigger methods.	*/

void prepareTree(int n){
	prepareTreeUtil(0, n-1, 0);
}

void displayTree(int n){
	displayTreeUtil(0, n-1, 0);
}

void setTree(int x, int y, LLD value, int n){
	setTreeUtil(x, y, 0, n-1, value, 0);
}

void addTree(int x, int y, LLD value, int n){
	addTreeUtil(x, y, 0, n-1, value, 0);
}

LLD queryTree(int x, int y, int n){
	return queryTreeUtil(x, y, 0, n-1, 0);
}

int main(){

	int t, n, m, option, x, y, testCase = 1;
	LLD val;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		//printf("%d\n", m);
		for(int i=0;i<n;i++)
			scanf("%lld", &arr[i]);
		prepareTree(n);
		//displayTree(n);
		printf("Case %d:\n", testCase++);
		while(m--){
			//cout << "waiting for option" << endl;
			scanf("%d", &option);
			if(option == 0){
				scanf("%d%d%lld", &x, &y, &val);
				setTree(x-1, y-1, val, n);
				//displayTree(n);
				continue;
			}
			if(option == 1){
				scanf("%d%d%lld", &x, &y, &val);
				addTree(x-1, y-1, val, n);
				//displayTree(n);
				continue;
			}
			scanf("%d%d", &x, &y);
			printf("%lld\n", queryTree(x-1, y-1, n));
		}
	}
	return 0;
}