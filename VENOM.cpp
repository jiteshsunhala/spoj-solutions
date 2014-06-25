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

vector<LLD> find_root(int h, int p, int a){
	vector<LLD> res;
	double A = (double)p, B = (double)(p - 2 * a), C = (double)(-2 * h);
	double D = sqrt(B * B - 4 * A * C);
	
	double first = (-B + D) / (2 * A);
	double second = (-B - D) / (2 * A);
	
	if(first < 0)
		res.push_back((LLD)(floor(second)));
	else if(second < 0)
		res.push_back((LLD)(floor(first)));
	return res;
}

LLD find_val(LLD h, LLD p, LLD a, LLD time){
	LLD n = time >> 1, m = time - n;
	return (h - (p * ((m * (m + 1)) >> 1)) + (a * n));
}

LLD find_time(LLD h, LLD p, LLD a){
	vector<LLD> roots = find_root(h, p, a);
	/*for(int i=0;i<roots.size();i++)
		cout << roots[i] << endl;*/
	LLD val1 = (roots[0] << 1) - 1;
	LLD val2 = (roots[0] << 1) + 1;
	
	LLD time1 = min(val1, val2);
	LLD time2 = max(val1, val2);
	
	if(time1 > 0 && find_val(h, p, a, time1) <= 0)
		return time1;
	return time2;
	
	return 0;
}

int main(){
	
	LLD t, a, h, p;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld%lld%lld", &h, &p, &a);
		printf("%lld\n", find_time(h, p, a));
	}
    return 0;
}
