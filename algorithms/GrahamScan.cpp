/*
	Guilherme Resende - 2018
	The code below is for finding the Convex Hull of a set of points.
	The algorithm used in this case was Graham Scan that hold a time
	complexity order of O(n*ln n). Graham Scan method on this context
	receives a vetor of points ( convexHull ) and then fills it with the solution.
*/

#include <bits/stdc++.h>

using namespace std;

typedef struct Point{
	int x,y;
	Point(){}
	Point(int _x, int _y){
		x = _x, y = _y;
	}

	bool operator <(const Point &p) const{
		return x < p.x or (x == p.x and y < p.y);
	}

	int operator -(const Point &p) const{
		return (p.x-x)*(p.x-x) + (p.y-y)*(p.y-y);
	}
} Point;

vector<Point> pts;

int isCCW(Point p1, Point p2, Point p3){
	return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
}

void swap(Point &p1, Point &p2){
	Point tmp = p1;
	p1 = p2;
	p2 = tmp;
}

void findLeftMost(vector<Point> &pts){
	int lm = 0;
	for(int i = 1; i < pts.size(); ++i)	
		if(pts[i] < pts[lm]) 
			lm = i;
	swap(pts[0], pts[lm]);
}

bool compare(Point p1, Point p2){
	int R = isCCW(pts[0], p1, p2);
	if(R == 0)
		return pts[0]-p1 > pts[0]-p2;
	return R > 0 ? true : false;
}

void GrahamScan(vector<Point> &convexHull){
	findLeftMost(pts);
	vector<Point> ch(pts.size());
	int chSize = 3;

	sort(pts.begin()+1, pts.end(), compare);

	ch[0] = pts[0], ch[1] = pts[1], ch[2] = pts[2];
	for(int i = 3; i < pts.size(); ++i){
		while(chSize > 2 and isCCW(ch[chSize-2], ch[chSize-1], pts[i]) <= 0)
			chSize--;
		ch[chSize++] = pts[i];
	}

	for(int i = 0; i < chSize; ++i) convexHull.push_back(ch[i]);
}