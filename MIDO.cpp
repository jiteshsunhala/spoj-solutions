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

int sc1 = 0, sc2 = 0, dm, ds, n, team, m, s, beginm = 0, begins = 0, fm = 0, fs = 0, sm = 0, ss = 0;
char str[10];

void find_time(){
	m = 10 * (str[0] - 48) + (str[1] - 48);
	s = 10 * (str[3] - 48) + (str[4] - 48);
}

void find_difference(){
	
	int ts = s, tm = m;
	if(ts < begins){
		tm -= 1;
		ts += 60;
	}
	
	ds = ts - begins;
	dm = tm - beginm;
	
	begins = s;
	beginm = m;
}

void prepare_string(int tm, int ts){
	char str[10];
	
	if(tm < 10){
		str[0] = '0';
		str[1] = tm + 48;
	}
	else{
		str[1] = (tm % 10) + 48;
		tm /= 10;
		str[0] = tm + 48;
	}
	str[2] = ':';
	if(ts < 10){
		str[3] = '0';
		str[4] = ts + 48;
	}
	else{
		str[4] = (ts % 10) + 48;
		ts /= 10;
		str[3] = ts + 48;
	}
	str[5] = 0;
	printf("%s\n", str);
}

int main(){

	scanf("%d", &n);
	while(n--){
		scanf("%d%s", &team, str);
		find_time();
		
		if(team == 1){
			if(sc1 == sc2)
				find_difference();
			sc1++;
			if(sc1 == sc2){
				find_difference();
				ss += ds;
				sm += (ss / 60) + dm;
				ss %= 60;
			}
		}
		else{
			if(sc1 == sc2)
				find_difference();
			sc2++;
			if(sc1 == sc2){
				find_difference();
				fs += ds;
				fm += (fs / 60) + dm;
				fs %= 60;
			}
		}
	}
	
	if(sc1 > sc2){
		s = 0;
		m = 48;
		find_difference();
		fs += ds;
		fm += (fs / 60) + dm;
		fs %= 60;
	}
	else if(sc2 > sc1){
		s = 0;
		m = 48;
		find_difference();
		ss += ds;
		sm += (ss / 60) + dm;
		ss %= 60;
	}
	
	prepare_string(fm, fs);
	prepare_string(sm, ss);
	system("pause");
    return 0;
}
