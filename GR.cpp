#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#define VVI vector< vector<int> >

using namespace std;

VVI init(int n){
	VVI v(n);
	int num = 1;
	for(int i=0;i<n;i++){
		v[i].resize(n);
		for(int j=0;j<n;j++)
			v[i][j] = num++;
	}
	return v;
}

VVI transpose(VVI v){
	VVI result;
	result.resize(v.size());
	for(int i=0;i<result.size();i++)
		result[i].resize(v.size());
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v.size();j++){
			result[j][v.size() - 1 - i] = v[i][j];
		}
	}
	return result;
}

VVI prepareTranspose(int n, VVI v){
	for(int i=0;i<n;i++)
		v = transpose(v);
	return v;
}

void display(VVI v){
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++)
			printf("%d ", v[i][j]);
		printf("\n");
	}
}

int main(){
	VVI v;
	string names[] = {"Atef", "Sameh", "Ameen", "Shafeek"};
	int n, t;
	scanf("%d%d", &n, &t);
	v = init(n);
	printf("%s\n", names[t % 4].c_str());
	display(prepareTranspose(t % 4, v));
	return 0;
}
