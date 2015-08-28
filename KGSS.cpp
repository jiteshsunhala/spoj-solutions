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
#define SIZE 200000
#define MAX_TREE_SIZE 263000

typedef long long LLD;
typedef unsigned long long LLU;

using namespace std;

LLD arr[SIZE], n;

struct node{
	LLD firstMax, secondMax;
}tree[MAX_TREE_SIZE];

LLD findTreeSize(LLD n){
	LLD size = 1;
	while(size < n){
		size <<= 1;
	}
	return size << 1;
}

void prepareNode(LLD left, LLD right, LLD cur){
	int arr[4];
	arr[0] = tree[left].firstMax;
	arr[1] = tree[left].secondMax;
	arr[2] = tree[right].firstMax;
	arr[3] = tree[right].secondMax;
	sort(arr, arr + 4);
	tree[cur].firstMax = arr[3];
	tree[cur].secondMax = arr[2];
}

void buildTree(LLD left, LLD right, LLD curIdx, LLD noOfElements){
	if(left == right){
		tree[curIdx].firstMax = arr[left];
		tree[curIdx].secondMax = -INF;
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
	for(int i=0;i<n-1;i++){
		cout << i << " " << tree[i].firstMax << " " << tree[i].secondMax << endl;
	}
	system("pause");
}

void updateTree(LLD left, LLD right, LLD pos, LLD val, LLD curIdx){
	if(left == right && right == pos){
		tree[curIdx].firstMax = val;
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

node findMaxSum(LLD left, LLD right, LLD leftR, LLD rightR, LLD curIdx){
	if(left == leftR && right == rightR)
		return tree[curIdx];
	LLD mid = (left + right) / 2;
	if(rightR <= mid)
		return findMaxSum(left, mid, leftR, rightR, 2 * curIdx + 1);
	if(leftR >= mid + 1)
		return findMaxSum(mid + 1, right, leftR, rightR, 2 * curIdx + 2);
	node leftNode = findMaxSum(left, mid, leftR, mid, 2 * curIdx + 1);
	//cout << leftNode.firstMax << " " << leftNode.secondMax << endl;	
	node rightNode = findMaxSum(mid + 1, right, mid + 1, rightR, 2 * curIdx + 2);
	//cout << rightNode.firstMax << " " << rightNode.secondMax << endl;
	node tmpNode;
	int arr[4];
	arr[0] = leftNode.firstMax;
	arr[1] = leftNode.secondMax;
	arr[2] = rightNode.firstMax;
	arr[3] = rightNode.secondMax;
	sort(arr, arr + 4);
	tmpNode.firstMax = arr[3];
	tmpNode.secondMax = arr[2];
//	cout << tmpNode.firstMax << " " << tmpNode.secondMax << endl;
	return tmpNode;
}

LLD findRangeSum(LLD left, LLD right, LLD leftR, LLD rightR, LLD curIdx){
	node tmpNode = findMaxSum(left, right, leftR, rightR, curIdx);
	return tmpNode.firstMax + tmpNode.secondMax;
}

int main(){
	
	LLD m, x, y;
	char c;
	scanf("%lld", &n);
	for(LLD i=0;i<n;i++)
		scanf("%lld", &arr[i]);
	prepareTree(n-1, n);
	//display(findTreeSize(n));
	scanf("%lld", &m);
	while(m--){
		cin >> c;
		scanf("%lld%lld", &x, &y);
		if(c == 'Q')
			printf("%lld\n", findRangeSum(0, n-1, x-1, y-1, 0));
		else
			updateTree(0, n-1, x-1, y, 0);
	}
    return 0;
}
