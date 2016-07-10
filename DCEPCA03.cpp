#include <iostream>
#include <cstdio>
#define SIZE 10001
#define LLD long long int

using namespace std;

LLD phi(int n)
{
     LLD result = n, i;
       for(i=2;i*i <= n;i++) 
       { 
         if (n % i == 0) 
         result -= result / i; 
         while (n % i == 0) 
         n /= i; 
       } 
       if (n > 1)
       result -= result / n; 
       return result; 
}

int main(){

	LLD arr[SIZE];
	arr[0] = 0;
	for(int i=1;i<SIZE;i++){
		arr[i] = phi(i);
		arr[i] += arr[i-1];
		//printf("%d: %lld\n", i, arr[i]);
	}
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%lld\n", arr[n] * arr[n]);
	}
	return 0;
}