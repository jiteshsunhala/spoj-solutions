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
#define SIZE 1000009

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;
double arr[SIZE];

bool male(int node){
	return (node % 2 == 0);
}

void traverseUp(int node){
	int parent;
	while(node != 1){
		parent = node >> 1;
		if(male(parent))
			arr[parent] = 2 * arr[node];
		else{
			if(male(node))
				arr[parent] = 2 * arr[node];
			else
				arr[parent] = 4 * arr[node];
		}
		node = parent;
	}
}

void traverseDown(int size){
	int lchild, rchild;
	for(int i=1;i<=size;i++){
		lchild = 2 * i;
		rchild = 2 * i + 1;
		if(male(i)){
			if(lchild <= size && arr[lchild] == -1)
				arr[lchild] = arr[i] / 2;
			if(rchild <= size && arr[rchild] == -1)
				arr[rchild] = arr[i] / 2;
		}
		else{
			if(lchild <= size && arr[lchild] == -1)
				arr[lchild] = arr[i] / 2;
			if(rchild <= size && arr[rchild] == -1)
				arr[rchild] = arr[i] / 4;
		}
	}
}

int main(){
	
	int t, x, y;
	double w;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%lf", &x, &y, &w);
		fill(arr, arr + max(x, y) + 1, -1);
		arr[x] = w;
		traverseUp(x);
		traverseDown(max(x, y));
		printf("%.6lf\n", arr[y]);
	}
    return 0;
}
