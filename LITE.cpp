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
	int leftOn, rightOn, totalOn;
	bool lazyUpdate;
}tree[SIZE];

void prepareNode(int curIdx){
	tree[curIdx].lazyUpdate = false;
	tree[curIdx].leftOn = 0;
	tree[curIdx].rightOn = 0;
	tree[curIdx].totalOn = 0;
}

void prepareTreeUtil(int left, int right, int curIdx){
	if(left == right){
		prepareNode(curIdx);
		return;
	}
	int mid = (left + right) / 2;
	int leftChild = 2 * curIdx + 1;
	int rightChild = 2 * curIdx + 2;
	prepareTreeUtil(left, mid, leftChild);
	prepareTreeUtil(mid + 1, right, rightChild);
	prepareNode(curIdx);
}

void prepareTree(int n){
	prepareTreeUtil(0, n-1, 0);
}

bool leafNode(int left, int right){
	return (left == right);
}

void updateLazy(int left, int right, int curIdx){
	int mid = (left + right) / 2;
	int leftNodesCount = mid - left + 1;
	int rightNodesCount = right - mid;
	int leftChild = 2 * curIdx + 1;
	int rightChild = 2 * curIdx + 2;
	tree[curIdx].lazyUpdate = false;
	tree[curIdx].leftOn = leftNodesCount - tree[curIdx].leftOn;
	tree[curIdx].rightOn = rightNodesCount - tree[curIdx].rightOn;
	tree[curIdx].totalOn = tree[curIdx].leftOn + tree[curIdx].rightOn;
	if(!leafNode(left, right)){
		tree[leftChild].lazyUpdate ^= true;
		tree[rightChild].lazyUpdate ^= true;
	}
}

int updateNode(int left, int right, int curIdx){
	int mid = (left + right) / 2;
	int leftNodesCount = mid - left + 1;
	int rightNodesCount = right - mid;
	int leftChild = 2 * curIdx + 1;
	int rightChild = 2 * curIdx + 2;
	tree[curIdx].leftOn = leftNodesCount - tree[curIdx].leftOn;
	tree[curIdx].rightOn = rightNodesCount - tree[curIdx].rightOn;
	tree[curIdx].totalOn = tree[curIdx].leftOn + tree[curIdx].rightOn;
	if(!leafNode(left, right)){
		tree[leftChild].lazyUpdate ^= true;
		tree[rightChild].lazyUpdate ^= true;
	}
	return tree[curIdx].totalOn;
}

int updateTreeUtil(int left, int right, int lRange, int rRange, int curIdx){
	if(left <= lRange && rRange <= right){
		if(tree[curIdx].lazyUpdate)
			updateLazy(left, right, curIdx);
	}
	if(left == lRange && rRange == right)
		return updateNode(left, right, curIdx);
	int mid = (left + right) / 2;
	int leftChild = 2 * curIdx + 1;
	int rightChild = 2 * curIdx + 2;
	if(rRange <= mid){
		tree[curIdx].leftOn = updateTreeUtil(left, mid, lRange, rRange, leftChild);
		tree[curIdx].totalOn = tree[curIdx].leftOn + tree[curIdx].rightOn;
		return tree[curIdx].totalOn;
	}
	if(lRange > mid){
		tree[curIdx].rightOn = updateTreeUtil(mid + 1, right, lRange, rRange, rightChild);
		tree[curIdx].totalOn = tree[curIdx].leftOn + tree[curIdx].rightOn;
		return tree[curIdx].totalOn;
	}
	tree[curIdx].leftOn = updateTreeUtil(left, mid, lRange, mid, leftChild);
	tree[curIdx].rightOn = updateTreeUtil(mid + 1, right, mid + 1, rRange, rightChild);
	tree[curIdx].totalOn = tree[curIdx].leftOn + tree[curIdx].rightOn;
	return tree[curIdx].totalOn;
}

void updateTree(int x, int y, int n){
	updateTreeUtil(0, n-1, x, y, 0);
}

int queryTreeUtil(int left, int right, int lRange, int rRange, int curIdx){
	if(left <= lRange && rRange <= right){
		if(tree[curIdx].lazyUpdate)
			updateLazy(left, right, curIdx);
	}
	if(left == lRange && rRange == right)
		return tree[curIdx].totalOn;
	int mid = (left + right) / 2;
	int leftChild = 2 * curIdx + 1;
	int rightChild =  2 * curIdx + 2;
	if(rRange <= mid)
		return queryTreeUtil(left, mid, lRange, rRange, leftChild);
	if(mid < lRange)
		return queryTreeUtil(mid + 1, right, lRange, rRange, rightChild);
	int leftResult = queryTreeUtil(left, mid, lRange, mid, leftChild);
	int rightResult = queryTreeUtil(mid + 1, right, mid + 1, rRange, rightChild);
	return leftResult + rightResult;
}

int queryTree(int x, int y, int n){
	return queryTreeUtil(0, n-1, x, y, 0);
}

void displayNode(int left, int right, int curIdx){
	cout << curIdx << " " << left << " " << right << " "
		<< tree[curIdx].leftOn << " " << tree[curIdx].rightOn << " "
		<< tree[curIdx].totalOn << " " << tree[curIdx].lazyUpdate << endl;
}

void displayTreeUtil(int left, int right, int curIdx){
	if(left == right){
		displayNode(left, right, curIdx);
		return;
	}
	int mid = (left + right) / 2;
	int leftChild = 2 * curIdx + 1;
	int rightChild = 2 * curIdx + 2;
	displayTreeUtil(left, mid, leftChild);
	displayTreeUtil(mid + 1, right, rightChild);
	displayNode(left, right, curIdx);
}

void displayTree(int n){
	displayTreeUtil(0, n-1, 0);
}

int main(){
	
	int n, m, op, x, y;
	scanf("%d%d", &n, &m);
	prepareTree(n);
	while(m--){
		scanf("%d%d%d", &op, &x, &y);
		if(op == 0){
			updateTree(x-1, y-1, n);
	//		displayTree(n);
			continue;
		}
		printf("%d\n", queryTree(x-1, y-1, n));
	}
    return 0;
}
