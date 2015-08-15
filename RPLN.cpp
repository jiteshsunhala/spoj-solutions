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
#define MAX_NODES 263000
#define SIZE 100000

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

struct node{
	int lRange, rRange, minValue;
}tree[MAX_NODES];

int arr[SIZE];

void initNode(int left, int right, int idx, int value){
	tree[idx].lRange = left;
	tree[idx].rRange = right;
	tree[idx].minValue = value;
}

void display(int idx){
	cout << idx << " " << tree[idx].lRange << " " << tree[idx].rRange << " " << tree[idx].minValue << endl;
}

int prepareTree(int left, int right, int idx){
	if(left == right){
		initNode(left, right, idx, arr[left]);
		/*display(idx);
		system("pause");*/
		return 1;
	}
	int mid = (left + right) >> 1;
	int leftChild = 2 * idx + 1;
	int rightChild = 2 * idx + 2;
	int leftNode = prepareTree(left, mid, leftChild);
	int rightNode = prepareTree(mid + 1, right, rightChild);
	initNode(left, right, idx, min(tree[leftChild].minValue, tree[rightChild].minValue));
/*	display(idx);
	cout << leftNode << " " << rightNode << endl;
	system("pause");*/
	return leftNode + rightNode + 1;
}

int findMinimum(int leftR, int rightR, int idx){
	int left = tree[idx].lRange;
	int right = tree[idx].rRange;
	if(leftR == left && rightR == right)
		return tree[idx].minValue;
	int mid = (left + right) / 2;
	int leftChild = 2 * idx + 1;
	int rightChild =  2 * idx + 2;
	if(rightR <= mid)
		return findMinimum(leftR, rightR, leftChild);
	if(leftR >= mid + 1)
		return findMinimum(leftR, rightR, rightChild);
	return min(findMinimum(leftR, mid, leftChild), findMinimum(mid + 1, rightR, rightChild));
}

int main(){
	
	int x, y, t, n, q, sc = 0;
	scanf("%d", &t);
	while(t--){
		printf("Scenario #%d:\n", ++sc);
		scanf("%d%d", &n, &q);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		int treeSize = prepareTree(0, n-1, 0);
		while(q--){
			scanf("%d%d", &x, &y);
			x--;
			y--;
			printf("%d\n", findMinimum(x, y, 0));
		}
	}
    return 0;
}
