#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int main(){
	char str[300001], *ch;
	int t, last, cnt, max, l, len[1000], i, j, k;
	scanf("%d", &t);
	cin.getline(str, 300000);
	while(t--){
		cin.getline(str, 300000);
		if(strlen(str) == 0)
			continue;
		ch = strtok(str, " \t\r");
		i=0;
		while(ch != NULL){
			len[i++] = strlen(ch);
			ch = strtok(NULL, " \t\r");
		}
		max = 0;
		for(j=0;j<i;){
			l = len[j];
			cnt = 1;
			for(k=j+1;k<i && len[k] == l;k++){
				cnt++;
			}
			if(max < cnt)
				max = cnt;
			j = k;
		}
		printf("%d\n", max);
	}
	return 0;
}
