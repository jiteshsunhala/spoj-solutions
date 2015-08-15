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
#define SIZE 1000000

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

struct point{
	double x, y;
}points[SIZE];

point centroid_polygon(int n){
	double signedArea = 0, X = 0, Y = 0, a;
	for(int i=0;i<n;i++){
		int first = i;
		int second = (i + 1) % n;
		a = points[first].x * points[second].y - points[second].x * points[first].y;
		X += ((points[first].x + points[second].x) * a);
		Y += ((points[first].y + points[second].y) * a);
		signedArea += a;
	}
	signedArea *= 0.5;
	X /= (6 * signedArea);
	Y /= (6 * signedArea);
	point result;
	result.x = X;
	result.y = Y;
	return result;
}

int main(){
	
	int t, n;	
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%lf%lf", &points[i].x, &points[i].y);
		point centroid = centroid_polygon(n);
		printf("%.2lf %.2lf\n", centroid.x, centroid.y);
	}
    return 0;
}
