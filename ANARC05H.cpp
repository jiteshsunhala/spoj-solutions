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

char s[30];

LLD findGroups(int leftSum, int start, int end, int sum){
	int total = 0, rightSum = sum;
	LLD groupsFormed = 0;
	for(int i=start;i<=end;i++){
		total += (s[i] - 48);
		rightSum -= (s[i] - 48);
		if(i == end && total >= leftSum)
			groupsFormed++;
		else if(total >= leftSum && total <= rightSum)
			groupsFormed += findGroups(total, i + 1, end, rightSum);
	}
	return groupsFormed;
}

int main(){
	int cas = 1;
	while(true){
		scanf("%s", s);
		int n = strlen(s);
		if(strcmp(s, "bye") == 0)
			break;
		int sum = 0;
		for(int i=0;i<n;i++)
			sum += (s[i] - 48);
		printf("%d. %lld\n", cas++, findGroups(0, 0, n-1, sum));
	}
    return 0;
}

