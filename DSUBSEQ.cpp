#include<iostream>
#include<cstdio>
#include<string>
#define SIZE 100005
#define MOD 1000000007

using namespace std;

long long int findDistinctSubsequences(string s){
    long long int total[SIZE], idx[26];
    long long int nextSize;
    fill(idx, idx + 26, -1);
    total[0] = 1;
    idx[s[0] - 65] = 0;
    for(int i=1;i<s.length();i++){
        nextSize = (MOD + 2 * total[i-1] + 1) % MOD;
        if(idx[s[i] - 65] == 0)
            nextSize = (MOD + nextSize - total[0]) % MOD;
        else if(idx[s[i] - 65] != -1)
            nextSize = (MOD + nextSize - (total[idx[s[i] - 65] - 1] + 1)) % MOD;
        total[i] = (nextSize + MOD) % MOD;
        idx[s[i] - 65] = i;
    }
    return total[s.length() - 1] + 1;
}

int main(){

    int t;
    string s;
    scanf("%d", &t);
    while(t--){
        cin >> s;
        printf("%lld\n", findDistinctSubsequences(s));
    }
    return 0;
}
