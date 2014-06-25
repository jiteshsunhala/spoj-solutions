#include<cstdio>
#include<iostream>

typedef long long int LLD;

using namespace std;

int mylog(LLD n){
	int cnt = 0;
	while(n){
		cnt++;
		n >>= 1;
	}
	return cnt-1;
}

LLD mypow(int pow){
	LLD res = 1;
	for(int i=0;i<pow;i++)
		res <<= 1;
	return res;
}

string find(LLD n){
	if(n == 1)
		return "2(0)";
	if(n == 2)
		return "2";
	string res = "";
	int tmp = mylog(n);
	string res1 = find(tmp);
	if(tmp != 1)
		res = "2(" + res1 + ")";
	else
		res = "2";
	LLD diff = n - mypow(tmp);
	if(diff != 0){
		res += "+";
		res += find(diff);
	}
	return res;
}

int main(){
	LLD n, t;
	for(scanf("%lld", &t);t--;){
		scanf("%lld", &n);
		printf("%lld=", n);
		cout << find(n) << endl;
	}
    return 0;
}
