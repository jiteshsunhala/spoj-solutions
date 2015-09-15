#include<cstdio>
#include<iostream>
#include<stack>
#include<string>

using namespace std;

int findMass(string s){
    stack<int> st;
    for(int i=0;i<s.length();i++){
        if(s[i] == '(')
            st.push(-1);
        if(s[i] == 'C')
            st.push(12);
        if(s[i] == 'H')
            st.push(1);
        if(s[i] == 'O')
            st.push(16);
        if(s[i] >= '2' && s[i] <= '9'){
            int n = st.top();
            st.pop();
            st.push(n * (s[i] - '0'));
        }
        if(s[i] == ')'){
            int total = 0;
            while(st.top() != -1){
                total += st.top();
                st.pop();
            }
            st.pop();
            st.push(total);
        }
    }
    int res = 0;
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}

int main(){

    string s;
    cin >> s;
    cout << findMass(s);
    return 0;
}
