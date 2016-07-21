#include <iostream>
#include <cstdio>

using namespace std;

int findMinutes(string s){
	int hours = 10 * (s[0] - 48) + (s[1] - 48);
	int minutes = 10 * (s[3] - 48) + (s[4] - 48);
	return hours * 60 + minutes;
}

int findOverlappingTimes(int startTime, int endTime){
	int times[] = {0, 66, 131, 197, 262, 328, 393, 459, 524, 590, 655, 720, 786, 851, 917, 982, 1048, 1113, 1179, 1244, 1310, 1375};
	int cnt = 0;
	for(int i=0;i<22;i++)
		if(startTime < times[i] && times[i] <= endTime)
			cnt++;
	return cnt;
}

int main(){
	int t;
	string startTime, endTime;
	scanf("%d", &t);
	while(t--){
		cin >> startTime >> endTime;
		printf("%d\n", findOverlappingTimes(findMinutes(startTime), findMinutes(endTime)));
	}
}