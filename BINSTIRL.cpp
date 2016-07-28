#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int t, n, m;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		if((n-m) & (m-1)/2)
			cout << "0" << endl;
		else cout << "1" << endl;
	}
}