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

int main(){
	
	int t, n, x, y, player, player2;
	vector< vector<int> > v;
	vector<bool> visited;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int m = (n * (n - 1)) >> 1;
		v.clear();
		v.resize(n + 1);
		visited.resize(n + 1);
		for(int i=0;i<m;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
		}
		int maxValue = -1, maxIdx = -1, value;
		for(int i=1;i<=n;i++){
			fill(visited.begin(), visited.end(), false);
			value = 0;
			for(int j=0;j<v[i].size();j++){
				player = v[i][j];
				if(!visited[player]){
					visited[player] = true;
					value++;
				}
				for(int k=0;k<v[player].size();k++){
					player2 = v[player][k];
					if(!visited[player2]){
						visited[player2] = true;
						value++;
					}
				}
			}
			if(value > maxValue){
				maxValue = value;
				maxIdx = i;
			}
		}
		printf("%d %d\n", maxIdx, maxValue);
	}
    return 0;
}
