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

int main(){
	
	string s;
	int t, freq[26];
	scanf("%d", &t);
	getline(cin, s);
	while(t--){
		getline(cin, s);
		fill(freq, freq + 26, 0);
		for(int i=0;i<s.length();i++){
			if(s[i] >= 65 && s[i] <= 90)
				freq[s[i] - 65]++;
		}
		int maxf = 0, maxcnt = 0;
		char maxc;
		for(int i=0;i<26;i++){
			if(maxf < freq[i]){
				maxc = (char)i + 65;
				maxf = freq[i];
				maxcnt = 1;
			}
			else if(maxf == freq[i])
				maxcnt++;
		}
		if(maxcnt > 1 || maxcnt == 0)
			printf("NOT POSSIBLE\n");
		else{
			int diff = (maxc - 'E' + 26) % 26;
			for(int i=0;i<s.length();i++){
				if(s[i] >= 65 && s[i] <= 90){
					int val = s[i] - 65;
					int differ = (val - diff + 26) % 26;
					s[i] = (char) (differ + 65);
				}
			}
			cout << diff << " " << s << endl;
		}
	}
	
    return 0;
}
