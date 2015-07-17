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
#define INF 10000000
#define SIZE 50000
#define MAX_TREE_SIZE 132000

typedef long long LLD;
typedef unsigned long long LLU;

using namespace std;

LLD arr[SIZE], n;

struct node{
	LLD lRange, rRange, totalSum, maxSum, prefixSum, suffixSum;
}tree[MAX_TREE_SIZE];

LLD findTreeSize(LLD n){
	LLD size = 1;
	while(size < n){
		size <<= 1;
	}
	return size << 1;
}

void prepareNode(LLD left, LLD right, LLD cur){
	tree[cur].totalSum = tree[left].totalSum + tree[right].totalSum;
	tree[cur].prefixSum = max(tree[left].prefixSum, tree[left].totalSum + tree[right].prefixSum);
	tree[cur].suffixSum = max(tree[right].suffixSum, tree[left].suffixSum + tree[right].totalSum);
	tree[cur].maxSum = max(tree[cur].totalSum, 
							max(tree[left].maxSum, 
								max(tree[right].maxSum, 
									max(tree[cur].suffixSum, 
										max(tree[cur].prefixSum, tree[left].suffixSum + tree[right].prefixSum)
									)
								)
							)
						);
}

void buildTree(LLD left, LLD right, LLD curIdx, LLD noOfElements){
	tree[curIdx].lRange = left;
	tree[curIdx].rRange = right;
	if(left == right){
		tree[curIdx].maxSum = tree[curIdx].totalSum = tree[curIdx].prefixSum = tree[curIdx].suffixSum = arr[left];
		return;
	}
	LLD mid = (left + right) / 2;
	LLD leftChild = 2 * curIdx + 1;
	LLD rightChild = 2 * curIdx + 2;
	buildTree(left, mid, leftChild, noOfElements);
	buildTree(mid + 1, right, rightChild, noOfElements);
	prepareNode(leftChild, rightChild, curIdx);
}

void prepareTree(LLD n, LLD noOfElements){
	buildTree(0, n, 0, noOfElements);
}

void display(LLD n){
	for(LLD i=0;i<n-1;i++){
		cout << tree[i].lRange << " " << tree[i].rRange << " " << tree[i].maxSum << " " << tree[i].totalSum << " " << tree[i].prefixSum << " " << tree[i].suffixSum << endl;
	}
}

node findMaxSum(LLD left, LLD right, LLD leftR, LLD rightR, LLD curIdx){
	if(left == leftR && right == rightR)
		return tree[curIdx];
	LLD mid = (left + right) / 2;
	if(rightR <= mid)
		return findMaxSum(left, mid, leftR, rightR, 2 * curIdx + 1);
	if(leftR >= mid + 1)
		return findMaxSum(mid + 1, right, leftR, rightR, 2 * curIdx + 2);
	node leftNode = findMaxSum(left, mid, leftR, mid, 2 * curIdx + 1);
	node rightNode = findMaxSum(mid + 1, right, mid + 1, rightR, 2 * curIdx + 2);
	node tmpNode;
	tmpNode.lRange = leftR;
	tmpNode.rRange = rightR;
	tmpNode.totalSum = leftNode.totalSum + rightNode.totalSum;
	tmpNode.prefixSum = max(leftNode.prefixSum, leftNode.totalSum + rightNode.prefixSum);
	tmpNode.suffixSum = max(leftNode.suffixSum + rightNode.totalSum, rightNode.suffixSum);
	tmpNode.maxSum = max(tmpNode.totalSum, 
							max(leftNode.maxSum, 
								max(rightNode.maxSum, 
									max(tmpNode.suffixSum, 
										max(tmpNode.prefixSum, leftNode.suffixSum + rightNode.prefixSum)
									)
								)
							)
						);
	return tmpNode;
}

LLD findRangeSum(LLD left, LLD right, LLD leftR, LLD rightR, LLD curIdx){
	node tmpNode = findMaxSum(left, right, leftR, rightR, curIdx);
	return tmpNode.maxSum;
}

void updateTree(LLD left, LLD right, LLD pos, LLD val, LLD curIdx){
	if(left == right && right == pos){
		tree[curIdx].maxSum = tree[curIdx].totalSum = tree[curIdx].prefixSum = tree[curIdx].suffixSum = val;
		return;
	}
	LLD mid = (left + right) / 2;
	LLD leftChild = 2 * curIdx + 1;
	LLD rightChild = 2 * curIdx + 2;
	if(pos <= mid)
		updateTree(left, mid, pos, val, leftChild);
	else
		updateTree(mid + 1, right, pos, val, rightChild);
	prepareNode(leftChild, rightChild, curIdx);
}

int main(){
	
	LLD m, x, y, option;
	scanf("%lld", &n);
	for(LLD i=0;i<n;i++)
		scanf("%lld", &arr[i]);
	prepareTree(n-1, n);
	//sdisplay(findTreeSize(n));
	scanf("%lld", &m);
	while(m--){
		scanf("%lld%lld%lld", &option, &x, &y);
		if(option == 1)
			printf("%lld\n", findRangeSum(0, n-1, x-1, y-1, 0));
		else{
			updateTree(0, n-1, x-1, y, 0);
			//display(findTreeSize(n));
		}
	}
    return 0;
}
