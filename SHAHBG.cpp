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

int main(){
	
	int q, n, cnt=0;
	bool arr[20001];
	scanf("%d", &q);
	fill(arr, arr + 20001, false);
	while(q--){
		scanf("%d", &n);
		if(n == 1){
			if(!arr[n+1])
				cnt++;
		}
		else if(n == 20000){
			if(!arr[n-1])
				cnt++;
		}
		else{
			if(!arr[n-1] && !arr[n+1])
				cnt++;
			else if(arr[n-1] && arr[n+1])
				cnt--;
		}
		arr[n] = true;
		cout << cnt << endl;
	}
	cout << "Justice\n";
    return 0;
}
