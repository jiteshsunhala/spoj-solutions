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

map<int, int> mp, mq;

void prepare(int num, int val = 0){
	for(int i=2;i*i <= num;i++){
		while(num % i == 0){
			if(val == 0)
				mp[i]++;
			else
				mq[i]++;
			num /= i;
		}
	}
	
	if(num > 1 && val)
		mq[num]++;
	else
		mp[num]++;
	mp.erase(1);
	mq.erase(1);
}

void display(map<int, int> m, int val){
	cout << val << endl;
	map<int, int>::iterator it;
	for(it = m.begin();it != m.end();it++)
		cout << it->first << " " << it->second << endl;
}

LLD mypow(int val, int power){
	LLD res = 1;
	for(int i=0;i<power;i++)
		res *= val;
	return res;
}

int main(){
	
	LLD t, m, n, g, lcm;
	scanf("%lld", &t);
	while(t--){
		mp.clear();
		mq.clear();
		scanf("%lld %lld", &m, &n);
		prepare(m);
		prepare(n, 1);
		map<int, int>::iterator it;
		LLD res = 1;
		for(it = mp.begin();it != mp.end();){
			int val = it->first;
			if(it->second != mq[val]){
				int rep = max(it->second, mq[it->first]);
				res *= mypow(val, rep);
				mp.erase(val);
				mq.erase(val);
				it = mp.begin();
			}
			else
				it++;
		}
		for(it = mq.begin();it != mq.end();){
			int val = it->first;
			if(it->second != mp[val]){
				int rep = max(it->second, mp[it->first]);
				res *= mypow(val, rep);
				mp.erase(val);
				mq.erase(val);
				it = mq.begin();
			}
			else
				it++;
		}
		printf("%lld\n", res);
	}
    return 0;
}
