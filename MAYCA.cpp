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

string haabMonth[] = {	"pop", "no", "zip", "zotz", "tzec", "xul", 
						"yoxkin", "mol", "chen", "yax", "zac", "ceh", 
						"mac", "kankin", "muan", "pax", "koyab", "cumhu", 
						"uayet"};
						
string tzolkinNames[] = {	"imix", "ik", "akbal", "kan", "chicchan",
							"cimi", "manik", "lamat", "muluk", "ok", 
							"chuen", "eb", "ben", "ix", "mem",
							"cib", "caban", "eznab", "canac", "ahau"};

int noOfHaabDays(string m){
	int days = 0, idx = 0;
	while(m != haabMonth[idx]){
		days += 20;
		idx++;
	}
	return days;
}

int findHaabDays(int d, string month, int y){
	int totalDays = y * 365;
	totalDays += noOfHaabDays(month);
	totalDays += d + 1;
	return totalDays;
}

void convertToTzolkin(int days){
	int year = (days - 1) / 260;
	days %= 260;
	int day = days % 13;
	if(day == 0)
		day = 13;
	days = (days + 19) % 20;
	string tzolkinName = tzolkinNames[days];
	printf("%d %s %d\n", day, tzolkinName.c_str(), year);
}

int main(){
	
	int t, nDay, year, totalDays;
	char s[10];
	string month;
	scanf("%d", &t);
	printf("%d\n", t);
	while(t--){
		scanf("%d. %s %d", &nDay, s, &year);
		month = s;
		totalDays = findHaabDays(nDay, month, year);
		convertToTzolkin(totalDays);
	}
    return 0;
}
