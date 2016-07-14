#include <iostream>
#include <cstdio>
#define SIZE 1000001

using namespace std;

bool win[SIZE];
int squares[1001];

int main(){
	fill(win, win + SIZE, false);
	win[0] = false;
	for(int i=1;i<1001;i++)
		squares[i] = i * i;
	for(int i=1;i<SIZE;i++){
		for(int j=1;squares[j] <= i;j++){
			win[i] |= (!win[i - squares[j]]);
			if(win[i])
				break;
		}
	}
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%s\n", win[n] ? "Win" : "Lose");
	}
	return 0;
}