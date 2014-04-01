#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
typedef long long int LLD;
using namespace std;

int main(){
	
	LLD n, d, f, b, m, total;
	while(true){
		scanf("%lld%lld%lld%lld", &d, &f, &b, &m);
		if(!d && !f && !b && !m)
			break;
		n = (f * (f + 1) / 2) + 1;
		total = n * b;
		if(total + m < d)
			printf("Farmer Cream will have %lld Bsf to spend.\n", d - total);
		else
			printf("The firm is trying to bankrupt Farmer Cream by %lld Bsf.\n", total + m - d);
	}
	
    system("pause");
    return 0;
}
