#include <bits/stdc++.h>

using namespace std;

typedef struct Point{
	int x,y;

	Point(){}
	
	Point(int _x, int _y){
		x = _x, y = _y;
	}

	double operator -(const Point &p)const{
		return fabs(sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y)));
	}
	
	double operator >(const Point &p)const{
		return x>p.x or (x==p.x and y>p.y);
	}
	
	double operator <(const Point &p)const{
		return x<p.x or (x==p.x and y<p.y);
	}
} Point;

bool intersects(Point p1, Point p2, Point p){
	return ((p2.x - p1.x)*(p.y - p1.y) - (p2.y - p1.y)*(p.x - p1.x)) == 0 ?  true : false;
}

bool middle(Point p1, Point p2, Point p3){
	return (p1 < p3 and p3 < p2) or (p2 < p3 and p3 < p1);
}

int main(){
	int n, x, y;
	vector<Point> pts;
	float length;

	scanf("%d", &n);

	for(int i = 0; i < n; ++i){
		scanf("%d %d", &x, &y);
		pts.push_back(Point(x,y));
	}

	double sum = 0.0;
	for(int i = 0; i < n; ++i){
		for(int j = i+1; j < n; ++j){
			bool inter = false;
			for(int k = 0; k < n; ++k){
				if(k == i or k == j)
					continue;
				if(intersects(pts[i], pts[j], pts[k]) and middle(pts[i], pts[j], pts[k])){
					inter = true;
					break;
				}
			}
			if(!inter)
				sum += (pts[i]-pts[j]);
		}
	}

	printf("%d\n", (int)round(sum));

	return 0;
}