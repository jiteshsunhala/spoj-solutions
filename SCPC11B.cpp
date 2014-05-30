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

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int rem_miles, arr[2000], n, location;

bool forward(){
	location = 0;
	for(int i=0;i<n;i++){
		if(arr[i] > location)
			return false;
		location = arr[i];
		location = min(location + 200, 1422);
	}
	rem_miles = 200 - 1422 + arr[n-1];
	return true;
}

bool backward(){
	location = 1422 - rem_miles;
/*	for(int i=n-1;i>=0;i--){
		if(arr[i] < location)
			return false;
		location = arr[i];
		location = max(location - 200, 0);
	}
	return true;*/
	if(arr[n-1] >= location)
		return true;
	return false;
}

int main(){
	
	while(true){
		scanf("%d", &n);
		if(!n)
			break;
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + n);
		if(forward()){
			if(backward())
				printf("POSSIBLE\n");
			else
				printf("IMPOSSIBLE\n");
		}
		else
			printf("IMPOSSIBLE\n");
	}
    return 0;
}
