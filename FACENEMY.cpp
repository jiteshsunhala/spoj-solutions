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
#define PI 3.14159265

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

float find_angle(float a, float b, float c, float d, float e, float f){
	
	float dx1, dy1, dx2, dy2;
	
	dy1 = d - b;
	dx1 = c - a;
	
	dy2 = f - b;
	dx2 = e - a;
	
	float angle = (acos((dx1 * dx2 + dy1 * dy2) / (sqrt(dx1 * dx1 + dy1 * dy1) * sqrt(dx2 * dx2 + dy2 * dy2))) * 180) / PI;
	angle = min(angle, (float)360.0 - angle);
	
//	cout << angle << endl;
	return angle;
}

int main(){
	
	int t;
	float x1, y1, u1, v1, x2, y2, u2, v2;
	
	scanf("%d", &t);
	while(t--){
		scanf("%f%f%f%f%f%f%f%f", &x1, &y1, &u1, &v1, &x2, &y2, &u2, &v2);
		float angle1 = find_angle(x1, y1, u1, v1, x2, y2);
		float angle2 = find_angle(x2, y2, u2, v2, x1, y1);
		float diff = angle1 - angle2;
		if(diff < 0)
			printf("Hero\n");
		else if(diff > 0)
			printf("Heroine\n");
		else
			printf("0\n");
	}
	
    return 0;
}
