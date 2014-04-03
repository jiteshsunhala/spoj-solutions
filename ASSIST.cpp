#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#define size 33811
using namespace std;

void init(bool a[size]){
	for(int i=2;i<size;i++)
		a[i] = true;
}

int find_next(bool a[size], int idx){
	for(int i = idx+1; i < size;i++){
		if(a[i])
			return i;
	}
	return -1;
}

void update_array(bool a[size], int jump, int idx){
	int cnt = 0;
	for(int i = idx;i < size; i++){
		if(a[i]){
			cnt++;
			if(cnt == jump){
				cnt = 0;
				a[i] = false;
			}
		}
	}
}

int main(){
	
	bool a[size];
	init(a);
	int i=1, jump_val, arr[3001], k=1, n;
	while(true){
		i = find_next(a, i);
		if(i == -1)
			break;
		arr[k++] = i;
		jump_val = i;
		update_array(a, jump_val, i+1);
	}
	
	while(true){
		scanf("%d", &n);
		if(!n)
			break;
		printf("%d\n", arr[n]);
	}
    return 0;
}
