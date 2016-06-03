#include<iostream>
#include<cstdio>
#define SIZE 100005

using namespace std;

int main(){
	int t, n, m, pos, cas=0;
	bool arr[SIZE];
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		fill(arr, arr + n + 1, false);
		while(m--){
			scanf("%d", &pos);
			arr[pos - 1] = arr[pos] = arr[pos + 1] = true;
		}
		int cnt = 0;
		for(int i=1;i<=n;i++)
			cnt += (arr[i] ? 1 : 0);
		printf("Case %d: %d\n", ++cas, cnt);
	}
	return 0;
}
