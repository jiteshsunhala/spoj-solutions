#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#define size 10000
#define mymax(x, y) ((x > y) ? (x) : (y))
using namespace std;

int main(){
	
	int sum1, sum2, total, x, y, a[size], b[size], n, m;
	while(1){
		scanf("%d", &n);
		if(!n)
			break;
		for(int i=0;i<n;i++)
			scanf("%d", &a[i]);
		scanf("%d", &m);
		for(int i=0;i<m;i++)
			scanf("%d", &b[i]);
		x = y = total = sum1 = sum2 = 0;
		
		while(x < n && y < m){
			if(a[x] < b[y]){
				sum1 += a[x];
				x++;
			}
			else if(a[x] > b[y]){
				sum2 += b[y];
				y++;
			}
			else{
				total += (mymax(sum1, sum2) + a[x]);
				sum1 = sum2 = 0;
				x++;
				y++;
			}
		}
		
		while(x < n){
			sum1 += a[x];
			x++;
		}
		
		while(y < m){
			sum2 += b[y];
			y++;
		}
		
		total += mymax(sum1, sum2);
		printf("%d\n", total);
	}
    //system("pause");
    return 0;
}
