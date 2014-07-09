#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int rounds, n, p[100], r[100], s[100];
string sven, frnd;
void find_score(){
	int sc=0, msc=0;
	for(int i=0;i<rounds;i++){
		if(sven[i] == 'S') sc += (2 * p[i] + s[i]);
		else if(sven[i] == 'P') sc += (2 * r[i] + p[i]);
		else sc += (2 * s[i] + r[i]);
		msc += max((2 * p[i] + s[i]), max((2 * r[i] + p[i]), (2 * s[i] + r[i])));
	}
	printf("%d\n%d\n", sc, msc);
}
int main(){
	
	fill(p, p+100, 0);
	fill(r, r+100, 0);
	fill(s, s+100, 0);
	scanf("%d", &rounds);
	cin >> sven;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		cin >> frnd;
		for(int i=0;i<rounds;i++)
			if(frnd[i] == 'S') s[i]++;
			else if(frnd[i] == 'P') p[i]++;
			else r[i]++;
	}
	find_score();
    return 0;
}
