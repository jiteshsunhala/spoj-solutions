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
	
	vector<int> row, col;
	int nr, nc, t, r, c;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &r, &c);
		row.resize(r-1);
		col.resize(c-1);
		for(int i=0;i<r-1;i++)
			scanf("%d", &row[i]);
		sort(row.begin(), row.end());
		for(int j=0;j<c-1;j++)
			scanf("%d", &col[j]);
		sort(col.begin(), col.end());
		nr = nc = 1;
		int total = 0;
		int i = row.size() - 1, j = col.size() - 1;
		while(i >= 0 && j >= 0){
			if(row[i] > col[j]){
				total += (row[i] * nc);
				i--;
				nr++;
			}
			else{
				total += (col[j] * nr);
				j--;
				nc++;
			}
		}
		while(i >= 0){
			total += (row[i] * nc);
			i--;
			nr++;
		}
		while(j >= 0){
			total += (col[j] * nr);
			j--;
			nc++;
		}
		cout << total << endl;
	}
	return 0;
}
