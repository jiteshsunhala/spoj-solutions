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
#define SIZE 100000
#define INF 100000000

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int arr[SIZE];

vector<int> noOfPeople(int n, int p){
	int totalPeople = 0, curDistance = 0, minPeople = 0, dis = 0;
	vector<int> v(2);
	for(int i=0, start=0;i<n;i++){
		if(totalPeople + arr[i] <= p){
			totalPeople += arr[i];
			curDistance++;
		}
		else{
			while(totalPeople + arr[i] > p){
				totalPeople -= arr[start];
				start++;
				curDistance--;
			}
			totalPeople += arr[i];
			curDistance++;
		}
		if(dis < curDistance || (dis == curDistance && minPeople > totalPeople)){
			dis = curDistance;
			minPeople = totalPeople;
		}
	}
	v[0] = minPeople;
	v[1] = dis;
	return v;
}

int main(){
	
	int n, p, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &p);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		vector<int> v = noOfPeople(n, p);
		printf("%d %d\n", v[0], v[1]);
	}
	return 0;
}
