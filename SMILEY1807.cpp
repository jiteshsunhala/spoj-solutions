#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main(){
	string str;
	cin >> str;
	vector<int> v(str.length()); 
	int one = -1, eight = -1, zero = -1, seven = -1, result = -1;
	for(int i=0;i<str.length();i++){
		v[i] = -1;
		switch(str[i]){
			case '1':
				if(one == -1)
					v[i] = 1;
				else
					v[i] = v[one] + 1;
				one = i;
				break;
			case '8':
				if(one == -1)
					continue;
				if(eight == -1)
					v[i] = v[one] + 1;
				else
					v[i] = max(v[one] + 1, v[eight] + 1);
				eight = i;
				break;
			case '0':
				if(eight == -1)
					continue;
				if(zero == -1)
					v[i] = v[eight] + 1;
				else
					v[i] = max(v[eight] + 1, v[zero] + 1);
				zero = i;
				break;
			case '7':
				if(zero == -1)
					continue;
				if(seven == -1)
					v[i] = v[zero] + 1;
				else
					v[i] = max(v[zero] + 1, v[seven] + 1);
				result = max(result, v[i]);
				seven = i;
				break;
		}
	}
	if(result == -1)
		result = 0;
	printf("\n%d\n", result);
}