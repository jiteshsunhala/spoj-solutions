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

#define VI vector<int>
#define VF vector<float>
#define VD vector<double>
#define VC vector<char>
#define VVI vector<VI>
#define VVF vector<VF>
#define VVD vector<VD>
#define VVC vector<VC>
#define SI set<int>
#define SF set<float>
#define SD set<double>
#define SC set<char>
#define SSI set<SI>
#define SSF set<SF>
#define SSD set<SD>
#define SSC set<SC>
#define STI stack<int>
#define STF stack<float>
#define STD stack<double>
#define STC stack<char>
#define STSTI stack<STI>
#define STSTF stack<STF>
#define STSTD stack<STD>
#define STSTC stack<STC>
#define size 10000

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

char primes[size];
bool visited[size];
int dis[size];

int find_prime(char primes[size])
{
    int i,j;
    primes[0]=primes[1]='0';
    for(i=2;i<size;i++)
        primes[i]='1';
    for(i=4;i<size;i+=2)
        primes[i]='0';
    for(i=3;i<=sqrt(size);i+=2)
        if(primes[i]=='1')
            for(j=i*3;j<size;j+=(i*2))
                primes[j]='0';
    return 0;
}

void display(queue<int> q){
	while(!q.empty()){
		int val = q.front();
		cout << val << ": " << dis[val] << endl;
		q.pop();
	}
	system("pause");
}

int get_next_num(int i, int j, int val){
	char a[5];
	int k=3;
	a[4] = 0;
	while(val){
		a[k--] = (val % 10) + 48;
		val /= 10;
	}
	a[i] = j + 48;
	return atoi(a);
}

int bfs(int a, int b){
	
	queue<int> q;
	int val;
	fill(visited, visited + size, false);
	fill(dis, dis + size, 1000000);
	q.push(a);
	dis[a] = 0;
	visited[a] = true;
	while(!q.empty()){
		val = q.front();
		q.pop();
		
		for(int i=0;i<4;i++){
			for(int j=0;j<10;j++){
				if(i || j){
					int nval = get_next_num(i, j, val);
					if(primes[nval] == '1' && !visited[nval]){
						dis[nval] = min(dis[val] + 1, dis[nval]);
						visited[nval] = true;
						q.push(nval);
					}
				}
			}
		}
		
		//display(q);
		
		if(val == b)
			return dis[val];
	}
}

int main(){
	
	find_prime(primes);
	
	int t, a, b;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &a, &b);
		printf("%d\n", bfs(a, b));
	}
    return 0;
}
