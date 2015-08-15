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
#define SIZE 505

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int mPriority[SIZE][SIZE], wPriority[SIZE][SIZE], mChoice[SIZE][SIZE], wChoice[SIZE][SIZE], nextPriority[SIZE], current[SIZE];

int main(){
	
	int t, n, w, m;
	queue<int> q;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=1;i<=n;i++){
			scanf("%d", &w);
			current[w] = -1;
			for(int j=1;j<=n;j++){
				scanf("%d", &wChoice[w][j]);
				wPriority[w][wChoice[w][j]] = j;
			}
		}
		for(int i=1;i<=n;i++){
			scanf("%d", &m);
			q.push(m);
			nextPriority[m] = 1;
			for(int j=1;j<=n;j++){
				scanf("%d", &mChoice[m][j]);
				mPriority[m][mChoice[m][j]] = j;
			}
		}
		while(!q.empty()){
			m = q.front();
			w = mChoice[m][nextPriority[m]++];
			if(current[w] == -1){
				current[w] = m;
				q.pop();
			}
			else if(wPriority[w][m] < wPriority[w][current[w]]){
				q.push(current[w]);
				current[w] = m;
				q.pop();
			}
		}
		for(int i=1;i<=n;i++)
			printf("%d %d\n", current[i], i);
	}
    return 0;
}
