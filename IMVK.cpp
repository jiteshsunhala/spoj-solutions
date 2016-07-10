#include <iostream>
#include <cstdio>

using namespace std;

int modulusString(string s, int n){
	int rem = 0;
	for(int i=0;i<s.length();i++){
		rem *= 10;
		rem += (s[i] - 48);
		rem %= 495;
	}
	return rem;
}

int main(){
	int t;
	string s;
	scanf("%d", &t);
	while(t--){
		cin >> s;
		printf("%s\n", (modulusString(s, 495) == 0 ? "yes" : "no"));
	}
	return 0;
}
