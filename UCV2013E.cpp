#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#define mod 1000000007
using namespace std;

void input(int a[50], int n){
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
}

void difference(int a[50], int b[50], int c[50], int n){
	for(int i=0;i<n;i++)
		c[i] = b[i] - a[i];
}

bool zero(int a[50], int n){
	for(int i=0;i<n;i++)
		if(a[i])
			return false;
	return true;
}

int set_arr(int a[500], int i, int n){
	while(n >= 1)
		a[i++] = n--;
	return i;
}

int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main(){
	
	int a[50], b[50], diff[50], n, num[500], den[500], inum, iden, sum;
	long long int prod;
	while(true){
		scanf("%d", &n);
		if(!n)
			break;
		inum = iden = sum = 0;
		prod = 1;
		input(a, n);
		input(b, n);
		difference(a, b, diff, n);
		if(zero(diff, n))
			printf("1\n");
		else{
			sum = 0;
			for(int i=0;i<n;i++){
				sum += diff[i];
				iden = set_arr(den, iden, diff[i]);
			}
			inum = set_arr(num, inum, sum);
			
			for(int i=0;i<inum;i++){
				int j=0;
				while(den[i] != 1){
					while(num[j] == 1)
						j++;
					int d = gcd(num[j], den[i]);
					num[j] /= d;
					den[i] /= d;
					j++;
				}
			}
			
			for(int i=0;i<inum;i++)
				prod = ((prod % mod) * (num[i] % mod)) % mod;
			cout << prod << "\n";
		}
	}
    return 0;
}
