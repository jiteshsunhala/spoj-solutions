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
#define ARR_SIZE 200000

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

struct node{
	int startNum, startCount, endNum, endCount, maxFrequency;
}tree[SIZE];

int arr[ARR_SIZE];

void prepareNode(int curIdx, int x){
	tree[curIdx].startNum = arr[x];
	tree[curIdx].endNum = arr[x];
	tree[curIdx].startCount = 1;
	tree[curIdx].endCount = 1;
	tree[curIdx].maxFrequency = 1;
}

void prepareTreeUtil(int left, int right, int curIdx){
	if(left == right){
		prepareNode(curIdx, left);
		return;
	}
	int mid = (left + right) / 2;
	int leftChild = 2 * curIdx + 1;
	int rightChild = 2 * curIdx + 2;
	prepareTreeUtil(left, mid, leftChild);
	prepareTreeUtil(mid + 1, right, rightChild);
	tree[curIdx].startNum = tree[leftChild].startNum;
	tree[curIdx].endNum = tree[rightChild].endNum;
	tree[curIdx].startCount = ((tree[leftChild].startNum == tree[rightChild].startNum) ? 
								(tree[leftChild].startCount + tree[rightChild].startCount) : (tree[leftChild].startCount));
	tree[curIdx].endCount = ((tree[leftChild].endNum == tree[rightChild].endNum) ? 
							(tree[leftChild].endCount + tree[rightChild].endCount) : (tree[rightChild].endCount));
	int midCount = 0;
	if(tree[leftChild].endNum == tree[rightChild].startNum)
		midCount = tree[leftChild].endCount + tree[rightChild].startCount;
	tree[curIdx].maxFrequency = max(midCount, max(tree[leftChild].maxFrequency, tree[rightChild].maxFrequency));
}

void prepareTree(int n){
	prepareTreeUtil(0, n-1, 0);
}

void displayNode(int left, int right, int curIdx){
	cout << curIdx << " " << left << " " << right << " "
		<< tree[curIdx].startNum << " " << tree[curIdx].startCount << " "
		<< tree[curIdx].maxFrequency << " "
		<< tree[curIdx].endNum << " " << tree[curIdx].endCount << endl;
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
	system("pause");
}

node maxFrequencyUtil(int left, int right, int lRange, int rRange, int curIdx){
	if(left == lRange && right == rRange)
		return tree[curIdx];
	int mid = (left + right) / 2;
	int leftChild = 2 * curIdx + 1;
	int rightChild = 2 * curIdx + 2;
	if(mid >= rRange)
		return maxFrequencyUtil(left, mid, lRange, rRange, leftChild);
	if(mid + 1 <= lRange)
		return maxFrequencyUtil(mid + 1, right, lRange, rRange, rightChild);
	node leftMax = maxFrequencyUtil(left, mid, lRange, mid, leftChild);
	node rightMax = maxFrequencyUtil(mid + 1, right, mid + 1, rRange, rightChild);
	node result;
	result.startNum = leftMax.startNum;
	result.endNum = rightMax.endNum;
	result.startCount = ((leftMax.startNum == rightMax.startNum) ? 
								(leftMax.startCount + rightMax.startCount) : (leftMax.startCount));
	result.endCount = ((leftMax.endNum == rightMax.endNum) ? 
							(leftMax.endCount + rightMax.endCount) : (rightMax.endCount));
	int midCount = 0;
	if(leftMax.endNum == rightMax.startNum)
		midCount = leftMax.endCount + rightMax.startCount;
	result.maxFrequency = max(midCount, max(leftMax.maxFrequency, rightMax.maxFrequency));
	return result;
}

int findFrequency(int x, int y, int n){
	node result = maxFrequencyUtil(0, n-1, x, y, 0);
	return result.maxFrequency;
}

int main(){
	
	int n, q, x, y;
	while(true){
		scanf("%d", &n);
		if(!n)
			break;
		scanf("%d", &q);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		prepareTree(n);
		//displayTree(n);
		while(q--){
			scanf("%d%d", &x, &y);
			printf("%d\n", findFrequency(x-1, y-1, n));
		}
	}
    return 0;
}
