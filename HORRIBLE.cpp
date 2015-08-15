#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#include<utility>
#include<string>
#include<cstring>
#include<set>
#include<cmath>
#include<vector>
#include<fstream>
#include<map>
#include<list>
#include<algorithm>
#define SIZE 263000

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

struct node{
	LLD total, lazyAdd;
	int index;
}segmentTree[SIZE];

int findTreeSize(int n){
	int res = 1;
	while(res < n)
		res <<= 1;
	return (res << 1);
}

void initNode(int index){
	segmentTree[index].lazyAdd = 0;
	segmentTree[index].total = 0;
	segmentTree[index].index = index;
}

void buildTreeUtil(int left, int right, int index){
	if(left == right){
		initNode(index);
		return;
	}
	int mid = (left + right) / 2;
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;
	buildTreeUtil(left, mid, leftChild);
	buildTreeUtil(mid + 1, right, rightChild);
	initNode(index);
}

void buildTree(int n){
	buildTreeUtil(0, n-1, 0);
}

void displayNode(int index){
	cout << segmentTree[index].index << " " << segmentTree[index].total << " " << segmentTree[index].lazyAdd << endl;
}

void displayTreeUtil(int left, int right, int index){
	if(left == right){
		displayNode(index);
		return;
	}
	int mid = (left + right) / 2;
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;
	displayTreeUtil(left, mid, leftChild);
	displayTreeUtil(mid + 1, right, rightChild);
	displayNode(index);
}

void displayTree(int n){
	displayTreeUtil(0, n-1, 0);
	system("pause");
}

bool leafNode(int left, int right){
	return left == right;
}

bool remainingPrevUpdates(int index){
	return (segmentTree[index].lazyAdd > 0);
}

void updateChildLazyValues(int index, LLD value){
	int lChild = 2 * index + 1;
	int rChild = 2 * index + 2;
	segmentTree[lChild].lazyAdd += value;
	segmentTree[rChild].lazyAdd += value;
}

void updatePrevious(int left, int right, int index){
	LLD nodes = (LLD)(right - left + 1);
	segmentTree[index].total += (nodes * segmentTree[index].lazyAdd);
	if(!leafNode(left, right))
		updateChildLazyValues(index, segmentTree[index].lazyAdd);
	segmentTree[index].lazyAdd = 0;
}

LLD queryTreeUtil(int left, int right, int lRange, int rRange, int index){
	if(left <= lRange && rRange <= right){
		if(remainingPrevUpdates(index))
			updatePrevious(left, right, index);
	}
	if(left == lRange && rRange == right)
		return segmentTree[index].total;
	int mid = (left + right) / 2;
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;
	if(rRange <= mid)
		return queryTreeUtil(left, mid, lRange, rRange, leftChild);
	if(lRange > mid)
		return queryTreeUtil(mid + 1, right, lRange, rRange, rightChild);
	LLD result = queryTreeUtil(left, mid, lRange, mid, leftChild);
	result += queryTreeUtil(mid + 1, right, mid + 1, rRange, rightChild);
	return result;
}

LLD queryTree(int n, int x, int y){
	return queryTreeUtil(0, n-1, x, y, 0);
}

LLD updateNode(int left, int right, int index, LLD value){
	LLD nodes = (LLD)(right - left + 1);
	LLD totalValue = nodes * value;
	segmentTree[index].total += totalValue;
	if(!leafNode(left, right))
		updateChildLazyValues(index, value);
	return totalValue;
}

LLD updateTreeUtil(int left, int right, int lRange, int rRange, LLD value, int index){
	if(left <= lRange && rRange <= right){
		if(remainingPrevUpdates(index))
			updatePrevious(left, right, index);
	}
	if(left == lRange && rRange == right){
		return updateNode(left, right, index, value);
	}
	LLD result;
	int mid = (left + right) / 2;
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;
	if(rRange <= mid){
		result = updateTreeUtil(left, mid, lRange, rRange, value, leftChild);
		segmentTree[index].total += result;
		return result;
	}
	if(lRange > mid){
		result = updateTreeUtil(mid + 1, right, lRange, rRange, value, rightChild);
		segmentTree[index].total += result;
		return result;
	}
	result = updateTreeUtil(left, mid, lRange, mid, value, leftChild);
	result += updateTreeUtil(mid + 1, right, mid + 1, rRange, value, rightChild);
	segmentTree[index].total += result;
	return result;
}

void updateTree(int n, int x, int y, LLD value){
	updateTreeUtil(0, n-1, x, y, value, 0);
}

int main(){
	
	int opt, x, y, t, n, c, treeSize;
	LLD value;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &c);
		treeSize = findTreeSize(n);
		buildTree(n);
//		displayTree(n);
		while(c--){
			scanf("%d%d%d", &opt, &x, &y);
			x--;y--;
			if(opt == 1){
				printf("%lld\n", queryTree(n, x, y));
				//displayTree(n);
				continue;
			}
			scanf("%lld", &value);
			updateTree(n, x, y, value);
			//displayTree(n);
		}
	}
    return 0;
}
