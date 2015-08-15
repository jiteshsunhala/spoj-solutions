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
	
	string s, res, tmp;
	int n, len;
	bool length1;
	while(true){
		getline(cin, s);
		if(cin.fail())
			break;
		res = tmp = "";
		n = s.length();
		int i, j;
		length1 = false;
		for(i=0;i<n;){
			len = 0;
			for(j=i;j<n && s[j] == s[i] && len != 9;j++)
				len++;
			if(len == 1){
				length1 = true;
				if(s[i] == '1')
					tmp.append("11");
				else
					tmp.append(1, s[i]);
			}
			else{
				if(length1){
					res.append(1, '1');
					res.append(tmp);
					tmp = "";
					res.append(1, '1');
					length1 = false;
				}
				res.append(1, len + 48);
				res.append(1, s[i]);
			}
			i = i + len;
		}
		if(length1){
			res.append(1, '1');
			res.append(tmp);
			tmp = "";
			res.append(1, '1');
			length1 = false;
		}
		cout << res << endl;
	}
    return 0;
}
