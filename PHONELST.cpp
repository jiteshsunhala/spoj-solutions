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

bool in(string s, string t){
	if(t.find(s) == 0)
		return true;
	return false;
}

int main(){
	
	string arr[40000];
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			cin >> arr[i];
		sort(arr, arr + n);
		bool flag = true;
		for(int i=0;i<n-1 && flag;i++){
			if(in(arr[i], arr[i+1]))
				flag = false;
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
    return 0;
}
