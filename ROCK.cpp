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

int t, n, cnt1[200], cnt0[200], mat[200][200];
string s;

void input_and_prepare_count(){
	scanf("%d", &n);
	cin >> s;
	fill(cnt1, cnt1+n, 0);
	fill(cnt0, cnt0+n, 0);
	if(s[0] == '0')
		cnt0[0] = 1;
	else
		cnt1[0] = 1;
	for(int i=1;i<s.length();i++){
		if(s[i] == '1'){
			cnt1[i] = cnt1[i-1] + 1;
			cnt0[i] = cnt0[i-1];
		}
		else{
			cnt0[i] = cnt0[i-1] + 1;
			cnt1[i] = cnt1[i-1];
		}
	}
}

void display(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}

int find_cnt(int i, int j, int num){
	if(num == 1){
		if(i == 0)
			return cnt1[j];
		return cnt1[j] - cnt1[i-1];
	}
	if(i == 0)
		return cnt0[j];
	return cnt0[j] - cnt0[i-1];
}

int find_length(){
	
	for(int i=0;i<n;i++)
		mat[i][i] = s[i] - 48;
	
	for(int len=2; len <= n; len++){
		for(int i=0;i<n;i++){
			int j = i + len - 1;
			if(j >= n)
				break;
			mat[i][j] = -1;
			if(find_cnt(i, j, 1) > find_cnt(i, j, 0))
				mat[i][j] = len;
			else{
				for(int k=i;k<j;k++)
					mat[i][j] = max(mat[i][j], max(mat[i][k] + mat[k+1][j], max(mat[i][k], mat[k+1][j])));
			}
		}
	}
	return mat[0][n-1];
}

int main(){
	
	scanf("%d", &t);
	while(t--){
		input_and_prepare_count();
		cout << find_length() << endl;
	}
    return 0;
}
