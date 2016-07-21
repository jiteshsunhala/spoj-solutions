#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int w, h, num, result, heights1[21], heights2[21];
	while(true){
		scanf("%d%d", &w, &h);
		if(w == 0 && h == 0)
			break;
		result = 0;
		fill(heights1, heights1 + 21, 0);
		fill(heights2, heights2 + 21, 0);
		for(int i=0;i<w;i++){
			scanf("%d", &num);
			heights1[num]++;
		}
		for(int i=0;i<h;i++){
			scanf("%d", &num);
			heights2[num]++;
		}
		for(int i=1;i<21;i++){
			int common = min(heights1[i], heights2[i]);
			result += (common * i);
			heights1[i] -= common;
			heights2[i] -= common;
			result += (heights1[i] * i) + (heights2[i] * i);
		}
		printf("%d\n", result);
	}
	return 0;
}