#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int j, n, i=0;
    vector<int> v;
    while(scanf("%d", &n) != EOF)
        v.push_back(n);
    sort(v.begin(), v.end());
    i=0;
    int a, b;
    for(;i<v.size();){
        a = i;
        j = i + 1;
        while(j < v.size() && v[j] - v[j-1] == 1)
            j++;
        b = j-1;
        printf("for (int i = %d; i <= %d; i++) cout << i << \" \";\n", v[a], v[b]);
        i = j;
    }
    return 0;
}
