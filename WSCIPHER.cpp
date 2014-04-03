#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#include<string>
using namespace std;

string arr1 = "abcdefghi";
string arr2 = "jklmnopqr";
string arr3 = "stuvwxyz_";

string find_text(string msg, string alt){
	string tmp = "";
	for(int i=0;i<msg.length();i++){
		if(alt.find(msg[i]) != -1)
			tmp.append(1, msg[i]);
	}
	return tmp;
}

int main(){
	
	string msg, dec, tmp1, tmp2, tmp3;
	int k1, k2, k3;
	while(true){
		scanf("%d%d%d", &k1, &k2, &k3);
		if(!k1 && !k2 && !k3)
			break;
		cin >> msg;
		tmp1 = find_text(msg, arr1);
//		cout << tmp1 << endl;
		if(tmp1.length() > 0)
			k1 %= tmp1.length();
		
		if(k1 != 0 && tmp1.length() > 0)
			k1 = tmp1.length() - k1;
		
		tmp2 = find_text(msg, arr2);
//		cout << tmp2 << endl;
		if(tmp2.length() > 0)
			k2 %= tmp2.length();
		
		if(k2 != 0 && tmp2.length() > 0)
			k2 = tmp2.length() - k2;
		
		tmp3 = find_text(msg, arr3);
//		cout << tmp3 << endl;
		if(tmp3.length() > 0)
			k3 %= tmp3.length();
		
		if(k3 != 0 && tmp3.length() > 0)
			k3 = tmp3.length() - k3;
		
//		cout << k1 << " " << k2 << " " << k3 << endl;	
		
		string tmp = "";
		for(int i=0;i<msg.length();i++){
			if(arr1.find(msg[i]) != -1){
				tmp.append(1, tmp1[k1]);
				k1 = (k1 + 1) % tmp1.length();
			}
			else if(arr2.find(msg[i]) != -1){
				tmp.append(1, tmp2[k2]);
				k2 = (k2 + 1) % tmp2.length();
			}
			else if(arr3.find(msg[i]) != -1){
				tmp.append(1, tmp3[k3]);
				k3 = (k3 + 1) % tmp3.length();
			}
		}
		
		cout << tmp << "\n";
			
	}
    return 0;
}
