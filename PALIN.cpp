#include<iostream>
#include<cstdio>
using namespace std;

bool isPalindrome(string s){
    for(int i=0, j=s.length() - 1;i<=j;i++, j--)
        if(s[i] != s[j])
            return false;
    return true;
}

bool allNines(string s){
    for(int i=0;i<s.length();i++)
        if(s[i] != '9')
            return false;
    return true;
}

string findPalinForNines(string s){
    string res = "1";
    for(int i=0;i<s.length() - 1;i++)
        res.append(1, '0');
    res.append(1, '1');
    return res;
}

string addOneToCenter(string s){
    int n, i, cursor, carry;
    cursor = s.length() / 2;
    i = cursor;
    do{
        n = s[i] - 48;
        n++;
        carry = n / 10;
        s[i] = (n % 10) + 48;
        i++;
    }while(i < s.length() && carry);
    for(int i=0, j=s.length() - 1;i<=j;i++, j--)
        s[i] = s[j];
    return s;
}

string prepareString(string s){
    for(int i=0, j=s.length() - 1;i<=j;i++, j--){
        if(s[j] < s[i]){
            s[j] = s[i];
            continue;
        }
        if(s[j] > s[i]){
            s[j] = s[i];
            int n, carry = 1, k=j-1;
            while(carry && k >= 0){
                n = s[k] - 48;
                n++;
                carry = n / 10;
                s[k] = (n % 10) + 48;
                k--;
            }
        }
    }
    return s;
}

string findNext(string s){
    return prepareString(prepareString(s));
}

string findNextPalindrome(string s){
    string res;
    if(isPalindrome(s)){
        if(allNines(s))
            return findPalinForNines(s);
        return addOneToCenter(s);
    }
    return findNext(s);
}

int main(){
    int t;
    string s;
    scanf("%d", &t);
    while(t--){
        cin >> s;
        cout << findNextPalindrome(s) << endl;
    }
    return 0;
}
