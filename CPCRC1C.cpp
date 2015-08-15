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

LLD sum_of_digits(LLD n){
	LLD sum = 0;
	while(n){
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}

LLD find_digit_sum(LLD n, LLD mul){
	if(n <= 0)
		return 0;
	LLD sum = 0;
	LLD last_digit = n % 10;
	LLD rem_part = n / 10;
	sum += ((last_digit * (last_digit + 1) / 2) * mul);
	LLD sod = sum_of_digits(rem_part);
	sum += (sod * (last_digit + 1) * mul);
	sum += (rem_part * 45 * mul);
	return sum + find_digit_sum(rem_part - 1, mul * 10);
}

int main(){
	
	LLD a, b;
	while(true){
		cin >> a >> b;
		if(a == -1 && b == -1)
			break;
		LLD sum1 = find_digit_sum(b, 1);
		LLD sum2 = find_digit_sum(a-1, 1);
		cout << sum1 - sum2 << endl;
	}
    return 0;
}
