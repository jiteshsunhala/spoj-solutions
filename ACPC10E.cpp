#include<cstdio>
typedef long long int LLD;
using namespace std;

LLD no_of_1;

LLD mylog2(LLD teams){
	LLD cnt = 0;
	while(teams){
		if(teams & 1)
			no_of_1++;
		cnt++;
		teams = teams >> 1;
	}
	return cnt - 1;
}

int main(){
	
	LLD teams, games, g, t, a, d, mylog, mypow;
	while(1){
		scanf("%lld%lld%lld%lld", &g, &t, &a, &d);
		if(g == -1)
			break;
		teams = games = 0;
		games = (t * (t-1) /2) * g;
		
		teams = a * g + d;
		no_of_1 = 0;
		mylog = mylog2(teams);
		if(no_of_1 == 1){
			mypow = mylog;
			teams = 0;
		}
		else{
			mypow = mylog + 1;
			teams = ((LLD)(1) << (mylog + 1)) - teams;
		}
		games+=(((LLD)(1) << (mypow)) - 1);
		printf("%lld*%lld/%lld+%lld=%lld+%lld\n", g, a, t, d, games, teams);
	}
    return 0;
}
