#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int t, cntK, cntE, result;
	int arr[2001];
	string s;
	scanf("%d", &t);
	while(t--){
		cin >> s;
		fill(arr, arr + s.length(), 0);
		cntK = cntE = result = 0;
		for(int i=0;i<s.length();i++){
			switch(s[i]){
				case 'K':
				arr[i] = cntE;
				result += arr[i];
				cntK++;
				break;
				case 'E':
				arr[i] = cntK;
				cntE += arr[i];
				break;
				default:
				continue;
			}
		}
		printf("%d\n", result);
	}
	return 0;
}