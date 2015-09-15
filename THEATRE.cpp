#include<iostream>
#include<vector>
#include<cstdio>
#include<stack>
#define MOD 1000000007

using namespace std;

int main(){
    int n;
    long long int prod = 1;
    vector<long long int> v;
    scanf("%d", &n);
    v.resize(n);
    for(int i=0;i<n;i++)
        scanf("%lld", &v[i]);
    stack<long long int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top() <= v[i])
            st.pop();
        if(!st.empty())
            prod = (prod * st.top()) % MOD;
        st.push(v[i]);
    }
    cout << prod;
}
