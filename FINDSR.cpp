#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

vector<int> prepareLPSArray(string pattern){
	int len = pattern.length();
	vector<int> lsp(len);
	lsp[0] = 0;
	for(int j=0, i=1;i<len;i++){
		if(pattern[i] == pattern[j]){
			lsp[i] = j + 1;
			j++;
		}
		else{
			while(true){
				if(j == 0 || pattern[j] == pattern[i])
					break;
				j = lsp[j-1];
			}
			if(pattern[j] == pattern[i]){
				lsp[i] = j + 1;
				j++;
			}
			else
				lsp[i] = 0;
		}
	//	cout << i << " " << lsp[i] << endl;
	}
	return lsp;
}

int main(){

    string s;
    while(true){
        cin >> s;
        if(s == "*")
            break;
        bool printed = false;
        vector<int> v = prepareLPSArray(s);
        int res = s.length() - v[v.size() - 1];
        if(s.length() % res != 0){
            printf("1\n");
            continue;
        }
        int i, tmp = res;
        for(i=2 * res - 1;i<s.length();i+=res){
            //cout << v[i] << endl;
            if(v[i] != tmp){
                printf("1\n");
                printed = true;
                break;
            }
            tmp += res;
        }
        if(!printed)
            printf("%d\n", s.length() / res);
    }
    return 0;
}
