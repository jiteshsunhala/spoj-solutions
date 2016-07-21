#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int a, b, c, d, e, w;
	cin >> a >> b >> c >> d >> e >> w;
	if(w % 2){
		printf("NO");
		return 0;
	}
	int total = a + (b * 2) + (c * 4) + (d * 8) + (e * 16);
	if(w <= total)
		printf("YES");
	else
		printf("NO");
	return 0;
}