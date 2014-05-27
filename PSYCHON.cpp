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

bool psychon(int n){
	
	if(n == 1)
		return false;
	
	int evcnt = 0, odcnt = 0;
	int pow = 0;
	if(n % 2 == 0){
		while(n % 2 == 0){
			n /= 2;
			pow++;
		}
		if(pow % 2 == 0)
			evcnt++;
		else
			odcnt++;
	}

	for(int i=3;i<=sqrt(n);i+=2){
		pow = 0;
		if(n % i == 0){
			while(n % i == 0){
				n /= i;
				pow++;
			}
			if(pow % 2 == 0)
				evcnt++;
			else
				odcnt++;
		}
	}
	
	if(n != 1)
		odcnt++;
	return (evcnt > odcnt);
}

int main(){
	
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%s\n", (psychon(n) ? "Psycho Number" : "Ordinary Number"));
	}
    return 0;
}
