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
#define SIZE 100001
#define square(x) x * x

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

struct Point{
	int x, y, idx;
}points[SIZE];

int orientation(Point p, Point q, Point r){
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
	if (val == 0) return 0;  // colinear
	return (val > 0) ? 1: 2; // clock or counterclock wise
}

int calculateDistance(Point a, Point b){
	int res = square((a.x - b.x)) + square((a.y - b.y));
	return res;
}

bool compare(Point a, Point b){
	int o = orientation(points[0], a, b);
	if(o == 0){
		if(calculateDistance(points[0], a) < calculateDistance(points[0], b))
			return true;
		else if(calculateDistance(points[0], a) == calculateDistance(points[0], b))
			return a.idx > b.idx;
	}
	return (o == 2);
}

void display(int n){
	cout << "display begin" << endl;
	for(int i=0;i<n;i++)
		cout << points[i].x << " " << points[i].y << " " << points[i].idx << endl;
	cout << "display end" << endl;
}

void computeBottomPoint(int n){
	Point bottomAndLeftPoint = points[0];
	int idx = 0;
	for(int i=1;i<n;i++){
		if(points[i].y < bottomAndLeftPoint.y){
			bottomAndLeftPoint = points[i];
			idx = i;
		}
		else if(points[i].y == bottomAndLeftPoint.y && points[i].x < bottomAndLeftPoint.x){
			bottomAndLeftPoint = points[i];
			idx = i;
		}
	}
	swap(points[idx], points[0]);
}

Point getTop(stack<Point> st){
	return st.top();
}

Point getNextTop(stack<Point> &st){
	Point tmp = st.top();
	st.pop();
	Point res = st.top();
	st.push(tmp);
	return res;
}

stack<Point> reverse(stack<Point> st){
	stack<Point> res;
	while(!st.empty()){
		res.push(st.top());
		st.pop();
	}
	return res;
}

void convexHull(int n){
	stack<Point> st, res;
	if(n == 1){
		printf("0.00\n1\n\n");
		return;
	}
	computeBottomPoint(n);
	sort(points + 1, points + n, compare);
	if(n == 2){
		printf("%.2lf\n", (double)(2 * sqrt(calculateDistance(points[0], points[1]))));
		for(int i=0;i<n;i++)
			printf("%d ", points[i].idx);
		printf("\n\n");
		return;
	}
	st.push(points[0]);
	st.push(points[1]);
	for(int i=2;i<n;i++){
		while(st.size() >= 2 && orientation(getNextTop(st), st.top(), points[i]) != 2)
			st.pop();
		st.push(points[i]);
	}
	res = reverse(st);
	vector<int> p;
	Point p0, p1, p2;
	p0 = res.top();
	p.push_back(p0.idx);
	res.pop();
	p1 = res.top();
	p.push_back(p1.idx);
	res.pop();
	double totalDistance = (double)(sqrt(calculateDistance(p0, p1)));
	while(!res.empty()){
		p2 = res.top();
		p.push_back(p2.idx);
		totalDistance += (double)(sqrt(calculateDistance(p1, p2)));
		p1 = p2;
		res.pop();
	}
	totalDistance += (double)(sqrt(calculateDistance(p1, p0)));
	printf("%.2lf\n", totalDistance);
	for(int i=0;i<p.size();i++)
		printf("%d ", p[i]);
	printf("\n\n");
}

int main(){
	
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%d%d", &points[i].x, &points[i].y);
			points[i].idx = i+1;
		}
		convexHull(n);
	}
    return 0;
}
