#include <iostream>
#include <cstdio>
#define SIZE 100000
#define LLD long long int

using namespace std;

int main(){
	int t, n;
	LLD a[SIZE], b[SIZE];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%lld", &a[i]);
		for(int i=0;i<n;i++)
			scanf("%lld", &b[i]);
		LLD last = min(a[0], b[0]);
		bool found = true;
		for(int i=1;i<n;i++){
			if(last <= a[i] && last <= b[i])
				last = min(a[i], b[i]);
			else if(last <= a[i])
				last = a[i];
			else if(last <= b[i])
				last = b[i];
			else{
				found = false;
				break;
			}
		}
		printf("%s\n", found ? "YES" : "NO");
	}
	return 0;
}