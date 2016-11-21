#include <iostream>
#include <cstdio>
#define SIZE 30005
#define MAX_TREE_SIZE 66000

using namespace std;

struct node{
	int leftOpen, leftClose, rightOpen, rightClose, pairLeftRight, remainingOpen, remainingClose;
} segmentTree[MAX_TREE_SIZE];

char s[SIZE];

node getNode(int position){
	node tempNode;
	tempNode.leftOpen = 0;
	tempNode.remainingOpen = 0;
	if(s[position] == '('){
		tempNode.leftOpen = 1;
		tempNode.remainingOpen = 1;
	}
	tempNode.leftClose = 0;
	tempNode.remainingClose = 0;
	if(s[position] == ')'){
		tempNode.leftClose = 1;
		tempNode.remainingClose = 1;
	}
	tempNode.rightOpen = 0;
	tempNode.rightClose = 0;
	tempNode.pairLeftRight = 0;
	return tempNode;
}

node getNode(int leftIndex, int rightIndex){
	node tempNode, leftNode = segmentTree[leftIndex], rightNode = segmentTree[rightIndex];
	tempNode.leftOpen = leftNode.remainingOpen;
	tempNode.leftClose = leftNode.remainingClose;
	tempNode.rightOpen = rightNode.remainingOpen;
	tempNode.rightClose = rightNode.remainingClose;
	tempNode.pairLeftRight = min(tempNode.leftOpen, tempNode.rightClose);
	tempNode.remainingOpen = tempNode.leftOpen + tempNode.rightOpen - tempNode.pairLeftRight;
	tempNode.remainingClose = tempNode.leftClose + tempNode.rightClose - tempNode.pairLeftRight;
	return tempNode;
}

void displayNode(int x, int y, int index){
	cout 	<< "x: " << x
			<< "\ty: " << y
			<< "\tindex: " << index
			<< "\tleftOpen: " << segmentTree[index].leftOpen
			<< "\tleftClose: " << segmentTree[index].leftClose
			<< "\trightOpen: " << segmentTree[index].rightOpen
			<< "\trightClose: " << segmentTree[index].rightClose
			<< "\tpairLeftRight: " << segmentTree[index].pairLeftRight
			<< "\tremainingOpen: " << segmentTree[index].remainingOpen
			<< "\tremainingClose: " << segmentTree[index].remainingClose
			<< endl;
}

void prepareTreeUtil(int left, int right, int index){
	if(left == right){
		segmentTree[index] = getNode(left);
		return;
	}
	int mid = (left + right) / 2;
	int leftChild = (index << 1) + 1;
	int rightChild = (index + 1) << 1;
	prepareTreeUtil(left, mid, leftChild);
	prepareTreeUtil(mid + 1, right, rightChild);
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

void updateTreeUtil(int x, int left, int right, int index){
	if(x == left && x == right){
		s[x] = (s[x] == '(' ? ')' : '(');
		segmentTree[index] = getNode(x);
		return;
	}
	int mid = (left + right) >> 1;
	int leftChild = (index << 1) + 1;
	int rightChild = (index + 1) << 1;
	if(x <= mid)
		updateTreeUtil(x, left, mid, leftChild);
	if(x > mid)
		updateTreeUtil(x, mid + 1, right, rightChild);
	segmentTree[index] = getNode(leftChild, rightChild);
}

void prepareTree(int n){
	prepareTreeUtil(0, n-1, 0);
}

void displayTree(int n){
	displayTreeUtil(0, n-1, 0);
}

bool queryTree(){
	return (segmentTree[0].remainingOpen == 0 && segmentTree[0].remainingClose == 0);
}

void updateTree(int x, int n){
	updateTreeUtil(x, 0, n-1, 0);
}

int main(){

	int test = 1, n, q, o;
	while(scanf("%d", &n) != EOF){
		printf("Test %d:\n", test++);
		scanf("%s", s);
		//cout << s << endl;
		prepareTree(n);
		//displayTree(n);
		scanf("%d", &q);
		while(q--){
			scanf("%d", &o);
			if(n % 2 == 1){
				if(!o)
					printf("NO\n");
				continue;
			}
			if(!o){
				printf("%s\n", queryTree() ? "YES" : "NO");
				continue;
			}
			updateTree(o-1, n);
			//cout << s << endl;
			//displayTree(n);
		}
	}
	return 0;
}