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

int main(){
	
	int e, f, s, m, ee, ff, ss, mm, efr, ffr, sfr, mfr;
	while(true){
		scanf("%d %d %d %d %d %d %d %d", &e, &f, &s, &m, &ee, &ff, &ss, &mm);
		if(e == -1)
			break;
		efr = (int) ceil((float)e / (float)ee);
		ffr = (int) ceil((float)f / (float)ff);
		sfr = (int) ceil((float)s / (float)ss);
		mfr = (int) ceil((float)m / (float)mm);
		
//		printf("%d %d %d %d\n", efr, ffr, sfr, mfr);
		
		int maxfr = max(efr, max(ffr, max(sfr, mfr)));
		
		printf("%d %d %d %d\n", (maxfr * ee) - e, (maxfr * ff) - f, (maxfr * ss) - s, (maxfr * mm) - m);
	}
    return 0;
}
