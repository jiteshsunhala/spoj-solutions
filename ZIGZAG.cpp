#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
using namespace std;

void next_cell(long long int *x, long long int *y, char c){
	if(c == 'D')
		(*x)++;
	else if(c == 'U')
		(*x)--;
	else if(c == 'R')
		(*y)++;
	else
		(*y)--;
}

int main(){
	
	long long int total, n, k, sum, x = 0, y = 0, value, final = 1;
	char c;
	scanf("%lld%lld%c", &n, &k, &c);
	for(int i=0;i<k;i++){
		scanf("%c", &c);
		next_cell(&x, &y, c);
		sum = x+y;
		sum++;
		total = (sum * (sum + 1) / 2);
		sum--;
		if(sum % 2 == 0){
			value = total - (sum - y);
			final += value;
		}
		else{
			value = total - (sum - x);
			final += value;
		}
	}
	printf("%lld", final);
    return 0;
}
