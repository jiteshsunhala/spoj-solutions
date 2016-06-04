#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<bool> visited;
vector< vector<int> > grph;
vector<int> money, budget;

int findBudget(int start){
	visited[start] = true;
	int amt = money[start];
	for(int i=0;i<grph[start].size();i++){
		int node = grph[start][i];
		if(!visited[node])
			amt += findBudget(node);
	}
	return amt;
}

int main(){
	int t, n, m, x, y, cas=0;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		grph.clear();
		visited.clear();
		money.clear();
		budget.clear();
		grph.resize(n + 1);
		visited.resize(n + 1);
		money.resize(n + 1);
		for(int i=1;i<=n;i++)
			scanf("%d", &money[i]);
		fill(visited.begin(), visited.end(), false);
		while(m--){
			scanf("%d%d", &x, &y);
			grph[x].push_back(y);
			grph[y].push_back(x);
		}
		int cnt = 0;
		for(int i=1;i<=n;i++){
			if(!visited[i]){
				budget.push_back(findBudget(i));
				cnt++;
			}
		}
		sort(budget.begin(), budget.end());
		printf("Case %d: %d\n", ++cas, cnt);
		for(int i=0;i<budget.size() - 1;i++)
			printf("%d ", budget[i]);
		printf("%d\n", budget[budget.size() - 1]);
	}
	return 0;
}
