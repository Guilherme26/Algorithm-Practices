#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

typedef struct{
	double x,y;
} Point;

Point points[3000];
lli curSize;

lli isCCW(Point p1, Point p2, Point p3){
	return (p2.y - p1.y)*(p3.x - p1.x)-(p2.x - p1.x)*(p3.y - p1.y);
}

void findBottomMost(lli size){
	lli bottomMost = 0;
	for(int i = 1; i < size; ++i)
		if(points[i].y < points[bottomMost].y or (points[i].y == points[bottomMost].y and points[i].x < points[bottomMost].x))
			bottomMost = i;

	Point aux = points[bottomMost];
	points[bottomMost] = points[0];
	points[0] = aux;
}

void GrahamScan(vector<Point> &r, lli size){
	curSize = 3;
	vector<Point> ch(3000);

	ch[0] = points[0];
	ch[1] = points[1];
	ch[2] = points[2];

	for(int i = 3; i < size; ++i){
		while(curSize > 1 and isCCW(ch[curSize-2], ch[curSize-1], points[i]) <= 0){
			r.push_back(ch[curSize-1]);
			curSize -= 1;
		}
		ch[curSize] = points[i];
		curSize++;
	}
}

lli eucDist(Point p1, Point p2){
	return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

bool compare(Point p1, Point p2){
	lli result = isCCW(points[0], p1, p2);
	if(result == 0) return eucDist(points[0], p1) > eucDist(points[0], p2);
	if(result < 0) return false;
	return true;
}

bool isEqual(Point p1, Point p2){
	return (p1.x==p2.x and p1.y==p2.y);
}

int main(){
	lli size;
	while(cin >> size and size){
		Point p;
		for(int i = 0; i < size; ++i)
			scanf("%lf %lf", &points[i].x, &points[i].y);

		lli counter = 0;
		while(size >= 3){
			vector<Point> r;
			findBottomMost(size);
			sort(&points[1], points+size, compare);
			GrahamScan(r, size);

			for(int i = 0; i < r.size(); ++i)
				points[i] = r[i];

			size = r.size();
			counter += 1;
		}

		if(counter%2)
			printf("Take this onion to the lab!\n");
		else
			printf("Do not take this onion to the lab!\n");
	}

	return 0;
}