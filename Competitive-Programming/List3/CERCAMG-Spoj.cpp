#include <bits/stdc++.h>

using namespace std;

typedef struct{
	int x,y;
} Point;

Point points[1000];
int curSize;

/* 
 * > 0 if it is Counter Clockwise
 * < 0 if is Clockwise
 * = 0 if colinear
 */
int isCCW(Point p1, Point p2, Point p3){
	return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
}

void findLeftMost(int size){
	int leftMost = 0;
	for(int i = 1; i < size; ++i)
		if(points[i].x < points[leftMost].x or (points[i].x == points[leftMost].x and points[i].y < points[leftMost].y))
			leftMost = i;

	Point aux = points[leftMost];
	points[leftMost] = points[0];
	points[0] = aux;
}

vector<Point> GrahamScan(int size){
	curSize = 2;
	vector<Point> ch(size);

	ch[0] = points[0];
	ch[1] = points[1];

	for(int i = 2; i <= size; ++i){
		while(isCCW(ch[curSize-2], ch[curSize-1], points[i%size]) <= 0)
			curSize -= 1;

		if(i == size)
			break;

		ch[curSize] = points[i%size];
		curSize++;
	}
	return ch;
}

double eucDist(Point p1, Point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

bool compare(Point p1, Point p2){
	int result = isCCW(points[0], p1, p2);
	if(result == 0) return eucDist(points[0], p1) > eucDist(points[0], p2);
	if(result < 0) return false;
	return true;
}

int main(){
	int size, D;
	while(cin >> size >> D){
		Point p;
		for(int i = 0; i < size; ++i){
			scanf("%d %d", &p.x, &p.y);
			points[i] = p;
		}

		findLeftMost(size);
		sort(points+1, points+size, compare);
		vector<Point> ch = GrahamScan(size);

		double sum = 0.0;
		for(int i = 0; i < curSize; ++i){
			sum += sqrt(pow(ch[i].x-ch[(i+1)%curSize].x, 2) + pow(ch[i].y-ch[(i+1)%curSize].y, 2));
		}
		printf("%.2f\n", sum);
	}

	return 0;
}