#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
using namespace std;

int a[1000][1000];

int main(){
	
	int r, ans1, ans2, test = 0;
	while(true){
		scanf("%d", &r);
		if(r == 0)
			break;
		ans1 = 0;
		for(int i=0;i<r;i++){
			for(int j=0;j<r;j++){
				scanf("%d", &a[i][j]);
				ans1 += a[i][j];
			}
		}
		ans2 = 0;
		for(int i=0;i<r;i++){
			int pay = 0, rcv = 0;
			for(int j=0;j<r;j++)
				pay += a[i][j];
			for(int j=0;j<r;j++)
				rcv += a[j][i];
			if(pay >= rcv)
				ans2 += (pay - rcv);
		}
		printf("%d. %d %d\n", ++test, ans1, ans2);
	}
    return 0;
}
