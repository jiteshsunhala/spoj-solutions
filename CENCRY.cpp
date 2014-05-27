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
#define size 50001
#define isvowel(x) (x == 0 || x == 4 || x == 8 || x == 14 || x == 20)
typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

int main(){
	
	char vows[] = "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou";
	char cons[] = "bcdfghjklmnpqrstvwxyzbcdfghjklmnpqrstvwxyzbcdfghjklmnpqrstvwxyzbcdfghjklmnpqrstvwxyzbcdfghjklmnpqrstvwxyz";
	
	int pos[] = {0, 0, 1, 2, 1,
				3, 4, 5, 2, 6,
				7, 8, 9, 10, 3,
				11, 12, 13, 14, 15,
				4, 16, 17, 18, 19,
				20};
	
	char s[size];
	int t, len;
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		int freq[26] = {0};
		len = strlen(s);
		
		for(int i=0;i<len;i++){
			int c = s[i] - 97;
			if(isvowel(c)){
				int rep = ((freq[c] * 5 + pos[c]) % 105);
				freq[c] = (freq[c] + 1) % 21;
				printf("%c", cons[rep]);
			}
			else{
				int rep = ((freq[c] * 21 + pos[c]) % 105);
				freq[c] = (freq[c] + 1) % 5;
				printf("%c", vows[rep]);
			}
		}
		printf("\n");
	}
    return 0;
}
